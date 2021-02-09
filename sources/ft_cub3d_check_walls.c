/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cub3d_check_walls.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjourdan <jjourdan@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/05 15:26:51 by jjourdan          #+#    #+#             */
/*   Updated: 2021/02/09 10:02:57 by jjourdan         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

char						**ft_cub3d_get_test_map(char **map)
{
	ssize_t	nb_rows;
	ssize_t	len;
	char	**test_map;

	nb_rows = 0;
	while (map[nb_rows])
	{
		map[nb_rows] = ft_strjoin_free_s2("X", map[nb_rows]);
		map[nb_rows] = ft_strjoin_free_s1(map[nb_rows], "X");
		nb_rows++;
	}
	if (!(test_map = ft_calloc(nb_rows + 3, sizeof(char *))))
		return (NULL);
	len = ft_strlen(map[0]);
	if (!(test_map[0] = ft_calloc(len + 1, sizeof(char))))
		return (NULL);
	ft_memset(test_map[0], 'X', len);
	len = ft_strlen(map[nb_rows - 1]);
	if (!(test_map[nb_rows + 1] = ft_calloc(len + 1, sizeof(char))))
		return (NULL);
	ft_memset(test_map[nb_rows + 1], 'X', len);
	while (nb_rows > 0)
	{
		if (!(test_map[nb_rows] = ft_calloc(len = ft_strlen(map[nb_rows - 1]) \
													+ 1, sizeof(char))))
			return (NULL);
		while (--len >= 0)
		{
			if (map[nb_rows - 1][len] == ' ')
				test_map[nb_rows][len] = 'X';
			else
				test_map[nb_rows][len] = map[nb_rows - 1][len];
		}
		nb_rows--;
	}
	return (test_map);
}

int							ft_cub3d_check_walls(t_map_params *map_params)
{
	char	**test_map;
	int		return_value;
	ssize_t	i;

	if (!(test_map = ft_cub3d_get_test_map(map_params->map)))
		return (MALLOC_FAIL);
	if ((return_value = ft_cub3d_recursive_wall(test_map, \
							map_params->starting_pos_x + 1, \
							map_params->starting_pos_y + 1)) != SUCCESS)
		return (MAP_IS_OPEN);
	i = -1;
	while (test_map[++i])
		free(test_map[i]);
	free(test_map);
	return (SUCCESS);
}

void						ft_cub3d_print_map(char **map)
{
	ssize_t	i;

	i = -1;
	while (map[++i])
		printf("%s\n", map[i]);
}

int							ft_cub3d_recursive_wall(char **test_map, \
													size_t x, \
													size_t y)
{
	int	return_value;

	return_value = 0;
	if ((test_map[y][x] == 'v') || (test_map[y][x] == '1'))
		return (0);
	else if (test_map[y][x] == 'X')
		return (1);
	if ((ft_strlen(test_map[y - 1]) <= x) || (ft_strlen(test_map[y + 1]) <= x))
		return (1);
	else
	{
		test_map[y][x] = 'v';
		return_value += ft_cub3d_recursive_wall(test_map, x, y + 1);
		return_value += ft_cub3d_recursive_wall(test_map, x + 1, y);
		return_value += ft_cub3d_recursive_wall(test_map, x, y - 1);
		return_value += ft_cub3d_recursive_wall(test_map, x - 1, y);
	}
	return (return_value);
}
