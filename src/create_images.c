/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_images.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shaas <shaas@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 15:50:54 by shaas             #+#    #+#             */
/*   Updated: 2022/02/09 19:23:59 by shaas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	*my_xpm_file_to_image(t_mlx *all, char *filename, int *w, int *h)
{
	void	*img_ptr;

	img_ptr = mlx_xpm_file_to_image(all->mlx_ptr, filename, w, h);
	if (img_ptr == NULL)
		error_exit("Failed to create image", 0, all);
	return (img_ptr);
}

void	create_images(t_img *img, t_mlx *all)
{
	int		w;
	int		h;

	img->space = my_xpm_file_to_image(all, "xpm/0_64.xpm", &w, &h);
	img->wall = my_xpm_file_to_image(all, "xpm/1_64.xpm", &w, &h);
	img->coll[0] = my_xpm_file_to_image(all, "xpm/c0_64.xpm", &w, &h);
	img->coll[1] = my_xpm_file_to_image(all, "xpm/c1_64.xpm", &w, &h);
	img->coll[2] = my_xpm_file_to_image(all, "xpm/c2_64.xpm", &w, &h);
	img->coll[3] = my_xpm_file_to_image(all, "xpm/c3_64.xpm", &w, &h);
	img->exit[0] = my_xpm_file_to_image(all, "xpm/e0_64.xpm", &w, &h);
	img->exit[1] = my_xpm_file_to_image(all, "xpm/e1_64.xpm", &w, &h);
	img->player = my_xpm_file_to_image(all, "xpm/p_64.xpm", &w, &h);
	img->blood = my_xpm_file_to_image(all, "xpm/x_64.xpm", &w, &h);
	img->end = my_xpm_file_to_image(all, "xpm/end_256.xpm", &w, &h);
}
