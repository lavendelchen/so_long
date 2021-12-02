/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shaas <shaas@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 01:50:33 by shaas             #+#    #+#             */
/*   Updated: 2021/12/01 17:05:19 by shaas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <unistd.h>
#include "mlx/mlx.h"
#include <stdio.h>

int	hook_do_something(int key, void *param)
{
	printf("key hook activated: %d\n", key);

	return (0);
}

int	main(void)
{
	void	*mlx_ptr;
	void	*win;
	void	*img;

	int	x;
	int	y;
	mlx_ptr = mlx_init();
	win = mlx_new_window(mlx_ptr, 720, 1440, "hello");
	img = mlx_xpm_file_to_image(mlx_ptr, "./test.c", &x, &y);
	if (!img)
	{
		perror("./test.c");
		exit(1);
	}
	mlx_key_hook(win, hook_do_something, NULL);
	mlx_loop(mlx_ptr);
	mlx_destroy(mlx_ptr);
}
