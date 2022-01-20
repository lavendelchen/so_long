/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shaas <shaas@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 01:50:33 by shaas             #+#    #+#             */
/*   Updated: 2022/01/20 04:01:33 by shaas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	t_map	mapinfo;
	
	check_for_errors(argc, argv[1]);
	get_map(argv[1], &mapinfo);

	void *mlx_ptr = mlx_init();
	if (mlx_ptr == NULL)
		alloc_fail();
	void *win_ptr = mlx_new_window(mlx_ptr, 1000, 1000, "fuck you mlx");
	if (win_ptr == NULL)
		alloc_fail();

	int img_width1;
	int img_height1;
	void *img_ptr1 = mlx_xpm_file_to_image(mlx_ptr, "xpm/02.xpm", &img_width1, &img_height1);
	int i = 0;
	int j = 0;
	while (j * img_height1 < 1000)
	{
		i = 0;
		while (i * img_width1 < 1000)
		{
			mlx_put_image_to_window(mlx_ptr, win_ptr, img_ptr1, img_width1 * i, img_height1 * j);
			i++;
		}
		j++;
	}
	
	int img_width2;
	int img_height2;
	void *img_ptr2 = mlx_xpm_file_to_image(mlx_ptr, "xpm/12.xpm", &img_width2, &img_height2);
	i = 0;
	j = 0;
	while (j * img_height2 < 1000)
	{
		i = 0;
		while (i * img_width2 < 1000)
		{
			if ((j == 0 || j == 3) || (i == 0 || i == 4))
				mlx_put_image_to_window(mlx_ptr, win_ptr, img_ptr2, img_width2 * i, img_height2 * j);
			i++;
		}
		j++;
	}
	mlx_loop(mlx_ptr);
}
