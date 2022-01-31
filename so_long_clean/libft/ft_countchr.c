/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_countchr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shaas <shaas@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/22 10:14:39 by shaas             #+#    #+#             */
/*   Updated: 2022/01/30 05:19:29 by shaas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*not NULL protected! just like most of the str/mem libft functions :/ */
int	ft_countchr(const char *s, int c)
{
	int	i;
	int	num;

	i = 0;
	num = 0;
	while (s[i] != '\0')
	{
		if (s[i] == c)
			num++;
		i++;
	}
	return (num);
}
