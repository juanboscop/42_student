/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_capitalizer.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bosco <bosco@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 14:53:02 by bosco             #+#    #+#             */
/*   Updated: 2024/11/27 15:49:23 by bosco            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	is_delimiter(char c)
{
	return (c == ' ' || c == '\t');
}

char	*capitalize_w(char *str)
{
	int	in_word;
	int	i;

	in_word = 0;
	i = 0;
	while (str[i] != '\0')
	{
		if (is_delimiter(str[i]))
			in_word = 0;
		else if (in_word == 0)
		{
			if (str[i] >= 97 && str[i] <= 122)
				str[i] -= 32;
			in_word = 1;
		}
		else
		{
			if (str[i] >= 65 && str[i] <= 90)
				str[i] += 32;
		}
		i++;
	}
	return (str);
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

int	main(int argc, char *argv[])
{
	int	i;

	if (argc <= 1)
	{
		write(1, "\n", 1);
		return (0);
	}
	i = 1;
	while (i < argc)
	{
		write(1, capitalize_w(argv[i]), ft_strlen(argv[i]));
		write(1, "\n", 1);
		i++;
	}
	return (0);
}
