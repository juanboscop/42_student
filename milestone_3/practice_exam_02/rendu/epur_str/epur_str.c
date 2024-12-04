/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   epur_str.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpavia <jpavia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 14:31:21 by jpavia            #+#    #+#             */
/*   Updated: 2024/11/28 16:41:44 by jpavia           ###   ########.fr       */
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
	return (i);
}

char	*add_or_remove_spaces(char *str)
{
	static char	mod_str[500];
	int			in_word;
	int			i;
	int			j;

	i = 0;
	j = 0;
	in_word = 0;
	while (str[i] != '\0')
	{
		if(!is_delimiter(str[i]))
		{
			in_word = 1;
			mod_str[j++] = str[i];
		}
		else if (in_word)
		{
			mod_str[j++] = ' ';
			in_word = 0;
		}
		i++;
	}
	if (mod_str[j - 1] == ' ' && j > 0)
		j--;
	mod_str[j] = '\0';
	return (mod_str);
}

int	main(int argc, char	*argv[])
{
	int		i;
	char	*new_string;

	if (argc != 2)
	{
		write(1, "\n", 1);
		return (0);
	}
	new_string = add_or_remove_spaces(argv[1]);
	write(1, new_string, ft_strlen(new_string));
	write(1, "\n", 1);
	return (0);
}