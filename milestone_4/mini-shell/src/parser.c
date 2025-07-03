/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bosco <bosco@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 12:59:58 by bosco             #+#    #+#             */
/*   Updated: 2025/05/06 13:19:50 by bosco            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

static void    print_tokens(t_token *tok)
{
    while (tok)
    {
        if (tok->type == TOKEN_WORD)
            ft_printf("WORD:%s\n", tok->value);
        else if (tok->type == TOKEN_PIPE)
            ft_printf("PIPE\n");
        else if (tok->type == TOKEN_REDIR_IN)
            ft_printf("REDIR_IN\n");
        else if (tok->type == TOKEN_REDIR_OUT)
            ft_printf("REDIR_OUT\n");
        else if (tok->type == TOKEN_APPEND)
            ft_printf("APPEND\n");
        else if (tok->type == TOKEN_HEREDOC)
            ft_printf("HEREDOC\n");
        tok = tok->next;
    }
}


void	parse_input(char *prompt)
{
	t_token	*tokens;

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
	print_tokens(tokens);
	free_tokens(tokens);
}

