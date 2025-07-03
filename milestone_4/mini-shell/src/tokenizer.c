#include "../include/minishell.h"
#include <ctype.h>

static t_token *new_token(t_token_type type, char *value)
{
    t_token *tok = (t_token *)malloc(sizeof(t_token));
    if (!tok)
        return NULL;
    tok->type = type;
    tok->value = value;
    tok->next = NULL;
    return tok;
}

static void    add_token(t_token **lst, t_token *new)
{
    if (!*lst)
        *lst = new;
    else
    {
        t_token *tmp = *lst;
        while (tmp->next)
            tmp = tmp->next;
        tmp->next = new;
    }
}

static char     *substr_dup(const char *s, size_t start, size_t len)
{
        return (ft_substr(s, start, len));
}

static size_t   add_symbol(t_token **lst, t_token_type type,
                        const char *sym, size_t len)
{
        add_token(lst, new_token(type, substr_dup(sym, 0, len)));
        return (len);
}

static size_t  read_word(const char *line, size_t i, char **out)
{
    size_t start = i;
    while (line[i] && !isspace((unsigned char)line[i]) &&
           line[i] != '|' && line[i] != '<' && line[i] != '>')
        i++;
    *out = substr_dup(line, start, i - start);
    return i;
}

static size_t  read_quoted(const char *line, size_t i, char **out)
{
    char quote = line[i++];
    size_t start = i;
    while (line[i] && line[i] != quote)
        i++;
    *out = substr_dup(line, start, i - start);
    if (line[i] == quote)
        i++;
    return i;
}

static size_t   tokenize_symbol(const char *line, size_t i, t_token **lst)
{
        if (line[i] == '|')
                return (i + add_symbol(lst, TOKEN_PIPE, "|", 1));
        if (line[i] == '<' && line[i + 1] == '<')
                return (i + add_symbol(lst, TOKEN_HEREDOC, "<<", 2));
        if (line[i] == '>' && line[i + 1] == '>')
                return (i + add_symbol(lst, TOKEN_APPEND, ">>", 2));
        if (line[i] == '<')
                return (i + add_symbol(lst, TOKEN_REDIR_IN, "<", 1));
        if (line[i] == '>')
                return (i + add_symbol(lst, TOKEN_REDIR_OUT, ">", 1));
        return (i);
}

static void    free_token_list(t_token *list)
{
    t_token *tmp;
    while (list)
    {
        tmp = list->next;
        free(list->value);
        free(list);
        list = tmp;
    }
}

/* Public functions */

void    free_tokens(t_token *list)
{
    free_token_list(list);
}

t_token *tokenize_input(char *line)
{
    size_t  i = 0;
    t_token *tokens = NULL;
    char    *value;

    while (line && line[i])
    {
        if (isspace((unsigned char)line[i]))
            i++;
        else if (line[i] == '"' || line[i] == '\'')
        {
            i = read_quoted(line, i, &value);
            add_token(&tokens, new_token(TOKEN_WORD, value));
        }
        else if (line[i] == '|' || line[i] == '<' || line[i] == '>')
            i = tokenize_symbol(line, i, &tokens);
        else
        {
            i = read_word(line, i, &value);
            add_token(&tokens, new_token(TOKEN_WORD, value));
        }
    }
    return tokens;
}
