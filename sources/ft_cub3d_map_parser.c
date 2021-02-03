/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cub3d_map_parser.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjourdan <jjourdan@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/03 12:43:29 by jjourdan          #+#    #+#             */
/*   Updated: 2021/02/03 16:20:00 by jjourdan         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int			ft_cub3d_get_map_params(t_map_params *map_params, \
									char *map_lines)
{
	char	*tmp;
	int		return_value;

	tmp = map_lines;
	return_value = SUCCESS;
	while (tmp[0] != 0)
		if ((return_value = ft_cub3d_get_next_param(tmp, map_params)) \
															!= SUCCESS)
			return (return_value);
	printf("%s", "oui");
	return (SUCCESS);
}

int			ft_cub3d_get_next_param(char *tmp, \
									t_map_params *map_params)
{
	int		return_value;

	return_value = SUCCESS;
	while (tmp[0] == '\n')
		tmp++;
	if (tmp[0] == 'R')
	{
		if ((return_value = ft_cub3d_get_resolution(tmp, map_params)) != SUCCESS)
			return (return_value);
	}
	else if ((strncmp(tmp, "NO", 3) == 0) || (strncmp(tmp, "SO", 3) == 0) || \
			(strncmp(tmp, "WE", 3) == 0) || (strncmp(tmp, "EA", 3) == 0) || \
			(strncmp(tmp, "S", 2) == 0))
			{
		if ((return_value = ft_cub3d_get_texture(tmp, map_params)) != SUCCESS)
			return (return_value);
	}
	else if ((strncmp(tmp, "F", 2) == 0) || (strncmp(tmp, "C", 2) == 0))
	{
		if ((return_value = ft_cub3d_get_plane(tmp, map_params)) != SUCCESS)
			return (return_value);
	}
	else if (ft_isdigit(tmp[0]))
	{
		if ((return_value = ft_cub3d_get_field(tmp, map_params)) != SUCCESS)
			return (return_value);
	}
	else
		return (MAP_INVALID_CONFIG);
	return (SUCCESS);
}

/*
** MAP SAMPLE
** 
** R 1280 720
** NO ./textures/bookshelf.xpm
** SO ./textures/cracked_stone_bricks.xpm
** WE ./textures/piston_top.xpm
** EA ./textures/purplestone.xpm
** S ./textures/barrel.xpm
** F 155,62,62
** C 51,204,255
** 
** 1111111111111111111111111111111111
** 1000000000010202020100000111110111
** 1000000000010000000100000000000001
** 1000101000010202020111111100000001
** 10001010000100000001000000000000001
** 1000101000011100111111111110111111
** 120000W0002000000001      101
** 10002000000000000021111111101
** 100000000000000020000000000001
** 100000200000000000211111111111
** 11111111111111111111
*/