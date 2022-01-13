/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_stuff.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shaas <shaas@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 19:58:25 by shaas             #+#    #+#             */
/*   Updated: 2022/01/13 21:11:39 by shaas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_for_errors(int argc, char *map)
{
	char	*ber;
	
	if (argc != 2)
		error_exit("Need one map\n", 0);
	ber = ft_strnstr(map, ".ber", maplen);
	if (ber == NULL || ber[4] != '\0')
	{
		
	}

}

/* this function looks if we have a system error or if it's just "personal",
meaning it's just not valid for so_long. if it's a system error it prints the
personal message together with the system message, if not, it just prints the
personal one.*/
void	error_exit(char *message, int is_syserror)
{
	char	*msg;

	if (!is_syserror)
		printf("Error\n%s", message); //should we add a backslash? not sure, don't get the error stuff anyway
	if (is_syserror)
	{
		msg = ft_strjoin("Error\n", message);
		perror(msg);
		free(msg);
	}
	exit(EXIT_SUCCESS);
}
