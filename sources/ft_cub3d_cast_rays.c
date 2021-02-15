/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cub3d_cast_rays.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjourdan <jjourdan@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/15 11:02:33 by jjourdan          #+#    #+#             */
/*   Updated: 2021/02/15 16:18:44 by jjourdan         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int							ft_cub3d_init_player(t_data *data, \
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
	else
	{
		data->dir_y = -1;
		data->plane_x = -0.60;
	}
	return (SUCCESS);
}

int							ft_cub3d_init_walls(t_data *data, \
											t_map_params *map_params)
{
	ssize_t	x;

	x = -1;
	while (++x < map_params->res_width)
	{
		data->camera_x = 2 * x / (double)map_params->res_width - 1;
		data->ray_dir_x = data->dir_x + data->plane_x * data->camera_x;
		data->ray_dir_y = data->dir_y + data->plane_y * data->camera_x;
		data->map_x = data->pos_x;
		data->map_y = data->pos_y;
		data->delta_dist_x = abs(1 / data->ray_dir_x);
		data->delta_dist_y = abs(1 / data->ray_dir_y);
		if (data->ray_dir_x < 0)
		{
			data->step_x = -1;
			data->side_dist_x = (data->pos_x - data->map_x) \
									* data->delta_dist_x;
		}
		else
		{
			data->step_x = 1;
			data->side_dist_x = (data->map_x + 1.0 - data->pos_x) \
									* data->delta_dist_x;
		}
		if (data->ray_dir_y < 0)
		{
			data->step_y = -1;
			data->side_dist_y = (data->pos_y - data->map_y) \
									* data->delta_dist_y;
		}
		else
		{
			data->step_y = 1;
			data->side_dist_y = (data->map_y + 1.0 - data->pos_y) \
									* data->delta_dist_y;
		}
	}
	return (SUCCESS);
}

int							ft_cub3d_cast_rays(t_data *data, \
											t_map_params *map_params)
{
	ft_cub3D_init_player(data, map_params);
	ft_cub3d_init_walls(data, map_params);
	return (SUCCESS);
}
