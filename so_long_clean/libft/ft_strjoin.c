/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shaas <shaas@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/05 14:34:21 by shaas             #+#    #+#             */
/*   Updated: 2022/01/19 23:48:55 by shaas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*is null protected. null pointer is treated like empty string.*/
char	*ft_strjoin(const char *s1, const char *s2)
{
	int		i;
	size_t	len_1;
	size_t	len_2;
	char	*join;

	i = 0;
	len_1 = ft_strlen(s1);
	len_2 = ft_strlen(s2);
	join = (char *)ft_malloc(len_1 + len_2 + 1);
	while ((s1) && *s1 != '\0')
	{
		join[i] = *s1;
		i++;
		s1++;
	}
	while ((s2) && *s2 != '\0')
	{
		join[i] = *s2;
		i++;
		s2++;
	}
	join[i] = '\0';
	return (join);
}
