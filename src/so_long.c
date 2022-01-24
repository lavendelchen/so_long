/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shaas <shaas@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 01:50:33 by shaas             #+#    #+#             */
/*   Updated: 2022/01/24 17:25:41 by shaas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	t_mlx	all;
	t_map	mapinfo;
	t_img	images;
	
	all.mapinfo = &mapinfo;
	all.images = &images;
	check_for_errors(argc, argv[1]);
	printf("hi?\n");
	get_map(argv[1], all.mapinfo);
	all.mlx_ptr = mlx_init();
	if (all.mlx_ptr == NULL)
		alloc_fail();
	create_images(all.images, all.mlx_ptr);
	create_window(&all);
	mlx_loop(all.mlx_ptr);
}
