/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shaas <shaas@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/20 16:44:50 by shaas             #+#    #+#             */
/*   Updated: 2022/01/15 02:28:52 by shaas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static char	*split_remainder_1(char **line,
	char **remainder, char **buffer, int newline)
{
	*line = gnl_substr(*remainder, 0, (newline + 1));
	if (!(*line))
		return (gnl_free_helper(line, remainder, NULL));
	*buffer = gnl_substr(*remainder, (newline + 1), 1);
	if (!(*buffer))
		return (gnl_free_helper(line, remainder, NULL));
	free (*remainder);
	*remainder = gnl_substr(*buffer, 0, 1);
	if (!(*remainder))
		return (gnl_free_helper(line, remainder, buffer));
	free (*buffer);
	return (*line);
}

static char	*split_remainder_2(char **line,
	char **remainder, char **buffer, int newline)
{
	*remainder = gnl_substr(*buffer, 0, (newline + 1));
	if (!(*remainder))
		return (gnl_free_helper(remainder, buffer, line));
	*line = gnl_linejoin(*line, *remainder);
	if (!(*line))
		return (gnl_free_helper(buffer, NULL, NULL));
	free (*remainder);
	*remainder = gnl_substr(*buffer, (newline + 1), 1);
	if (!(*remainder))
		return (gnl_free_helper(remainder, buffer, line));
	free (*buffer);
	return (*line);
}

static char	*reader(int fd, char **remainder, char **buffer, char **line)
{
	int	bytes_read;
	int	newline;

	while (1)
	{
		bytes_read = read(fd, *buffer, 1);
		if (bytes_read < 0)
			return (gnl_free_helper(remainder, buffer, line));
		if (bytes_read == 0)
		{
			gnl_free_helper(buffer, NULL, NULL);
			if (ft_strlen(*line) != 0)
				return (*line);
			return (gnl_free_helper(line, NULL, NULL));
		}
		(*buffer)[bytes_read] = '\0';
		newline = gnl_find_newline(*buffer);
		if (newline != -1)
			return (split_remainder_2(line, remainder, buffer, newline));
		*line = gnl_linejoin(*line, *buffer);
		if (!(*line))
			return (gnl_free_helper(buffer, NULL, NULL));
	}
}

char	*get_next_line(int fd)
{
	static char	*remainder;
	char		*buffer;
	char		*line;
	int			newline;

	newline = gnl_find_newline(remainder);
	if (newline != -1)
		return (split_remainder_1(&line, &remainder, &buffer, newline));
	buffer = (char *)malloc((sizeof(char) * 1) + 1);
	line = (char *)malloc(sizeof(char) * 1);
	if (!buffer || !line || fd < 0)
		return (gnl_free_helper(&remainder, &buffer, &line));
	line[0] = '\0';
	line = gnl_linejoin(line, remainder);
	if (!line)
		return (gnl_free_helper(&buffer, NULL, NULL));
	gnl_free_helper(&remainder, NULL, NULL);
	return (reader(fd, &remainder, &buffer, &line));
}

/*#include <fcntl.h>

int	main(void)
{
	int		fd_1;
	int		fd_2;
	char	*line;

	fd_1 = open("test.txt", O_RDONLY);
	fd_2 = open("get_next_line.c", O_RDONLY);
	while ((line = get_next_line(fd_1)) != NULL)
	{
		printf("[%s]\n", line);
		free (line);
	}
	printf("[%s]", line);
	close(fd_1);
	close(fd_2);
	free(line);
}*/

/*comp get_next_line.c get_next_line_utils.c -D BUFFER_SIZE=3
also literally jus changed every BUFFER_SIZE to 1*/