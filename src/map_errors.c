/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_errors.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shaas <shaas@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 23:31:39 by shaas             #+#    #+#             */
/*   Updated: 2022/01/20 02:13:14 by shaas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	invalid_chars(char *map)
{
	char	*tester;

	tester = ft_strtrim(map, "01CEP\n");
	if (tester[0] != '\0')
	{
		error_exit("Map contains invalid character. \
Valid characters are [01CEP]\n", 0);
	}
	free(tester);
}

static void	item_numbers(char *map)
{
	if (!ft_strchr(map, 'E'))
		error_exit("Need at least one exit\n", 0);
	if (!ft_strchr(map, 'C'))
		error_exit("Need at least one collectible\n", 0);
	if (!ft_strchr(map, 'P'))
		error_exit("Need a starting position\n", 0);
	if (ft_strchr(map, 'P') != ft_strrchr(map, 'P'))
		error_exit("Only one starting position, please\n", 0);
}

/*btw! your map can have as many empty lines before, after and in between
the map as you want. ft_split gets rid of them. maybe i should change this?*/
static void	is_rectangular(t_map *mapinfo)
{
	size_t	i;

	i = 1;
	while (mapinfo->map[i] != NULL)
	{
		if (mapinfo->rowlen != ft_strlen(mapinfo->map[i]))
			error_exit("Map must be rectangular\n", 0);
		i++;
	}
}

static void	surrounded_by_walls(t_map *mapinfo)
{
	size_t	i;
	char	*msg;

	i = 0;
	msg = "Map must be completely surrounded by walls\n";
	while (i < mapinfo->rowlen)
	{
		if (mapinfo->map[0][i] != '1' ||
			mapinfo->map[mapinfo->collen - 1][i] != '1')
			error_exit(msg, 0);
		i++;
	}
	i = 0;
	while (i < mapinfo->collen)
	{
		if (mapinfo->map[i][0] != '1' ||
			mapinfo->map[i][mapinfo->rowlen - 1] != '1')
			error_exit(msg, 0);
		i++;
	}
}

/*spointer stands for single pointer, dpointer for double pointer.
to check some criteria of a valid map, the huge string is easier to check
than the string array.*/
void	map_errors(t_map *mapinfo)
{
	invalid_chars(mapinfo->strmap);
	item_numbers(mapinfo->strmap);
	is_rectangular(mapinfo);
	surrounded_by_walls(mapinfo);
	printf("\e[92mhi?\e[0m\n");
}
