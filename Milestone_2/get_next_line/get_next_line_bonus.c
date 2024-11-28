/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpavia <jpavia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 14:39:35 by jpavia            #+#    #+#             */
/*   Updated: 2024/11/19 20:25:40 by jpavia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

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
		return (free(remainder), NULL);
	bytes_read = read(fd, buffer, BUFFER_SIZE);
	if (bytes_read <= 0)
	{
		free(buffer);
		if (bytes_read == 0)
			return (remainder);
		free(remainder);
		return (NULL);
	}
	buffer[bytes_read] = '\0';
	return (join_and_free(remainder, buffer));
}

char	*extract_line(char *remainder)
{
	char	*newline_pos;
	size_t	line_length;
	char	*line;

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
	return (new_remainder);
}

char	*get_next_line(int fd)
{
	static char	*fd_remainders[OPEN_MAX];
	char		*line;
	char		*old_remainder;

	if (fd < 0 || BUFFER_SIZE <= 0 || fd >= OPEN_MAX)
		return (NULL);
	if (!fd_remainders[fd])
		fd_remainders[fd] = ft_strdup("");
	while (!ft_strchr(fd_remainders[fd], '\n'))
	{
		old_remainder = fd_remainders[fd];
		fd_remainders[fd] = read_and_append(fd, fd_remainders[fd]);
		if (!fd_remainders[fd] || *fd_remainders[fd] == '\0')
		{
			free(fd_remainders[fd]);
			fd_remainders[fd] = NULL;
			return (NULL);
		}
		if (fd_remainders[fd] == old_remainder)
			break ;
	}
	line = extract_line(fd_remainders[fd]);
	fd_remainders[fd] = update_remainder(fd_remainders[fd]);
	return (line);
}

// int main(void)
// {
//     int fd1, fd2, fd3, fd4;
//     char *line1, *line2, *line3, *line4;

//     // Open four test files
//     fd1 = open("test1.txt", O_RDONLY);
//     fd2 = open("test2.txt", O_RDONLY);
//     fd3 = open("test3.txt", O_RDONLY);
//     fd4 = open("test4.txt", O_RDONLY);

//     if (fd1 < 0 || fd2 < 0 || fd3 < 0 || fd4 < 0)
//     {
//         perror("Error opening file");
//         return (1);
//     }

//     // Read lines alternately from all four files
//     line1 = get_next_line(fd1);
//     line2 = get_next_line(fd2);
//     line3 = get_next_line(fd3);
//     line4 = get_next_line(fd4);
//     while (line1 || line2 || line3 || line4)
//     {
//         if (line1)
//         {
//             printf("File 1: %s", line1);
//             free(line1);
//             line1 = get_next_line(fd1);
//         }
//         if (line2)
//         {
//             printf("File 2: %s", line2);
//             free(line2);
//             line2 = get_next_line(fd2);
//         }
//         if (line3)
//         {
//             printf("File 3: %s", line3);
//             free(line3);
//             line3 = get_next_line(fd3);
//         }
//         if (line4)
//         {
//             printf("File 4: %s", line4);
//             free(line4);
//             line4 = get_next_line(fd4);
//         }
//     }

//     // Close file descriptors
//     close(fd1);
//     close(fd2);
//     close(fd3);
//     close(fd4);

//     return (0);
// }
