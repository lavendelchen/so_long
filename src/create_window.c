/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_window.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shaas <shaas@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 16:44:07 by shaas             #+#    #+#             */
/*   Updated: 2022/01/27 04:59:25 by shaas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	place_tile2(int y, int x, t_mlx *all, char tile)
{
	static int	count;

	if (tile == 'C')
	{
		mlx_put_image_to_window(all->mlx_ptr, all->win_ptr, \
		all->images.coll[count], x * 64, y * 64);
		count++;
		if (count == 4)
			count = 0;
	}
	else if (tile == 'P')
	{
		mlx_put_image_to_window(all->mlx_ptr, all->win_ptr, \
		all->images.player, x * 64, y * 64);
		all->mapinfo.map[y][x] = '0';
		all->player.y = y;
		all->player.x = x;
		all->player.collected = 0;
		all->player.ready = 0;
		all->moves = 0;
	}
}

static void	place_tile(int y, int x, t_mlx *all)
{
	char	tile;

	tile = all->mapinfo.map[y][x];
	if (tile == '1')
		mlx_put_image_to_window(all->mlx_ptr, all->win_ptr, \
		all->images.wall, x * 64, y * 64);
	else if (tile == '0')
		mlx_put_image_to_window(all->mlx_ptr, all->win_ptr, \
		all->images.space, x * 64, y * 64);
	else if (tile == 'E')
		mlx_put_image_to_window(all->mlx_ptr, all->win_ptr, \
		all->images.exit[0], x * 64, y * 64);
	else
		place_tile2(y, x, all, tile);
}

void	create_window(t_mlx *all, t_map *mapinfo)
{
	int	y;
	int	x;

	all->win_ptr = mlx_new_window(all->mlx_ptr, \
	mapinfo->rowlen * 64, mapinfo->collen * 64, "so_long");
	if (all->win_ptr == NULL)
		error_exit("Failed to create window", 0);
	y = 0;
	while (mapinfo->map[y] != NULL)
	{
		x = 0;
		while (mapinfo->map[y][x] != '\0')
		{
			place_tile(y, x, all);
			x++;
		}
		y++;
	}
}
