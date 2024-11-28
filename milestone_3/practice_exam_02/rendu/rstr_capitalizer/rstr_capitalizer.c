/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rstr_capitalizer.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bosco <bosco@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 11:29:59 by bosco             #+#    #+#             */
/*   Updated: 2024/11/28 11:48:12 by bosco            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	is_letter(char c)
{
	if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
		return (1);
	return (0);
}

void	capitalize_last(char *str, int last, int i)
{
	if (last != -1 && str[i - 1] == str[last] && is_letter(str[last]))
	{
		if (str[last] >= 'a' && str[last] <= 'z')
			str[last] -= 32;
	}
}

void	print_string(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		write(1, &str[i], 1);
		i++;
	}
}

void	process_string(char *str)
{
	int	i;
	int	last;

	i = 0;
	last = -1;
	while (str[i])
	{
		if (is_letter(str[i]))
		{
			last = i;
			if (str[i] >= 'A' && str[i] <= 'Z')
				str[i] += 32;
		}
		else if (str[i] == ' ' || str[i] == '\t' || str[i + 1] == '\0')
		{
			if (str[i + 1] == '\0')
				capitalize_last(str, last, i + 1);
			else
				capitalize_last(str, last, i);
			last = -1;
		}
		i++;
	}
	capitalize_last(str, last, i);
	print_string(str);
}

int	main(int argc, char **argv)
{
	int	i;

	i = 1;
	if (argc < 2)
	{
		write(1, "\n", 1);
		return (0);
	}
	while (i < argc)
	{
		process_string(argv[i]);
		write(1, "\n", 1);
		i++;
	}
	return (0);
}
