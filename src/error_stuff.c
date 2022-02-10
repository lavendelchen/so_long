/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_stuff.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shaas <shaas@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 19:58:25 by shaas             #+#    #+#             */
/*   Updated: 2022/02/10 23:22:37 by shaas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	destroy_mlx(void *mlx_ptr, void *win_ptr, t_img *img)
{
	if (img->space)
		mlx_destroy_image(mlx_ptr, img->space);
	if (img->wall)
		mlx_destroy_image(mlx_ptr, img->wall);
	if (img->coll[0])
		mlx_destroy_image(mlx_ptr, img->coll[0]);
	if (img->coll[1])
		mlx_destroy_image(mlx_ptr, img->coll[1]);
	if (img->coll[2])
		mlx_destroy_image(mlx_ptr, img->coll[2]);
	if (img->coll[3])
		mlx_destroy_image(mlx_ptr, img->coll[3]);
	if (img->exit[0])
		mlx_destroy_image(mlx_ptr, img->exit[0]);
	if (img->exit[1])
		mlx_destroy_image(mlx_ptr, img->exit[1]);
	if (img->player)
		mlx_destroy_image(mlx_ptr, img->player);
	if (img->blood)
		mlx_destroy_image(mlx_ptr, img->blood);
	if (img->end)
		mlx_destroy_image(mlx_ptr, img->end);
	if (win_ptr)
		mlx_destroy_window(mlx_ptr, win_ptr);
}

void	exit_cleanly(t_mlx *all, int s_or_f)
{
	int	i;

	if (all == NULL)
		exit(s_or_f);
	i = 0;
	while (i < all->map.exitcount)
	{
		free(all->map.exits[i]);
		i++;
	}
	free(all->map.exits);
	if (all->map.map != NULL)
	{
		i = 0;
		while (all->map.map[i] != NULL)
		{
			free(all->map.map[i]);
			i++;
		}
	}
	free(all->map.map);
	free(all->map.strmap);
	if (all->mlx_ptr)
		destroy_mlx(all->mlx_ptr, all->win_ptr, &all->img);
	exit(s_or_f);
}

/* this function looks if we have a system error or if it's just "personal",
meaning it's just not valid for so_long. if it's a system error it prints the
personal message together with the system message, if not, it just prints the
personal one.*/
void	error_exit(char *message, int is_syserror, t_mlx *all)
{
	char	*msg;

	msg = ft_strjoin("\e[31m\e[3mError\e[0m\n", message);
	if (!is_syserror)
		ft_putendl_fd(msg, 1);
	if (is_syserror)
		perror(msg);
	free(msg);
	exit_cleanly(all, EXIT_FAILURE);
}

void	alloc_fail(t_mlx *all)
{
	error_exit("Allocation failure", 1, all);
}

void	check_for_errors(int argc, char *map)
{
	char	*ber;

	if (argc != 2)
		error_exit("Need one map", 0, NULL);
	ber = ft_strrchr(map, '.');
	if (ber == NULL)
		error_exit("Map doesn't end in .ber", 0, NULL);
	if (ft_strnstr(ber, ".ber", UINT_MAX) == NULL || ber[4] != '\0')
		error_exit("Map doesn't end in .ber", 0, NULL);
}
