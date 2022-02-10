/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shaas <shaas@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 18:14:55 by shaas             #+#    #+#             */
/*   Updated: 2022/02/09 19:25:30 by shaas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	key_hook(int keycode, t_mlx *all)
{
	if (keycode == KEY_ESCAPE)
		exit_cleanly(all, EXIT_SUCCESS);
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

int	x_hook(t_mlx *all)
{
	exit_cleanly(all, EXIT_SUCCESS);
	return (0);
}
