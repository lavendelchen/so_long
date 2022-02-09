/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shaas <shaas@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 18:10:46 by shaas             #+#    #+#             */
/*   Updated: 2022/02/09 18:24:02 by shaas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <errno.h>
# include <limits.h>
# include <fcntl.h>

# include "../libft/libft.h"

/*If we're on a Mac system*/
# ifdef __APPLE__
#  include "keys_mac.h"
#  include "../mlx_mac/mlx.h"
# endif

/*If we're on a Linux system*/
# ifdef __linux__
#  include "keys_linux.h"
#  include "../mlx_linux/mlx.h"
# endif

typedef struct s_map
{
	char	**map;
	char	*strmap;
	size_t	x_len;
	size_t	y_len;
	int		collect;
	size_t	**exits;
	int		exitcount;
}				t_map;

typedef struct s_img
{
	void	*space;
	void	*wall;
	void	*coll[4];
	void	*exit[2];
	void	*player;
	void	*blood;
	void	*end;
}				t_img;

typedef struct s_play
{
	int	x;
	int	y;
	int	collected;
	int	ready;
}				t_play;

typedef struct s_mlx
{
	void	*mlx_ptr;
	void	*win_ptr;
	int		moves;
	int		won;
	t_map	map;
	t_img	img;
	t_play	play;
}				t_mlx;

char	*gnl_free_helper(char **str1, char **str2, char **str3);
size_t	gnl_strlen(const char *s);
char	*gnl_substr(const char *s, unsigned int start, size_t len);
char	*gnl_linejoin(char *old_line, char *add);
int		gnl_find_newline(char *buffer);
char	*get_next_line(int fd);
void	error_exit(char *message, int is_syserror);
void	free_everything(t_mlx *all);
void	alloc_fail(void);
void	check_for_errors(int argc, char *map);
void	get_map(char *mapfile, t_map *map);
void	map_errors(t_map *map);
void	create_images(t_img *img, void *mlx_ptr);
void	create_window(t_mlx *all, t_map *map);
int		x_hook(void);
int		key_hook(int keycode, t_mlx *all);
void	go_in_direction(int y_pos, int x_pos, t_mlx *all);
void	win(t_mlx *all);

#endif
