/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_stuff.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shaas <shaas@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/15 16:44:37 by shaas             #+#    #+#             */
/*   Updated: 2022/01/16 04:14:35 by shaas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	**parse_map(char *mapfile)
{
	int		fd;
	char	*line;
	char	*buffer1;
	char	*buffer2;

	fd = open(mapfile, O_RDONLY);
	if (fd == -1)
		error_exit("open fail", 1);
	buffer1 = ft_calloc(1, sizeof(char) * 1);
	if (!buffer1)
		alloc_fail();
	while ((line = get_next_line(fd)) != NULL)
	{
		buffer2 = ft_strjoin(buffer1, line);
		if (!buffer2)
			alloc_fail();
		printf("[%s]\n", buffer2);
		free(line);
		free(buffer1);
		buffer1 = buffer2;
		printf("here\n");
	}
	close(fd);
	free(line);
	free(buffer1); //buffer1 now allocated!!
	return (NULL);
}

//malloc checks? in every function!!!. every allocated thing needs to be freed before exiting. check for that