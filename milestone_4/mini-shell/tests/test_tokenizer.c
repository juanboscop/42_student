#include "../include/minishell.h"
#include <assert.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

static void check_token(t_token *tok, t_token_type type, const char *val)
{
    assert(tok);
    assert(tok->type == type);
    assert(strcmp(tok->value, val) == 0);
}

static void test_simple_pipe(void)
{
    char *input = strdup("ls | wc");
    t_token *list = tokenize_input(input);
    t_token *tok = list;
    check_token(tok, TOKEN_WORD, "ls");
    tok = tok->next;
    check_token(tok, TOKEN_PIPE, "|");
    tok = tok->next;
    check_token(tok, TOKEN_WORD, "wc");
    assert(tok->next == NULL);
    free_tokens(list);
    free(input);
}

static void test_quotes_and_env(void)
{
    setenv("TESTVAR", "VALUE", 1);
    char *input = strdup("echo \"$TESTVAR is cool\" '$TESTVAR'");
    t_token *list = tokenize_input(input);
    t_token *tok = list;
    check_token(tok, TOKEN_WORD, "echo");
    tok = tok->next;
    check_token(tok, TOKEN_WORD, "VALUE is cool");
    tok = tok->next;
    check_token(tok, TOKEN_WORD, "$TESTVAR");
    assert(tok->next == NULL);
    free_tokens(list);
    free(input);
}

static void test_redirections(void)
{
    char *input = strdup("cat < in > out");
    t_token *list = tokenize_input(input);
    t_token *tok = list;
    check_token(tok, TOKEN_WORD, "cat");
    tok = tok->next;
    check_token(tok, TOKEN_REDIR_IN, "<");
    tok = tok->next;
    check_token(tok, TOKEN_WORD, "in");
    tok = tok->next;
    check_token(tok, TOKEN_REDIR_OUT, ">");
    tok = tok->next;
    check_token(tok, TOKEN_WORD, "out");
    assert(tok->next == NULL);
    free_tokens(list);
    free(input);
}

static void test_append_heredoc(void)
{
    char *input = strdup("cmd >> log << EOF");
    t_token *list = tokenize_input(input);
    t_token *tok = list;
    check_token(tok, TOKEN_WORD, "cmd");
    tok = tok->next;
    check_token(tok, TOKEN_APPEND, ">>");
    tok = tok->next;
    check_token(tok, TOKEN_WORD, "log");
    tok = tok->next;
    check_token(tok, TOKEN_HEREDOC, "<<");
    tok = tok->next;
    check_token(tok, TOKEN_WORD, "EOF");
    assert(tok->next == NULL);
    free_tokens(list);
    free(input);
}

int main(void)
{
    test_simple_pipe();
    test_quotes_and_env();
    test_redirections();
    test_append_heredoc();
    printf("All tokenizer tests passed\n");
    return 0;
}
