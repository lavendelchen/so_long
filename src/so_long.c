/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shaas <shaas@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 01:50:33 by shaas             #+#    #+#             */
/*   Updated: 2022/01/16 04:06:28 by shaas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	//char **map;
	
	check_for_errors(argc, argv[1]);
	parse_map(argv[1]);

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
