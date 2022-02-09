/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shaas <shaas@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 18:14:55 by shaas             #+#    #+#             */
/*   Updated: 2022/02/09 17:48:45 by shaas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	ready_to_leave(t_mlx *all, t_map *map)
{
	int	i;

	i = 0;
	while (i < map->exitcount)
	{
		mlx_put_image_to_window(all->mlx_ptr, all->win_ptr, all->img.exit[1], \
		all->map.exits[i][1] * 64, all->map.exits[i][0] * 64);
		i++;
	}
	all->play.ready = 1;
}

static void	move_player(t_mlx *all, t_play *play, int y_pos, int x_pos)
{
	mlx_put_image_to_window(all->mlx_ptr, all->win_ptr, \
		all->img.player, x_pos * 64, y_pos * 64);
	if (all->map.map[play->y][play->x] == '0')
		mlx_put_image_to_window(all->mlx_ptr, all->win_ptr, \
		all->img.space, play->x * 64, play->y * 64);
	if (all->map.map[play->y][play->x] == 'X')
		mlx_put_image_to_window(all->mlx_ptr, all->win_ptr, \
		all->img.blood, play->x * 64, play->y * 64);
	play->y = y_pos;
	play->x = x_pos;
	all->moves++;
	ft_putchar_fd('[', 1);
	ft_putnbr_fd(all->moves, 1);
	if (all->moves == 1)
		ft_putendl_fd(" move made]", 1);
	else
		ft_putendl_fd(" moves made]", 1);
}

static void	go_in_direction(int y_pos, int x_pos, t_mlx *all)
{
	if (all->map.map[y_pos][x_pos] == '1')
		return ;
	else if (all->map.map[y_pos][x_pos] == '0' ||
			 all->map.map[y_pos][x_pos] == 'X')
		move_player(all, &all->play, y_pos, x_pos);
	else if (all->map.map[y_pos][x_pos] == 'C')
	{
		move_player(all, &all->play, y_pos, x_pos);
		all->map.map[y_pos][x_pos] = 'X';
		all->play.collected++;
		if (all->play.collected == all->map.collect)
			ready_to_leave(all, &all->map);
	}
	else if (all->map.map[y_pos][x_pos] == 'E')
	{
		if (all->play.ready == 0)
			return ;
		if (all->play.ready == 1)
			win(all);
	}
}

int	key_hook(int keycode, t_mlx *all)
{
	mlx_do_key_autorepeaton();
	if (keycode == KEY_ESCAPE)
		exit(EXIT_SUCCESS);
	else if (all->won == 1)
		return (0);
	else if (keycode == KEY_W)
		go_in_direction(all->play.y - 1, all->play.x, all);
	else if (keycode == KEY_A)
		go_in_direction(all->play.y, all->play.x - 1, all);
	else if (keycode == KEY_S)
		go_in_direction(all->play.y + 1, all->play.x, all);
	else if (keycode == KEY_D)
		go_in_direction(all->play.y, all->play.x + 1, all);
	return (0);
}

int	x_hook(void)
{
	exit(EXIT_SUCCESS);
}
