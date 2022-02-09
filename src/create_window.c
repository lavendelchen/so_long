/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_window.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shaas <shaas@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 16:44:07 by shaas             #+#    #+#             */
/*   Updated: 2022/02/09 00:41:28 by shaas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	place_tile2(int y, int x, t_mlx *all, char tile)
{
	static int	count;

	if (tile == 'C')
	{
		mlx_put_image_to_window(all->mlx_ptr, all->win_ptr, \
		all->img.coll[count], x * 64, y * 64);
		count++;
		if (count == 4)
			count = 0;
	}
	else if (tile == 'P')
	{
		mlx_put_image_to_window(all->mlx_ptr, all->win_ptr, \
		all->img.player, x * 64, y * 64);
		all->map.map[y][x] = '0';
		all->play.y = y;
		all->play.x = x;
		all->play.collected = 0;
		all->play.ready = 0;
		all->won = 0;
		all->moves = 0;
	}
}

static void	place_tile(int y, int x, t_mlx *all)
{
	char	tile;

	tile = all->map.map[y][x];
	if (tile == '1')
		mlx_put_image_to_window(all->mlx_ptr, all->win_ptr, \
		all->img.wall, x * 64, y * 64);
	else if (tile == '0')
		mlx_put_image_to_window(all->mlx_ptr, all->win_ptr, \
		all->img.space, x * 64, y * 64);
	else if (tile == 'E')
		mlx_put_image_to_window(all->mlx_ptr, all->win_ptr, \
		all->img.exit[0], x * 64, y * 64);
	else
		place_tile2(y, x, all, tile);
}

void	create_window(t_mlx *all, t_map *map)
{
	int	y;
	int	x;

	all->win_ptr = mlx_new_window(all->mlx_ptr, \
	map->x_len * 64, map->y_len * 64, "so_long");
	if (all->win_ptr == NULL)
		error_exit("Failed to create window", 0);
	y = 0;
	while (map->map[y] != NULL)
	{
		x = 0;
		while (map->map[y][x] != '\0')
		{
			place_tile(y, x, all);
			x++;
		}
		y++;
	}
}
