/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shaas <shaas@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 18:14:55 by shaas             #+#    #+#             */
/*   Updated: 2022/01/28 15:37:51 by shaas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	ready_to_leave(t_mlx *all, t_map *mapinfo)
{
	int	i;

	i = 0;
	while (i < mapinfo->exitcount)
	{
		mlx_put_image_to_window(all->mlx_ptr, all->win_ptr, \
		all->images.exit[1], \
		all->mapinfo.exits[i][1] * 64, all->mapinfo.exits[i][0] * 64);
		i++;
	}
	all->player.ready = 1;
}

static void	move_player(t_mlx *all, t_play *player, int y_pos, int x_pos)
{
	mlx_put_image_to_window(all->mlx_ptr, all->win_ptr, \
		all->images.player, x_pos * 64, y_pos * 64);
	if (all->mapinfo.map[player->y][player->x] == '0')
		mlx_put_image_to_window(all->mlx_ptr, all->win_ptr, \
		all->images.space, player->x * 64, player->y * 64);
	if (all->mapinfo.map[player->y][player->x] == 'X')
		mlx_put_image_to_window(all->mlx_ptr, all->win_ptr, \
		all->images.blood, player->x * 64, player->y * 64);
	if (all->mapinfo.map[player->y][player->x] == 'E')
		mlx_put_image_to_window(all->mlx_ptr, all->win_ptr, \
		all->images.exit[0], player->x * 64, player->y * 64);
	player->y = y_pos;
	player->x = x_pos;
	all->moves++;
	if (all->moves == 1)
		printf("[%d move made]\n", all->moves);
	else
		printf("[%d moves made]\n", all->moves);
}

static void	go_in_direction(int y_pos, int x_pos, t_mlx *all)
{
	if (all->mapinfo.map[y_pos][x_pos] == '1')
		return ;
	else if (all->mapinfo.map[y_pos][x_pos] == '0' ||
			 all->mapinfo.map[y_pos][x_pos] == 'X')
		move_player(all, &all->player, y_pos, x_pos);
	else if (all->mapinfo.map[y_pos][x_pos] == 'C')
	{
		move_player(all, &all->player, y_pos, x_pos);
		all->mapinfo.map[y_pos][x_pos] = 'X';
		all->player.collected++;
		if (all->player.collected == all->mapinfo.collect)
			ready_to_leave(all, &all->mapinfo);
	}
	else if (all->mapinfo.map[y_pos][x_pos] == 'E')
	{
		if (all->player.ready == 0)
			return ;
		if (all->player.ready == 1)
		{
			if (all->mapinfo.map[all->player.y][all->player.x] == '0')
				mlx_put_image_to_window(all->mlx_ptr, all->win_ptr, \
				all->images.space, all->player.x * 64, all->player.y * 64);
			if (all->mapinfo.map[all->player.y][all->player.x] == 'X')
				mlx_put_image_to_window(all->mlx_ptr, all->win_ptr, \
				all->images.blood, all->player.x * 64, all->player.y * 64);
			mlx_clear_window(all->mlx_ptr, all->win_ptr);
			mlx_put_image_to_window(all->mlx_ptr, all->win_ptr, \
			all->images.end, ((all->mapinfo.rowlen / 2) * 64) - (2 * 64), \
			(all->mapinfo.collen / 2) * 64);
			printf("Yes, that should work.\n");
			//sleep(5);
			//printf("\e[91mY\e[95mO\e[94mU \e[96mW\e[92mO\e[93mN\e[37m!\e[0m\n");
			exit(EXIT_SUCCESS);
		}
	}
}

int	key_hook(int keycode, t_mlx *all)
{
	if (keycode == KEY_ESCAPE)
		exit(EXIT_SUCCESS);
	else if (keycode == KEY_W)
		go_in_direction(all->player.y - 1, all->player.x, all);
	else if (keycode == KEY_A)
		go_in_direction(all->player.y, all->player.x - 1, all);
	else if (keycode == KEY_S)
		go_in_direction(all->player.y + 1, all->player.x, all);
	else if (keycode == KEY_D)
		go_in_direction(all->player.y, all->player.x + 1, all);
	return (0);
}

int	x_hook(void)
{
	exit(EXIT_SUCCESS);
}
