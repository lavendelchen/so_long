/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shaas <shaas@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/05 14:36:02 by shaas             #+#    #+#             */
/*   Updated: 2022/01/16 15:28:07 by shaas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_count(const char *s, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (s[i] != '\0')
	{
		if (s[i] != c)
		{
			count++;
			while (s[i] != c && s[i] != '\0')
				i++;
			i--;
		}
		i++;
	}
	return (count);
}

void	ft_insert(const char *s, char c, char **split)
{
	int	head;
	int	tail;
	int	count;

	head = 0;
	tail = 0;
	count = 0;
	while (s[head] != '\0')
	{
		if (s[head] != c)
		{
			tail = head;
			while (s[tail] != c && s[tail] != '\0')
				tail++;
			split[count] = (char *)ft_malloc(sizeof(char) * (tail - head + 1));
			ft_strlcpy(split[count], &s[head], tail - head + 1);
			count++;
			head = tail - 1;
		}
		head++;
	}
	split[count] = NULL;
}

char	**ft_split(const char *s, char c)
{
	char	**split;

	if (s == NULL)
		return (NULL);
	split = (char **)ft_malloc(sizeof(char *) * (ft_count(s, c) + 1));
	ft_insert(s, c, split);
	return (split);
}
