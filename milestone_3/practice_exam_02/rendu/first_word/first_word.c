/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   first_word.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bosco <bosco@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 13:51:48 by bosco             #+#    #+#             */
/*   Updated: 2024/11/27 14:15:24 by bosco            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	is_delimiter(char c)
{
	return (c == ' ' || c == '\t');
}

int	main(int argc, char *argv[])
{
	char	f_word[500];
	int		i;
	int		j;

	if (argc != 2)
	{
		write(1, "\n", 1);
		return (0);
	}
	i = 0;
	j = 0;
	while (argv[1][i] != '\0' && is_delimiter(argv[1][i]))
		i++;
	while (argv[1][i] != '\0' && !is_delimiter(argv[1][i]))
	{
		f_word[j] = argv[1][i];
		i++;
		j++;
	}
	write(1, f_word, j);
	write(1, "\n", 1);
	return (0);
}
