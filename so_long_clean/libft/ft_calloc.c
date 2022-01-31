/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shaas <shaas@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/28 17:59:10 by shaas             #+#    #+#             */
/*   Updated: 2022/01/16 15:23:22 by shaas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	char	*ptr;
	size_t	ptr_size;
	size_t	i;

	ptr_size = size * count;
	i = 0;
	ptr = (char *)ft_malloc(ptr_size);
	while (i < ptr_size)
	{
		ptr[i] = 0;
		i++;
	}
	return (ptr);
}
