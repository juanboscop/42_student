/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpavia <jpavia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 13:02:26 by bosco             #+#    #+#             */
/*   Updated: 2024/11/19 20:23:53 by jpavia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h> 
#include "get_next_line.h"

char	*join_and_free(char *remainder, char *buffer)
{
	char	*temp;

	temp = ft_strjoin(remainder, buffer);
	free(buffer);
	if (!temp)
	{
		free(remainder);
		return (NULL);
	}
	free(remainder);
	return (temp);
}

char	*read_and_append(int fd, char *remainder)
{
	char	*buffer;
	ssize_t	bytes_read;

	buffer = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buffer)
	{
		free(buffer);
		return (NULL);
	}
	bytes_read = read(fd, buffer, BUFFER_SIZE);
	if (bytes_read < 0)
	{
		free(buffer);
		free(remainder);
		return (NULL);
	}
	buffer[bytes_read] = '\0';
	if (bytes_read == 0)
	{
		free(buffer);
		return (remainder);
	}
	return (join_and_free(remainder, buffer));
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
	if (!new_remainder)
	{
		free(remainder);
		return (NULL);
	}
	free(remainder);
	return (new_remainder);
}

char	*get_next_line(int fd)
{
	static char	*txt_remainder;
	char		*line;
	char		*old_remainder;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (!txt_remainder)
		txt_remainder = ft_strdup("");
	while (!ft_strchr(txt_remainder, '\n'))
	{
		old_remainder = txt_remainder;
		txt_remainder = read_and_append(fd, txt_remainder);
		if (!txt_remainder || *txt_remainder == '\0')
		{
			free(txt_remainder);
			txt_remainder = NULL;
			return (NULL);
		}
		if (txt_remainder == old_remainder)
			break ;
	}
	line = extract_line(txt_remainder);
	txt_remainder = update_remainder(txt_remainder);
	return (line);
}

// int main(void)
// {
// 	// const char *filename = "tt.txt"; // Nombre del archivo a leer
// 	int fd = open("tt.txt", O_RDONLY);
// 	if (fd == -1)
// 	{
// 		perror("Error opening file");
// 		return 1;
// 	}

// 	char *line;
// 	while ((line = get_next_line(fd)) != NULL)
// 	{
// 		printf("%s", line);
// 		free(line);
// 	}
// 	return(0);
// }