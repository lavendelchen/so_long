/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shaas <shaas@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 18:14:55 by shaas             #+#    #+#             */
/*   Updated: 2022/01/26 19:34:12 by shaas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	key_hook(int keycode, t_mlx *all)
{
	printf("%x\n", keycode);
	if (keycode == KEY_ESCAPE)
		printf("you escaped\n");
	if (keycode == KEY_W)
		printf("you went up ⬆\n");
	if (keycode == KEY_A)
		printf("you went left ⬅\n");
	if (keycode == KEY_S)
		printf("you went down ⬇\n");
	if (keycode == KEY_D)
		printf("you went right ➡\n");
	return (0);
}

int	x_hook(void)
{
	exit(EXIT_SUCCESS);
}