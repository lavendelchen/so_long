/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shaas <shaas@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 01:50:33 by shaas             #+#    #+#             */
/*   Updated: 2021/12/14 21:10:23 by shaas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	if (argc != 2)
		error_exit("Need one map", 1);
	printf("%d\n", argc);
	printf("%s", argv[1]);
}

// comp -Lmlx -lmlx -framework OpenGL -framework AppKit test.c

//what were we doing?
//makefiles: trying to compile from another makefile. also just trying to cmpile into different directories
//error_message.c using libft stuff (append error: to message)
