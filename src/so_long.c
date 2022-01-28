/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shaas <shaas@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 01:50:33 by shaas             #+#    #+#             */
/*   Updated: 2022/01/28 15:37:27 by shaas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	t_mlx	all;

	check_for_errors(argc, argv[1]);
	get_map(argv[1], &all.mapinfo);
	all.mlx_ptr = mlx_init();
	if (all.mlx_ptr == NULL)
		error_exit("Failed to initiate mlx", 0);
	create_images(&all.images, all.mlx_ptr);
	create_window(&all, &all.mapinfo);
	mlx_hook(all.win_ptr, 17, 1L << 17, x_hook, NULL);
	mlx_key_hook(all.win_ptr, key_hook, &all); //does it work passing all like that?
	mlx_loop(all.mlx_ptr);
}
