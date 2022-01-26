/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shaas <shaas@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/15 16:44:37 by shaas             #+#    #+#             */
/*   Updated: 2022/01/26 14:29:06 by shaas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	parse_map(char *mapfile, t_map *mapinfo)
{
	int		fd;
	char	*line;
	char	*buffer1;
	char	*buffer2;

	fd = open(mapfile, O_RDONLY);
	if (fd == -1)
		error_exit("open fail", 1);
	buffer1 = ft_calloc(1, sizeof(char) * 1);
	line = ft_calloc(1, sizeof(char) * 1);
	while (line != NULL)
	{
		free(line);
		line = get_next_line(fd);
		buffer2 = ft_strjoin(buffer1, line);
		free(buffer1);
		buffer1 = buffer2;
	}
	close(fd);
	mapinfo->map = ft_split(buffer1, '\n');
	mapinfo->strmap = buffer1;
}

static void	get_itemdata(t_map *mapinfo)
{
	size_t	y;
	size_t	x;
	size_t	i;

	mapinfo->collect = ft_countchr(mapinfo->strmap, 'C');
	mapinfo->exitcount = ft_countchr(mapinfo->strmap, 'E');
	mapinfo->exits = ft_malloc(sizeof (size_t *) * mapinfo->exitcount);
	y = 0;
	x = 0;
	i = 0;
	while (y < mapinfo->collen)
	{
		x = 0;
		while (x < mapinfo->rowlen)
		{
			if (mapinfo->map[y][x] == 'E')
			{
				mapinfo->exits[i] = ft_malloc(sizeof (size_t) * 2);
				mapinfo->exits[i][0] = y;
				mapinfo->exits[i++][1] = x;
			}
			x++;
		}
		y++;
	}
}

static void	get_mapdata(t_map *mapinfo)
{
	size_t	i;

	i = 0;
	mapinfo->rowlen = ft_strlen(mapinfo->map[0]);
	while (mapinfo->map[i] != NULL)
		i++;
	mapinfo->collen = i;
}

void	get_map(char *mapfile, t_map *mapinfo)
{
	parse_map(mapfile, mapinfo); //map & strmap are allocated
	get_mapdata(mapinfo);
	map_errors(mapinfo);
	get_itemdata(mapinfo); //exits will be allocated
}
