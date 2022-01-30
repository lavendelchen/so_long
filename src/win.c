/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   win.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shaas <shaas@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/29 19:36:15 by shaas             #+#    #+#             */
/*   Updated: 2022/01/30 05:18:07 by shaas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	win(t_mlx *all)
{
	int	x_text;
	int	y_text;

	if (all->map.map[all->play.y][all->play.x] == '0')
		mlx_put_image_to_window(all->mlx_ptr, all->win_ptr, \
		all->img.space, all->play.x * 64, all->play.y * 64);
	else if (all->map.map[all->play.y][all->play.x] == 'X')
		mlx_put_image_to_window(all->mlx_ptr, all->win_ptr, \
		all->img.blood, all->play.x * 64, all->play.y * 64);
	mlx_clear_window(all->mlx_ptr, all->win_ptr);
	if (all->map.x_len % 2 == 0)
		x_text = ((all->map.x_len / 2) * 64) - (2 * 64);
	else
		x_text = ((all->map.x_len / 2) * 64) - (1.5 * 64);
	if (all->map.y_len % 2 == 0)
		y_text = ((all->map.y_len / 2) * 64) - 10;
	else
		y_text = ((all->map.y_len / 2) * 64) - 10 + (0.5 * 64);
	mlx_put_image_to_window(all->mlx_ptr, all->win_ptr, \
	all->img.end, x_text, y_text);
	//printf("Yes, that should work.\n"); still not sure if this or "you won"
	printf("\e[91mY\e[95mO\e[94mU \e[96mW\e[92mO\e[93mN\e[37m!\e[0m\n");
	all->won = 1;
}
