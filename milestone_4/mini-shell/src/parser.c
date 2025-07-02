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


void	parse_input(char *prompt)
{
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
}
