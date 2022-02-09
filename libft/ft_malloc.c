/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_malloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shaas <shaas@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/16 15:03:22 by shaas             #+#    #+#             */
/*   Updated: 2022/02/09 00:38:30 by shaas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*amazing idea by toni: every malloc call will now just call ft_malloc, which
already handles malloc checks. in case of a failure the program exits.
this means we don't have to check for malloc fails anywhere else now. sad thing
is, this kind of simplification only works if you have an ongoing process that 
is always gonna stop with an exit. so, programs that finish need to have it 
complicated.*/
void	*ft_malloc(size_t size)
{
	char	*ptr;

	ptr = malloc(size);
	if (!ptr)
	{
		ft_putendl_fd("\e[91m\e[3mError\e[0m\nAllocation Failure", 1);
		exit(EXIT_FAILURE);
	}
	return (ptr);
}
