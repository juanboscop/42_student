/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bosco <bosco@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 13:02:26 by bosco             #+#    #+#             */
/*   Updated: 2024/10/29 19:17:43 by bosco            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h> 
#include "get_next_line.h"

char	*read_and_append(int fd, char *remainder);
char	*extract_line(char *remainder);
char	*update_remainder(char *remainder);

char	*get_next_line(int fd)
{
	static char	*txt_remainder;
	char		*line;

	line = NULL;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (!txt_remainder)
		txt_remainder = ft_strdup("");
	if (!txt_remainder)
		return (NULL);
	while (!ft_strchr(txt_remainder, '\n'))
	{
		txt_remainder = read_and_append(fd, txt_remainder);
		if (!txt_remainder || *txt_remainder == '\0')
		{
			if (txt_remainder)
				free(txt_remainder);
			txt_remainder = NULL;
			return (NULL);
		}
	}
	line = extract_line(txt_remainder);
	txt_remainder = update_remainder(txt_remainder);
	return (line);
}

char	*read_and_append(int fd, char *remainder)
{
	char	buffer[BUFFER_SIZE + 1];
	ssize_t	bytes_read;
	char	*temp;

	bytes_read = read(fd, buffer, BUFFER_SIZE);
	if (bytes_read < 0)
	{
		free(remainder);
		return (NULL);
	}
	buffer[bytes_read] = '\0';
	temp = ft_strjoin(remainder, buffer);
	free(remainder);
	if (!temp)
		return (NULL);
	return (temp);
}

char	*extract_line(char *remainder)
{
	char	*line;
	size_t	line_length;
	char	*newline_pos;

	newline_pos = ft_strchr(remainder, '\n');
	if (newline_pos)
		line_length = newline_pos - remainder + 1;
	else
		line_length = ft_strlen(remainder);
	line = ft_substr(remainder, 0, line_length);
	return (line);
}

char	*update_remainder(char *remainder)
{
	char	*newline_pos;
	char	*new_remainder;

	newline_pos = ft_strchr(remainder, '\n');
	if (!newline_pos)
	{
		free(remainder);
		return (NULL);
	}
	new_remainder = ft_strdup(newline_pos + 1);
	free(remainder);
	if (!new_remainder)
		return (NULL);
	return (new_remainder);
}
