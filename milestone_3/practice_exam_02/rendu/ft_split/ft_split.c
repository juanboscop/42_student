/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bosco <bosco@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 19:24:00 by bosco             #+#    #+#             */
/*   Updated: 2024/11/27 20:25:45 by bosco            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stddef.h>

int	is_delimiter(char c)
{
	return (c == ' ' || c == '\t' || c == '\n');
}

char	*allocate_word(char *str, int start, int end)
{
	int		length;
	char	*word;
	int		i;

	i = 0;
	length = end - start;
	word = malloc(sizeof(char) * (length + 1));
	if (!word)
		return (NULL);
	while (i < length)
	{
		word[i] = str[start];
		i++;
		start++;
	}
	word[i] = '\0';
	return (word);
}

int	count_words(char *str)
{
	int	i;
	int	in_word;
	int	count;

	in_word = 0;
	i = 0;
	count = 0;
	while (is_delimiter(str[i]))
		i++;
	while (str[i] != '\0')
	{
		if (!is_delimiter(str[i]) && in_word == 0)
		{
			count++;
			in_word = 1;
		}
		else if (is_delimiter(str[i]))
			in_word = 0;
		i++;
	}
	return (count);
}

char	**ft_split(char *str)
{
	int		i;
	char	**result;
	int		start;
	int		j;

	result = malloc(sizeof(char *) * (count_words(str) + 1));
	if (!result)
		return (NULL);
	i = 0;
	j = 0;
	while (str[i] != '\0')
	{
		if (!is_delimiter(str[i]))
		{
			start = i;
			while (str[i] != '\0' && !is_delimiter(str[i]))
				i++;
			result[j++] = allocate_word(str, start, i);
		}
		else
			i++;
	}
	result[j] = NULL;
	return (result);
}
