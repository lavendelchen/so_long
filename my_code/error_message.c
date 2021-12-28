/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_message.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shaas <shaas@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 19:58:25 by shaas             #+#    #+#             */
/*   Updated: 2021/12/28 17:14:17 by shaas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/* this function looks if we have a system error or if it's just "personal",
meaning it's just not valid for so_long. if it's a system error it prints the
personal message together with the system message, if not, it just prints the
personal one.*/

void	error_exit(char *message, int is_error)
{
	if (!is_error)
		printf("Error: %s", message);
	if (is_error)
		perror(ft_strlcat("Error: ", message, 20));
	exit(EXIT_SUCCESS);
}

int main(void)
{
	char *message = "hello";
	error_exit(message, 1);
}