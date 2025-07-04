#include "../include/minishell.h"
#include <assert.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

static void check_arg(t_command *cmd, int index, const char *expect)
{
    assert(cmd->argc > index);
    assert(strcmp(cmd->argv[index], expect) == 0);
}

static void test_simple_command(void)
{
    char *input = strdup("ls -l");
    t_token *toks = tokenize_input(input);
    t_command *cmd = parse_tokens(toks);
    assert(cmd && cmd->next == NULL);
    assert(cmd->argc == 2);
    check_arg(cmd, 0, "ls");
    check_arg(cmd, 1, "-l");
    assert(cmd->infile == NULL && cmd->outfile == NULL);
    free_tokens(toks);
    free_commands(cmd);
    free(input);
}

static void test_pipeline_and_redir(void)
{
    char *input = strdup("echo Hello | grep H > out.txt");
    t_token *toks = tokenize_input(input);
    t_command *cmd = parse_tokens(toks);
    assert(cmd && cmd->next);
    check_arg(cmd, 0, "echo");
    check_arg(cmd, 1, "Hello");
    t_command *cmd2 = cmd->next;
    assert(cmd2->next == NULL);
    check_arg(cmd2, 0, "grep");
    check_arg(cmd2, 1, "H");
    assert(cmd2->outfile && strcmp(cmd2->outfile, "out.txt") == 0);
    assert(cmd2->append == 0);
    free_tokens(toks);
    free_commands(cmd);
    free(input);
}

static void test_redir_in_append(void)
{
    char *input = strdup("cat < in.txt >> out.txt");
    t_token *toks = tokenize_input(input);
    t_command *cmd = parse_tokens(toks);
    assert(cmd && cmd->next == NULL);
    check_arg(cmd, 0, "cat");
    assert(cmd->infile && strcmp(cmd->infile, "in.txt") == 0);
    assert(cmd->outfile && strcmp(cmd->outfile, "out.txt") == 0);
    assert(cmd->append == 1);
    free_tokens(toks);
    free_commands(cmd);
    free(input);
}

int main(void)
{
    test_simple_command();
    test_pipeline_and_redir();
    test_redir_in_append();
    printf("All parser tests passed\n");
    return 0;
}
