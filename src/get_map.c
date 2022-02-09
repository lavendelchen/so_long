/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shaas <shaas@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/15 16:44:37 by shaas             #+#    #+#             */
/*   Updated: 2022/02/09 21:18:14 by shaas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	parse_map(char *mapfile, t_map *map)
{
	int		fd;
	char	*line;
	char	*buffer1;
	char	*buffer2;

	fd = open(mapfile, O_RDONLY);
	if (fd == -1)
		error_exit("open fail", 1, NULL);
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
	map->map = ft_split(buffer1, '\n');
	map->strmap = buffer1;
}

static void	get_itemdata(t_map *map)
{
	size_t	y;
	size_t	x;
	size_t	i;

	map->collect = ft_countchr(map->strmap, 'C');
	map->exitcount = ft_countchr(map->strmap, 'E');
	map->exits = ft_malloc(sizeof (size_t *) * map->exitcount);
	y = 0;
	i = 0;
	while (y < map->y_len)
	{
		x = 0;
		while (x < map->x_len)
		{
			if (map->map[y][x] == 'E')
			{
				map->exits[i] = ft_malloc(sizeof (size_t) * 2);
				map->exits[i][0] = y;
				map->exits[i++][1] = x;
			}
			x++;
		}
		y++;
	}
}

static void	get_mapdata(t_map *map)
{
	size_t	i;

	i = 0;
	map->x_len = ft_strlen(map->map[0]);
	while (map->map[i] != NULL)
		i++;
	map->y_len = i;
}

void	get_map(char *mapfile, t_map *map, t_mlx *all)
{
	parse_map(mapfile, map);
	get_mapdata(map);
	map_errors(map, all);
	get_itemdata(map);
}
