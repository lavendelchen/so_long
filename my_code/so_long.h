/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shaas <shaas@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 18:10:46 by shaas             #+#    #+#             */
/*   Updated: 2022/01/13 21:56:56 by shaas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdio.h>				// printf()
# include <stdlib.h>			// exit()
# include <errno.h>				// see if there's an error
# include <limits.h>			// UINT_MAX
# include "keys.h"				// keyboard key names
# include "../libft/libft.h"	// libft //
# ifdef __APPLE__
#  include "../mlx_mac/mlx.h"	// mlx on mac //
# endif
# ifdef __linux__
#  include "../mlx_linux/mlx.h"	// mlx on linux //
# endif

void	error_exit(char *message, int is_error);
void	check_for_errors(int argc, char *map);


#endif
