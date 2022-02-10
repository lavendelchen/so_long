/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   go_in_direction.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shaas <shaas@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 18:19:23 by shaas             #+#    #+#             */
/*   Updated: 2022/02/09 18:32:50 by shaas            ###   ########.fr       */
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

static void	put_moves(t_mlx *all, int moves)
{
	char	*moves_str;
	char	*buf;

	mlx_put_image_to_window(all->mlx_ptr, all->win_ptr, all->img.wall, \
	(all->map.x_len - 1) * 64, (all->map.y_len - 1) * 64);
	mlx_put_image_to_window(all->mlx_ptr, all->win_ptr, all->img.wall, \
	(all->map.x_len - 2) * 64, (all->map.y_len - 1) * 64);
	moves_str = ft_itoa(moves);
	buf = ft_strjoin("[", moves_str);
	free(moves_str);
	if (moves == 1)
		moves_str = ft_strjoin(buf, " move made]");
	else
		moves_str = ft_strjoin(buf, " moves made]");
	free(buf);
	ft_putendl_fd(moves_str, 1);
	mlx_string_put(all->mlx_ptr, all->win_ptr, (all->map.x_len - 1.8) * 64, \
	(all->map.y_len - 0.45) * 64, 0x00FFFFFF, moves_str);
	free(moves_str);
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
	put_moves(all, all->moves);
}

void	go_in_direction(int y_pos, int x_pos, t_mlx *all)
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
