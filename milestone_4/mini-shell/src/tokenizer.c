#include "../include/minishell.h"
#include <ctype.h>
#include <stddef.h>

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

/* Simple strdup replacement */
static char     *ms_strdup(const char *s)
{
    char    *dup;
    size_t  i;

    dup = (char *)malloc(ft_strlen(s) + 1);
    if (!dup)
        return (NULL);
    i = 0;
    while (s[i])
    {
        dup[i] = s[i];
        i++;
    }
    dup[i] = '\0';
    return (dup);
}

/* Join s1 and s2, free s1 */
static char     *ms_strjoin_free(char *s1, const char *s2)
{
    size_t  len1;
    size_t  len2;
    char    *new;
    size_t  i;

    len1 = s1 ? ft_strlen(s1) : 0;
    len2 = ft_strlen(s2);
    new = (char *)malloc(len1 + len2 + 1);
    if (!new)
    {
        free(s1);
        return (NULL);
    }
    i = 0;
    while (s1 && i < len1)
    {
        new[i] = s1[i];
        i++;
    }
    for (size_t j = 0; j < len2; j++)
        new[i++] = s2[j];
    new[i] = '\0';
    free(s1);
    return (new);
}

static char     *expand_env_segment(const char *segment)
{
    char    *res;
    size_t  i;

    res = ms_strdup("");
    if (!res)
        return (NULL);
    i = 0;
    while (segment[i])
    {
        if (segment[i] == '$')
        {
            size_t  start;
            char    *name;
            char    *val;
            char    *tmp;

            i++;
            start = i;
            while (segment[i] && (isalnum((unsigned char)segment[i]) || segment[i] == '_'))
                i++;
            if (start == i)
            {
                res = ms_strjoin_free(res, "$");
                continue;
            }
            name = substr_dup(segment, start, i - start);
            val = getenv(name);
            free(name);
            if (!val)
                val = "";
            tmp = ms_strjoin_free(res, val);
            res = tmp;
        }
        else
        {
            char ch[2];

            ch[0] = segment[i];
            ch[1] = '\0';
            res = ms_strjoin_free(res, ch);
            i++;
        }
    }
    return (res);
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
    char *tmp = substr_dup(line, start, i - start);
    *out = expand_env_segment(tmp);
    free(tmp);
    return i;
}

static size_t  read_quoted(const char *line, size_t i, char **out)
{
    char quote = line[i++];
    size_t start = i;
    while (line[i] && line[i] != quote)
        i++;
    char *tmp = substr_dup(line, start, i - start);
    if (quote == '"')
        *out = expand_env_segment(tmp);
    else
        *out = ms_strdup(tmp);
    free(tmp);
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
