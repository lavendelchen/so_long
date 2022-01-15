/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shaas <shaas@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 01:50:33 by shaas             #+#    #+#             */
/*   Updated: 2022/01/15 02:35:12 by shaas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	check_for_errors(argc, argv[1]);
	printf("argc: %d\n", argc);
	printf("map name: %s\n", argv[1]);
	int fd_1 = open("/home/laven/42coding/so_long/src/keys.h", O_RDONLY);
	char *line;
	while ((line = get_next_line(fd_1)) != NULL)
	{
		printf("[%s]\n", line);
		free (line);
	}
	close(fd_1);
	free(line);
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

// to do: parser for map! :) let'S make a function for that