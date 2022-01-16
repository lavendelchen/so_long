/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shaas <shaas@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/20 16:44:50 by shaas             #+#    #+#             */
/*   Updated: 2022/01/16 04:08:27 by shaas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static char	*split_remainder_1(char **line,
	char **remainder, char **buffer, int newline)
{
	*line = gnl_substr(*remainder, 0, (newline + 1));
	*buffer = gnl_substr(*remainder, (newline + 1), 1);
	free (*remainder);
	*remainder = gnl_substr(*buffer, 0, 1);
	free (*buffer);
	return (*line);
}

static char	*split_remainder_2(char **line,
	char **remainder, char **buffer, int newline)
{
	*remainder = gnl_substr(*buffer, 0, (newline + 1));
	*line = gnl_linejoin(*line, *remainder);
	free (*remainder);
	*remainder = gnl_substr(*buffer, (newline + 1), 1);
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
			error_exit("Failure parsing map", 0);
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
	if (!buffer || !line)
		alloc_fail();
	line[0] = '\0';
	line = gnl_linejoin(line, remainder);
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