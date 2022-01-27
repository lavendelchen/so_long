/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_stuff.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shaas <shaas@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 19:58:25 by shaas             #+#    #+#             */
/*   Updated: 2022/01/26 20:34:49 by shaas            ###   ########.fr       */
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

	if (!is_syserror)
		printf("\e[91m\e[3mError\e[0m\n%s", message);
	if (is_syserror)
	{
		msg = ft_strjoin("\e[31m\e[3mError\e[0m\n", message);
		perror(msg);
		free(msg);
	}
	exit(EXIT_FAILURE);
}

void	alloc_fail(void)
{
	error_exit("Allocation failure\n", 0);
}

void	check_for_errors(int argc, char *map)
{
	char	*ber;

	if (argc != 2)
		error_exit("Need one map\n", 1);
	ber = ft_strnstr(map, ".ber", UINT_MAX);
	if (ber == NULL || ber[4] != '\0') // excludes stuff like affe.bergsteiger.ber but we ain't got time for funky shit like that
		error_exit("Map doesn't end in .ber\n", 0);
}
