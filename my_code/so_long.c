/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shaas <shaas@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 01:50:33 by shaas             #+#    #+#             */
/*   Updated: 2022/01/13 20:54:10 by shaas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	check_for_errors(argc, argv[1]);
	printf("%d\n", argc);
	printf("%s\n", argv[1]);

	void *mlx_ptr = mlx_init();
	if (mlx_ptr == NULL)
	{
		printf("mlx init alloc failed");
		return (0);
	}
	void *win_ptr = mlx_new_window(mlx_ptr, 500, 500, "fuck you mlx");
	if (win_ptr == NULL)
	{
		printf("new win alloc failed");
		return (0);
	}
	mlx_loop(mlx_ptr);
}

//what were we doing?
//whats working: using libft functions :))). what doesnt seem to be working: using mlx stuff. gives segmentation fault as oon as i want to use functions
//error_message.c using libft stuff (append error: to message)

// things to do to initialize the linux mlx: i think just run configure script