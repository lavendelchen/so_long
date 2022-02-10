/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shaas <shaas@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 18:10:46 by shaas             #+#    #+#             */
/*   Updated: 2022/02/10 13:24:35 by shaas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdio.h>				// printf()
# include <unistd.h>			// read/write
# include <stdlib.h>			// exit()
# include <errno.h>				// see if there's an error
# include <limits.h>			// UINT_MAX
# include <fcntl.h>				// O_RDONLY

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
	char	**map;		//map as array of strings, one string as each row
	char	*strmap;	//map as one string, seperated by \n
	size_t	x_len;		//length of each row
	size_t	y_len;		//length of each column
	int		collect;	//amount of items to collect
	size_t	**exits;	//positions of the exits, each on has two integers for x & y. needed to color them green later.
	int		exitcount;	//amount of exits we have
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
	int	x;			//row position
	int	y;			//column position
	int	collected;	//how many items are collected
	int	ready;		//is player ready to exit? 0 for no, 1 for yes.
}				t_play;

typedef struct s_mlx
{
	void	*mlx_ptr;
	void	*win_ptr;
	int		moves;	//moves made by the player
	int		won;	//gets initiated to 0, becomes 1 if game is won
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
void	error_exit(char *message, int is_syserror, t_mlx *all);
void	free_everything(t_mlx *all);
void	alloc_fail(t_mlx *all);
void	check_for_errors(int argc, char *map);
void	get_map(char *mapfile, t_map *map, t_mlx *all);
void	map_errors(t_map *map, t_mlx *all);
void	create_images(t_img *img, t_mlx *all);
void	create_window(t_mlx *all, t_map *map);
int		x_hook(t_mlx *all);
int		key_hook(int keycode, t_mlx *all);
void	go_in_direction(int y_pos, int x_pos, t_mlx *all);
void	exit_cleanly(t_mlx *all, int s_or_f);
void	win(t_mlx *all);

#endif
