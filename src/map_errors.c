/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_errors.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shaas <shaas@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 23:31:39 by shaas             #+#    #+#             */
/*   Updated: 2022/02/09 19:22:22 by shaas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	invalid_chars(char *map, t_mlx *all)
{
	char	*tester;

	tester = ft_strtrim(map, "01CEP\n");
	if (tester[0] != '\0')
	{
		error_exit("Map contains invalid character. \
Valid characters are [01CEP]", 0, all);
	}
	free(tester);
}

static void	item_numbers(char *map, t_mlx *all)
{
	if (!ft_strchr(map, 'E'))
		error_exit("Need at least one exit", 0, all);
	if (!ft_strchr(map, 'C'))
		error_exit("Need at least one collectible", 0, all);
	if (!ft_strchr(map, 'P'))
		error_exit("Need a starting position", 0, all);
	if (ft_strchr(map, 'P') != ft_strrchr(map, 'P'))
		error_exit("Only one starting position, please", 0, all);
}

/*btw! your map can have as many empty lines before, after and in between
the map as you want. ft_split gets rid of them. maybe i should change this?*/
static void	is_rectangular(t_map *map, t_mlx *all)
{
	size_t	i;

	i = 1;
	while (map->map[i] != NULL)
	{
		if (map->x_len != ft_strlen(map->map[i]))
			error_exit("Map must be rectangular", 0, all);
		i++;
	}
}

static void	surrounded_by_walls(t_map *map, t_mlx *all)
{
	size_t	i;
	char	*msg;

	i = 0;
	msg = "Map must be completely surrounded by walls";
	while (i < map->x_len)
	{
		if (map->map[0][i] != '1' ||
			map->map[map->y_len - 1][i] != '1')
			error_exit(msg, 0, all);
		i++;
	}
	i = 0;
	while (i < map->y_len)
	{
		if (map->map[i][0] != '1' ||
			map->map[i][map->x_len - 1] != '1')
			error_exit(msg, 0, all);
		i++;
	}
}

/*spointer stands for single pointer, dpointer for double pointer.
to check some criteria of a valid map, the huge string is easier to check
than the string array.*/
void	map_errors(t_map *map, t_mlx *all)
{
	invalid_chars(map->strmap, all);
	item_numbers(map->strmap, all);
	is_rectangular(map, all);
	surrounded_by_walls(map, all);
}
