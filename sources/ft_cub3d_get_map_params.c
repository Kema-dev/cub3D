/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cub3d_get_map_params.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjourdan <jjourdan@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/03 14:49:56 by jjourdan          #+#    #+#             */
/*   Updated: 2021/02/03 16:26:50 by jjourdan         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int			ft_cub3d_get_resolution(char *str, \
									t_map_params *map_params)
{
	size_t	i;

	i = 0;
	if ((map_params->res_width = ft_atoi(str)) <= 0)
		return (MAP_INVALID_RES);
	while (ft_isdigit(str[i]) || (str[i] == ' '))
		i++;
	if ((map_params->res_height = ft_atoi(str)) <= 0)
		return (MAP_INVALID_RES);
	while (ft_isdigit(str[i]) || (str[i] == ' '))
		i++;
	str += i;
	return (SUCCESS);
}

int			ft_cub3d_get_texture(char *tmp, \
									t_map_params *map_params)
{
	char	*path;
	char	*dest;
	size_t	i;

	i = 0;
	if (strncmp(tmp, "NO", 3) == 0)
		dest = map_params->north_text;
	else if (strncmp(tmp, "SO", 3) == 0)
		dest = map_params->south_text;
	else if (strncmp(tmp, "WE", 3) == 0)
		dest = map_params->west_text;
	else if (strncmp(tmp, "EA", 3) == 0)
		dest = map_params->east_text;
	else
		dest = map_params->sprite_text;
	while (ft_isalpha(tmp[i]))
		tmp++;
	while (tmp[i] == ' ')
		tmp++;
	while (ft_isalpha(tmp[i]))
		i++;
	if (!(path = ft_calloc(i + 1, sizeof(char))))
		return (MALLOC_FAIL);
	dest = path;
	tmp += i;
	return (SUCCESS);
}

int			ft_cub3d_get_plane(char *tmp, \
									t_map_params *map_params)
{
	int		*dest;
	int		r;
	int		g;
	int		b;
	size_t	i;

	i = 0;
	r = 0;
	g = 0;
	b = 0;
	if (strncmp(tmp, "F", 2) == 0)
		dest = &map_params->floor_color;
	else
		dest = &map_params->ceilling_color;
	if ((r = ft_atoi(tmp)) < 0)
		return (MAP_INVALID_COLOR);
	while (tmp[0] && tmp[0] != ',')
		i++;
	if ((g = ft_atoi(tmp)) < 0)
		return (MAP_INVALID_COLOR);
	while (tmp[0] && tmp[0] != ',')
		i++;
	if ((b = ft_atoi(tmp)) < 0)
		return (MAP_INVALID_COLOR);
	while (tmp[0] && tmp[0] != '\n')
		i++;
	if ((r < 0 || r > 255) || (g < 0 || g > 255) || (b < 0 || b > 255))
		return (MAP_INVALID_COLOR);
	tmp += i;
	*dest = ft_cub3d_create_trgb(0, r, g, b);
	return (SUCCESS);
}

int			ft_cub3d_get_field(char *str, \
								t_map_params *map_params)
{
	map_params->field = ft_strjoin(map_params->field, str);
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