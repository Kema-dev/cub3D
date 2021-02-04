/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cub3d_map_parser.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjourdan <jjourdan@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/03 14:49:56 by jjourdan          #+#    #+#             */
/*   Updated: 2021/02/04 16:45:32 by jjourdan         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int			ft_cub3d_get_resolution(char **str, \
									t_map_params *map_params)
{
	ft_cub3d_go_next_word(str, ' ', '\n');
	if ((map_params->res_width = ft_atoi(*str)) <= 0)
		return (MAP_INVALID_RES);
	ft_cub3d_go_next_word(str, ' ', '\n');
	if ((map_params->res_height = ft_atoi(*str)) <= 0)
		return (MAP_INVALID_RES);
	ft_cub3d_go_next_word(str, ' ', '\n');
	return (SUCCESS);
}

int			ft_cub3d_get_texture(char **str, \
									t_map_params *map_params)
{
	char	*path;
	char	*dest;
	ssize_t	i;

	i = 0;
	dest = ft_cub3d_get_first_word(str, ' ', '\n');
	ft_cub3d_go_next_word(str, ' ', '\n');
	path = ft_cub3d_get_first_word(str, ' ', '\n');
	if (strncmp(dest, "NO", 2) == 0)
		map_params->north_text = path;
	else if (strncmp(dest, "SO", 2) == 0)
		map_params->south_text = path;
	else if (strncmp(dest, "WE", 2) == 0)
		map_params->west_text = path;
	else if (strncmp(dest, "EA", 2) == 0)
		map_params->east_text = path;
	else
		map_params->sprite_text = path;
	return (SUCCESS);
}

int			ft_cub3d_get_plane(char **str, \
									t_map_params *map_params)
{
	char	*dest;
	int		r;
	int		g;
	int		b;
	size_t	i;

	i = 0;
	r = 0;
	g = 0;
	b = 0;
	dest = ft_cub3d_get_first_word(str, ' ', '\n');
	ft_cub3d_go_next_word(str, ' ', '\n');
	if ((r = ft_atoi(*str)) < 0)
		return (MAP_INVALID_COLOR);
	while (ft_isdigit(*str[0]))
		(*str) += 1;
	(*str) += 1;
	if ((g = ft_atoi(*str)) < 0)
		return (MAP_INVALID_COLOR);
	while (ft_isdigit(*str[0]))
		(*str) += 1;
	(*str) += 1;
	if ((b = ft_atoi(*str)) < 0)
		return (MAP_INVALID_COLOR);
	if ((r > 255) || (g > 255) || (b > 255))
		return (MAP_INVALID_COLOR);
	if (ft_strncmp(dest, "F", 1) == 0)
		map_params->floor_color = ft_cub3d_create_trgb(0, r, g, b);
	else
		map_params->ceiling_color = ft_cub3d_create_trgb(0, r, g, b);
	return (SUCCESS);
}

int			ft_cub3d_get_field(char **str, \
								t_map_params *map_params)
{
	map_params->field = ft_strjoin(map_params->field, *str);
	(*str) += ft_strlen(*str);
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