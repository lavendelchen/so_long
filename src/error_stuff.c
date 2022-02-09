/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_stuff.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shaas <shaas@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 19:58:25 by shaas             #+#    #+#             */
/*   Updated: 2022/02/09 00:51:25 by shaas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/* this function looks if we have a system error or if it's just "personal",
meaning it's just not valid for so_long. if it's a system error it prints the
personal message together with the system message, if not, it just prints the
personal one.*/
void	error_exit(char *message, int is_syserror)
{
	char	*msg;

	msg = ft_strjoin("\e[31m\e[3mError\e[0m\n", message);
	if (!is_syserror)
		ft_putendl_fd(msg, 1);
	if (is_syserror)
		perror(msg);
	free(msg);
	exit(EXIT_FAILURE);
}

void	alloc_fail(void)
{
	error_exit("Allocation failure", 1);
}

void	check_for_errors(int argc, char *map)
{
	char	*ber;

	if (argc != 2)
		error_exit("Need one map", 0);
	ber = ft_strrchr(map, '.');
	if (ber == NULL)
		error_exit("Map doesn't end in .ber", 0);
	if (ft_strnstr(ber, ".ber", UINT_MAX) == NULL || ber[4] != '\0')
		error_exit("Map doesn't end in .ber", 0);
}
