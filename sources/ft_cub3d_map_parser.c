/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cub3d_map_parser.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjourdan <jjourdan@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/03 14:49:56 by jjourdan          #+#    #+#             */
/*   Updated: 2021/03/16 16:15:17 by jjourdan         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int			ft_cub3d_get_resolution(char **str, \
									t_map_params *map_params)
{
	if (map_params->res_height || map_params->res_width)
		return (DOUBLE_DEF);
	(*str) += 1;
	while (*str[0] == ' ')
		(*str)++;
	if (*str[0] == '-')
		return (MAP_INVALID_RES);
	if ((map_params->res_width = ft_atoi(*str)) <= 0)
		map_params->res_width = 2560;
	while ((*str[0] >= '0') && (*str[0] <= '9'))
		(*str)++;
	while (*str[0] == ' ')
		(*str)++;
	if (*str[0] == '-')
		return (MAP_INVALID_RES);
	if ((map_params->res_height = ft_atoi(*str)) <= 0)
		map_params->res_height = 1395;
	ft_cub3d_get_resolution_2(str);
	while ((*str[0]) && (*str[0] != '\n'))
	{
		if (*str[0] != ' ')
			return (MAP_INVALID_CHAR);
		(*str)++;
	}
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
	if (ft_cub3d_get_texture_2(path, dest, map_params) != SUCCESS)
		return (DOUBLE_DEF);
	free(dest);
	while ((*str[0]) && (*str[0] != '\n'))
	{
		if (*str[0] != ' ')
			return (MAP_INVALID_CHAR);
		(*str)++;
	}
	return (SUCCESS);
}

int			ft_cub3d_get_plane(char **str, \
									t_map_params *map_params)
{
	char	*dest;
	int		r;
	int		g;
	int		b;

	dest = ft_cub3d_get_first_word(str, ' ', '\n');
	if (ft_cub3d_get_plane_2(str, r, g, b) != SUCCESS)
		return (MAP_INVALID_COLOR);
	if ((ft_strncmp(dest, "F", 1) == 0) && (!map_params->floor_color))
		map_params->floor_color = ft_cub3d_create_rgb_3(r, g, b);
	else if ((ft_strncmp(dest, "C", 1) == 0) && (!map_params->ceiling_color))
		map_params->ceiling_color = ft_cub3d_create_rgb_3(r, g, b);
	else
		return (DOUBLE_DEF);
	free(dest);
	ft_cub3d_pass_digit(str);
	while ((*str[0]) && (*str[0] != '\n'))
	{
		if (*str[0] != ' ')
			return (MAP_INVALID_CHAR);
		(*str)++;
	}
	return (SUCCESS);
}

int			ft_cub3d_get_field(char **str, \
								t_map_params *map_params)
{
	map_params->field = ft_strjoin(map_params->field, *str);
	(*str) += ft_strlen(*str);
	return (SUCCESS);
}

int			ft_cub3d_2d_map(t_map_params *map_params)
{
	int		return_value;

	if ((return_value = ft_cub3d_field_is_charset(map_params->field, \
											"\n012 NSEW")) != SUCCESS)
		return (MAP_INVALID_CHAR);
	if (!(map_params->map = ft_cub3d_split(map_params->field, '\n')))
		return (MAP_SPLIT_FAIL);
	if ((return_value = ft_cub3d_is_charset(map_params->map, \
											"012 NSEW")) != SUCCESS)
		return (return_value);
	map_params->starting_pos_x = -1;
	map_params->starting_pos_y = -1;
	if ((return_value = ft_cub3d_get_starting_pos(map_params, \
											"NSEW")) != SUCCESS)
		return (return_value);
	if ((map_params->starting_pos_x == -1) || \
				(map_params->starting_pos_y == -1))
		return (MAP_NO_STARTING_POS);
	if ((return_value = ft_cub3d_check_walls(map_params)) != SUCCESS)
		return (MAP_IS_OPEN);
	return (SUCCESS);
}
