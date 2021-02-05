/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cub3d_check_walls.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjourdan <jjourdan@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/05 15:26:51 by jjourdan          #+#    #+#             */
/*   Updated: 2021/02/05 15:58:58 by jjourdan         ###   ########lyon.fr   */
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
	len = ft_strlen(map[nb_rows]);
	if (!(test_map[nb_rows + 2] = ft_calloc(len + 1, sizeof(char))))
		return (NULL);
	ft_memset(test_map[nb_rows + 2], 'X', len);
	printf("=%s=\n", test_map[nb_rows+2]);
	while (nb_rows > 0)
	{
		if (!(test_map[nb_rows] = ft_calloc(len = ft_strlen(map[nb_rows - 1]) + 1, sizeof(char))))
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
	len = -1;
	while (test_map[++len])
		printf("%s\n", test_map[len]);
	return (test_map);
}

int							ft_cub3d_check_walls(t_map_params *map_params, \
													char empty, \
													char wall, \
													char sprite)
{
	char	**test_map;

	if (!(test_map = ft_cub3d_get_test_map(map_params->map)))
		return (MALLOC_FAIL);
	(void)empty;
	(void)wall;
	(void)sprite;
	return (SUCCESS);
}
