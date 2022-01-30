/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_a_bi_uebergang_with_mlx.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shaas <shaas@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 01:50:33 by shaas             #+#    #+#             */
/*   Updated: 2022/01/30 17:18:39 by shaas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <stdio.h>				// printf()
# include <unistd.h>			// read/write
# include <stdlib.h>			// exit()
# include <errno.h>				// see if there's an error
# include <limits.h>			// UINT_MAX
# include <fcntl.h>				// O_RDONLY
# include "../libft/libft.h"	// libft //
# ifdef __APPLE__
#  include "../mlx_mac/mlx.h"	// mlx on mac //
# endif
# ifdef __linux__
#  include "../mlx_linux/mlx.h"	// mlx on linux //
# endif

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

int	main(void)
{
	void		*mlx_ptr;
	void		*win_ptr;
	t_img_data	img;

	printf("here");
	mlx_ptr = mlx_init();
	win_ptr = mlx_new_window(mlx_ptr, 500, 500, "Love is Love");

	img.img_ptr = mlx_new_image(mlx_ptr, 500, 500);
	img.addr = mlx_get_data_addr(img.img_ptr, &img.bits_per_pixel, &img.size_line, &img.endian);

	int	x = 0;
	int	y = 0;
	long long bi_colours[3] = {0x00D00070, 0x008C4799, 0x000032A0};

	while (bi_colours[0] != 0x00D000FF)
	{
		while (x < 500)
		{
			if (y < 500)
				my_mlx_pixel_put(&img, x, y, bi_colours[0]);
			x++;
		}
		x = 0;
		y++;
		if (y % 2 == 0)
			bi_colours[0]++;
	}
	while (bi_colours[0] != 0x000000FF)
	{
		while (x < 500)
		{
			if (y < 500)
				my_mlx_pixel_put(&img, x, y, bi_colours[0]);
			x++;
		}
		x = 0;
		y++;
		if (y % 2 == 0)
			bi_colours[0] -= 0x0005000;
	}
	printf("y = [%i]\n", y);


	printf("address: [%s]\nbits per pixel: [%i]\nsize line: [%i]\nendian: [%i]\n", img.addr, img.bits_per_pixel, img.size_line, img.endian);
	mlx_put_image_to_window(mlx_ptr, win_ptr, img.img_ptr, 0, 0);

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
//	img_ptr = mlx_xpm_file_to_image(mlx_ptr, "./test.c", &x, &y);
//	if (!img)
//	{
//		perror("./test.c");
//		exit(1);
//	}
//	mlx_key_hook(win, hook_do_something, NULL);
//	mlx_loop(mlx_ptr);
//	mlx_destroy(mlx_ptr);
//}

// comp -Lmlx -lmlx -framework OpenGL -framework AppKit test.c
