/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_window.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shaas <shaas@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 16:44:07 by shaas             #+#    #+#             */
/*   Updated: 2022/01/24 17:27:14 by shaas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	place_tile(int y, int x, t_mlx *all)
{
	char	tile;

	tile = all->mapinfo->map[y][x];
	printf("[%c]", tile);
}

void	create_window(t_mlx *all)
{
	int	y;
	int	x;

	y = 0;
	all->win_ptr = mlx_new_window(all->mlx_ptr, all->mapinfo->rowlen * 64, all->mapinfo->collen * 64, "so_long");
	while (all->mapinfo->map[y] != NULL)
	{
		x = 0;
		while (all->mapinfo->map[y][x] != '\0')
		{
			place_tile(y, x, all);
			x++;
		}
		printf("\n");
		y++;
	}
}
