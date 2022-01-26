/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_images.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shaas <shaas@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 15:50:54 by shaas             #+#    #+#             */
/*   Updated: 2022/01/26 14:35:12 by shaas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	*my_xpm_file_to_image(void *mlx_ptr, char *filename, int *w, int *h)
{
	void	*img_ptr;

	img_ptr = mlx_xpm_file_to_image(mlx_ptr, filename, w, h);
	if (img_ptr == NULL)
		alloc_fail();
	return (img_ptr);
}

void	create_images(t_img *images, void *mlx_ptr)
{
	int		w;
	int		h;

	images->space = my_xpm_file_to_image(mlx_ptr, "xpm/0_64.xpm", &w, &h);
	images->wall = my_xpm_file_to_image(mlx_ptr, "xpm/1_64.xpm", &w, &h);
	images->coll[0] = my_xpm_file_to_image(mlx_ptr, "xpm/c0_64.xpm", &w, &h);
	images->coll[1] = my_xpm_file_to_image(mlx_ptr, "xpm/c1_64.xpm", &w, &h);
	images->coll[2] = my_xpm_file_to_image(mlx_ptr, "xpm/c2_64.xpm", &w, &h);
	images->coll[3] = my_xpm_file_to_image(mlx_ptr, "xpm/c3_64.xpm", &w, &h);
	images->exit[0] = my_xpm_file_to_image(mlx_ptr, "xpm/e0_64.xpm", &w, &h);
	images->exit[1] = my_xpm_file_to_image(mlx_ptr, "xpm/e1_64.xpm", &w, &h);
	images->player = my_xpm_file_to_image(mlx_ptr, "xpm/p_64.xpm", &w, &h);
	images->dead = my_xpm_file_to_image(mlx_ptr, "xpm/x_64.xpm", &w, &h);
	images->end = my_xpm_file_to_image(mlx_ptr, "xpm/end_256.xpm", &w, &h);
}
