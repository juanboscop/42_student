#include "../include/minishell.h"

static char *ms_strdup(const char *s)
{
    size_t len = ft_strlen(s);
    char *dup = (char *)malloc(len + 1);
    if (!dup)
        return NULL;
    for (size_t i = 0; i < len; i++)
        dup[i] = s[i];
    dup[len] = '\0';
    return dup;
}

static t_command *new_command(void)
{
    t_command *cmd = (t_command *)malloc(sizeof(t_command));
    if (!cmd)
        return NULL;
    cmd->argv = NULL;
    cmd->infile = NULL;
    cmd->outfile = NULL;
    cmd->append = 0;
    cmd->argc = 0;
    cmd->next = NULL;
    return cmd;
}

static int add_arg(t_command *cmd, const char *arg)
{
    char **new_argv = (char **)malloc(sizeof(char *) * (cmd->argc + 2));
    if (!new_argv)
        return 0;
    for (int i = 0; i < cmd->argc; i++)
        new_argv[i] = cmd->argv[i];
    new_argv[cmd->argc] = ms_strdup(arg);
    if (!new_argv[cmd->argc])
    {
        free(new_argv);
        return 0;
    }
    new_argv[cmd->argc + 1] = NULL;
    free(cmd->argv);
    cmd->argv = new_argv;
    cmd->argc++;
    return 1;
}

void free_commands(t_command *cmd)
{
    t_command *tmp;
    int i;

    while (cmd)
    {
        tmp = cmd->next;
        if (cmd->argv)
        {
            for (i = 0; i < cmd->argc; i++)
                free(cmd->argv[i]);
            free(cmd->argv);
        }
        free(cmd->infile);
        free(cmd->outfile);
        free(cmd);
        cmd = tmp;
    }
}

static t_command *parse_tokens_internal(t_token *tok)
{
    t_command *head = new_command();
    t_command *cur = head;

    if (!head)
        return NULL;
    while (tok)
    {
        if (tok->type == TOKEN_WORD)
        {
            if (!add_arg(cur, tok->value))
                return (free_commands(head), NULL);
        }
        else if (tok->type == TOKEN_REDIR_IN || tok->type == TOKEN_HEREDOC)
        {
            tok = tok->next;
            if (!tok || tok->type != TOKEN_WORD)
                return (free_commands(head), NULL);
            free(cur->infile);
            cur->infile = ms_strdup(tok->value);
        }
        else if (tok->type == TOKEN_REDIR_OUT || tok->type == TOKEN_APPEND)
        {
            int append = (tok->type == TOKEN_APPEND);
            tok = tok->next;
            if (!tok || tok->type != TOKEN_WORD)
                return (free_commands(head), NULL);
            free(cur->outfile);
            cur->outfile = ms_strdup(tok->value);
            cur->append = append;
        }
        else if (tok->type == TOKEN_PIPE)
        {
            cur->next = new_command();
            if (!cur->next)
                return (free_commands(head), NULL);
            cur = cur->next;
        }
        tok = tok->next;
    }
    return head;
}

t_command *parse_tokens(t_token *tokens)
{
    if (!tokens)
        return NULL;
    return parse_tokens_internal(tokens);
}

void    print_commands_debug(t_command *cmd)
{
    int i;
    while (cmd)
    {
        ft_printf("CMD:\n");
        for (i = 0; i < cmd->argc; i++)
            ft_printf("  argv[%d]=%s\n", i, cmd->argv[i]);
        if (cmd->infile)
            ft_printf("  infile=%s\n", cmd->infile);
        if (cmd->outfile)
        {
            if (cmd->append)
                ft_printf("  outfile>>%s\n", cmd->outfile);
            else
                ft_printf("  outfile>%s\n", cmd->outfile);
        }
        cmd = cmd->next;
    }
}

void    parse_input(char *prompt)
{
    t_token     *tokens;
    t_command   *cmds;

    if (!prompt)
    {
        ft_printf("exit\n");
        free(prompt);
        exit(1);
    }
    if (ft_strcmp(prompt, "exit") == 0)
    {
        free(prompt);
        exit(1);
    }
    tokens = tokenize_input(prompt);
    cmds = parse_tokens(tokens);
    print_commands_debug(cmds);
    free_tokens(tokens);
    free_commands(cmds);
}
