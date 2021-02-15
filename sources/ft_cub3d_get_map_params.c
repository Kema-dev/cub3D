/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cub3d_get_map_params.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjourdan <jjourdan@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/03 12:43:29 by jjourdan          #+#    #+#             */
/*   Updated: 2021/02/15 14:33:16 by jjourdan         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int			ft_cub3d_get_map_params(t_map_params *map_params, \
									char *map_lines)
{
	char	*tmp;
	int		return_value;

	tmp = map_lines;
	while ((return_value = ft_cub3d_get_next_param(&tmp, map_params)) \
															== SUCCESS)
		;
	if ((return_value != SUCCESS) && (return_value != PASS))
		return (return_value);
	free(map_lines);
	if ((return_value = ft_cub3d_2d_map(map_params)) != SUCCESS)
		return (return_value);
	return (SUCCESS);
}

int			ft_cub3d_last_checks(char **tmp)
{
	if (*tmp[0] != 0)
		return (MAP_INVALID_CONFIG);
	else
		return (PASS);
}

int			ft_cub3d_param_return(int return_value)
{
	if (return_value != SUCCESS)
		return (return_value);
	return (SUCCESS);
}

int			ft_cub3d_get_next_param(char **tmp, \
									t_map_params *map_params)
{
	int		return_value;

	while ((*tmp[0] == '\n') || (*tmp[0] == ' '))
		(*tmp) += 1;
	if (*tmp[0] == 'R')
	{
		return_value = ft_cub3d_get_resolution(tmp, map_params);
	}
	else if ((strncmp(*tmp, "NO ", 3) == 0) || (strncmp(*tmp, "SO ", 3) == 0) \
		|| (strncmp(*tmp, "WE ", 3) == 0) || (strncmp(*tmp, "EA ", 3) == 0) \
		|| (strncmp(*tmp, "S ", 2) == 0))
	{
		return_value = ft_cub3d_get_texture(tmp, map_params);
	}
	else if ((strncmp(*tmp, "F ", 2) == 0) || (strncmp(*tmp, "C ", 2) == 0))
	{
		return_value = ft_cub3d_get_plane(tmp, map_params);
	}
	else if (ft_isdigit(*tmp[0]))
	{
		return_value = ft_cub3d_get_field(tmp, map_params);
	}
	else
		return (ft_cub3d_last_checks(tmp));
	return (ft_cub3d_param_return(return_value));
}
