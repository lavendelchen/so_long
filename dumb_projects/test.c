/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shaas <shaas@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 01:50:33 by shaas             #+#    #+#             */
/*   Updated: 2021/12/15 20:16:57 by shaas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <unistd.h>
#ifdef __APPLE__
#include "mlx_mac/mlx.h"
#endif
#ifdef __linux__
#include "mlx_linux/mlx.h"
#endif
#include "my_code/keys.h"
#include <stdio.h>

int	hook_do_something(int key, void *param)
{
	(void)param;
	printf("key hook activated: %d\n", key);
	if (key == KEY_X)
		printf("mr x!!!!!!!!!!\n");

	return (0);
}

typedef struct	s_img_data
{
	void	*img_ptr;
	char	*addr;
	int		bits_per_pixel;
	int		size_line;
	int		endian;
}				t_img_data;

void	my_mlx_pixel_put(t_img_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->size_line + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

void	make_rainbow(t_img_data	*img)
{
	int	x = 0;
	int	y = 0;
	int	i = 1;
	long long rainbow[6] = {0x00FF0018, 0x00FFA52C, 0x00FFFF41, 0x00008018, 0x000000F9, 0x0086007D};

	int	format = 83;
	while (i <= 6)
	{
		while (y < format)
		{
			while (x < 500)
			{
				if ((y + (format * (i - 1))) < 500)
					my_mlx_pixel_put(img, x, (y + (format * (i - 1))), rainbow[i - 1]);
				x++;
			}
			x = 0;
			y++;
		}
		i++;
		y = 0;
	}
}

int	main(void)
{
	void		*mlx_ptr;
	void		*win_ptr;
	t_img_data	img;

	mlx_ptr = mlx_init();
	win_ptr = mlx_new_window(mlx_ptr, 500, 500, "Hello world!");

	//making the image of the rainbow
	img.img_ptr = mlx_new_image(mlx_ptr, 500, 500);
	img.addr = mlx_get_data_addr(img.img_ptr, &img.bits_per_pixel, &img.size_line, &img.endian);
	printf("address: [%s]\nbits per pixel: [%i]\nsize line: [%i]\nendian: [%i]\n", img.addr, img.bits_per_pixel, img.size_line, img.endian);
	make_rainbow(&img);
	mlx_put_image_to_window(mlx_ptr, win_ptr, img.img_ptr, 0, 0);

	mlx_string_put(mlx_ptr, win_ptr, 100, 100, 0x00000000, "what's up homosexuals");

	mlx_key_hook(win_ptr, hook_do_something, NULL);

	mlx_loop(mlx_ptr);
}

//int	main(void)
//{
//	void	*mlx_ptr;
//	void	*win_ptr;
//	void	*img_ptr;
//
//	int	x;
//	int	y;
//	mlx_ptr = mlx_init();
//	win_ptr = mlx_new_window(mlx_ptr, 720, 1440, "hello");
//	img_ptr = mlx_xpm_file_to_image(mlx_ptr, "./test.xpm", &x, &y);
//	if (!img)
//	{
//		perror("./test.c");
//		exit(1);
//	}
//	mlx_key_hook(win, hook_do_something, NULL);
//	mlx_loop(mlx_ptr);
//	mlx_destroy(mlx_ptr);
//}

// comp -Lmlx_mac -lmlx_mac -framework OpenGL -framework AppKit test.c

// comp -l/usr/include -lmlx_linux -O3 -c test.c -o test.o
// comp test.o -Lmlx_linux -lmlx_linux -L/usr/lib -lmlx_linux -lXext -lX11 -lm -lz
