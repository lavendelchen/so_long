/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrnstr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shaas <shaas@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 21:15:01 by shaas             #+#    #+#             */
/*   Updated: 2022/01/13 21:45:32 by shaas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//not finished!! dont know if ill ever finish it lol

char	*ft_strrnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	count;
	size_t	haystack_len;

	i = 0;
	if (*needle == '\0')
		return ((char *)haystack);
	haystack_len = ft_strlen(haystack);
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
