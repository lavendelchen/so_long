/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shaas <shaas@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 01:50:33 by shaas             #+#    #+#             */
/*   Updated: 2022/02/09 21:28:35 by shaas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/*to avoid failures when freeing during the exit process*/
static void	initiate_values(t_mlx *all)
{
	all->map.exitcount = 0;
	all->map.exits = NULL;
	all->map.map = NULL;
	all->map.strmap = NULL;
	all->img.space = NULL;
	all->img.wall = NULL;
	all->img.coll[0] = NULL;
	all->img.coll[1] = NULL;
	all->img.coll[2] = NULL;
	all->img.coll[3] = NULL;
	all->img.exit[0] = NULL;
	all->img.exit[1] = NULL;
	all->img.player = NULL;
	all->img.blood = NULL;
	all->img.end = NULL;
	all->win_ptr = NULL;
	all->mlx_ptr = NULL;
}

int	main(int argc, char **argv)
{
	t_mlx	all;

	initiate_values(&all);
	check_for_errors(argc, argv[1]);
	get_map(argv[1], &all.map, &all);
	all.mlx_ptr = mlx_init();
	if (all.mlx_ptr == NULL)
		error_exit("Failed to initiate mlx", 1, &all);
	create_images(&all.img, &all);
	create_window(&all, &all.map);
	mlx_hook(all.win_ptr, 17, 1L << 17, x_hook, &all);
	mlx_hook(all.win_ptr, 2, 1L << 0, key_hook, &all);
	mlx_loop(all.mlx_ptr);
}
