/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   last_word.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bosco <bosco@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 14:17:16 by bosco             #+#    #+#             */
/*   Updated: 2024/11/27 14:50:35 by bosco            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	is_delimiter(char c)
{
	return (c == ' ' || c == '\t');
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i - 1);
}

int	main(int argc, char *argv[])
{
	char	l_word[500];
	int		i;
	int		j;
	int		len;

	if (argc != 2)
	{
		write(1, "\n", 1);
		return (0);
	}
	len = ft_strlen(argv[1]);
	i = 0;
	while (len >= 0 && is_delimiter(argv[1][len]))
		len--;
	j = len;
	while (j >= 0 && !is_delimiter(argv[1][j]))
		j--;
	while (j < len)
	{
		l_word[i++] = argv[1][++j];
	}
	l_word[i] = '\0';
	write(1, l_word, i);
	write(1, "\n", 1);
	return (0);
}
