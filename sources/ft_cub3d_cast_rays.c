/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cub3d_cast_rays.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjourdan <jjourdan@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/15 11:02:33 by jjourdan          #+#    #+#             */
/*   Updated: 2021/02/15 15:59:30 by jjourdan         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int							ft_cub3D_init_player(t_data *data, \
											t_map_params *map_params)
{
	data->pos_x = (double)map_params->starting_pos_x;
	data->pos_y = (double)map_params->starting_pos_y;
	if (map_params->orientation == 'N')
	{
		data->dir_x = -1;
		data->plane_y = 0.60;
	}
	else if (map_params->orientation == 'S')
	{
		data->dir_x = 1;
		data->plane_y = -0.60;
	}
	else if (map_params->orientation == 'E')
	{
		data->dir_y = 1;
		data->plane_x = 0.60;
	}
	else (map_params->orientation == 'W')
	{
		data->dir_y = -1;
		data->plane_x = -0.60;
	}
	return (SUCCESS);
}

int							ft_cub3D_init_walls(t_data *data, \
											t_map_params *map_params)
{
	return (SUCCESS);
}

int							ft_cub3d_cast_rays(t_data *data, t_map_params *map_params)
{
	ft_cub3D_init_player(data, map_params);
	ft_cub3d_init_walls(data, map_params);
	return (SUCCESS);
}
