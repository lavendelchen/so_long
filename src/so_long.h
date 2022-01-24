/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shaas <shaas@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 18:10:46 by shaas             #+#    #+#             */
/*   Updated: 2022/01/24 17:20:19 by shaas            ###   ########.fr       */
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
# include "keys.h"				// keyboard key names
# include "../libft/libft.h"	// libft //
# ifdef __APPLE__
#  include "../mlx_mac/mlx.h"	// mlx on mac //
# endif
# ifdef __linux__
#  include "../mlx_linux/mlx.h"	// mlx on linux //
# endif
typedef struct s_map
{
	char	**map;
	char	*strmap;
	size_t	rowlen;
	size_t	collen;
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
	void	*dead;
	void	*end;
}				t_img;

typedef struct s_mlx
{
	void	*mlx_ptr;
	void	*win_ptr;
	t_map	*mapinfo;
	t_img	*images;
}				t_mlx;

char	*gnl_free_helper(char **str1, char **str2, char **str3);
size_t	gnl_strlen(const char *s);
char	*gnl_substr(const char *s, unsigned int start, size_t len);
char	*gnl_linejoin(char *old_line, char *add);
int		gnl_find_newline(char *buffer);
char	*get_next_line(int fd);		// 💭!!
void	error_exit(char *message, int is_error);
void	alloc_fail(void);
void	check_for_errors(int argc, char *map);
void	get_map(char *mapfile, t_map *mapinfo);
void	map_errors(t_map *mapinfo);
void	create_images(t_img *images, void *mlx_ptr);
void	create_window(t_mlx *all);


#endif
