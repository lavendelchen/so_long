/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrnstr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shaas <shaas@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 21:15:01 by shaas             #+#    #+#             */
/*   Updated: 2022/01/13 21:16:25 by shaas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	count;

	i = 0;
	if (*needle == '\0')
		return ((char *)haystack);
	while (*haystack != '\0' && i < len)
	{
		count = 0;
		while (haystack[count] == needle[count] && (i + count) < len)
		{
			count++;
			if (needle[count] == '\0')
				return ((char *)haystack);
		}
		haystack++;
		i++;
	}
	return (NULL);
}
