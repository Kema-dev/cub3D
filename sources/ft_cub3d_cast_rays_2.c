/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cub3d_cast_rays_2.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjourdan <jjourdan@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/16 12:54:50 by jjourdan          #+#    #+#             */
/*   Updated: 2021/02/17 15:09:08 by jjourdan         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void						ft_cub3d_hitbox(t_data *data)
{
	printf("x=%f\n", data->pos_x);
	printf("y=%f\n", data->pos_y);
	while (data->hit == 0)
	{
		if (data->side_dist_x < data->side_dist_y)
		{
			data->side_dist_x += data->delta_dist_x;
			data->pos_x += data->step_x;
			data->side = 0;
		}
		else
		{
			data->side_dist_y += data->delta_dist_y;
			data->pos_y += data->step_y;
			data->side = 1;
		}
		if (data->map_params->map[(int)data->pos_x][(int)data->pos_y] == '1')
			data->hit = 1;
	}
}

void						ft_cub3d_draw_ray(t_data *data)
{
	if (data->side == 0)
		data->perp_wall_dist = (data->map_x - data->pos_x \
				+ (1 - data->step_x) / 2) / data->ray_dir_x;
	else
		data->perp_wall_dist = (data->map_y - data->pos_y \
				+ (1 - data->step_y) / 2) / data->ray_dir_y;
	data->line_height = (int)(data->map_params->res_height \
							/ data->perp_wall_dist);
	data->draw_start = -data->line_height / 2 \
					+ data->map_params->res_height / 2;
	if (data->draw_start < 0)
		data->draw_start = 0;
	data->draw_end = data->line_height / 2 + data->map_params->res_height / 2;
	if (data->draw_end >= (ssize_t)data->map_params->res_height)
		data->draw_end = data->map_params->res_height - 1;
}

void						ft_cub3d_pixel_put(t_data *data, int x, int y, \
												int color)
{
	char	*pixel;

	pixel = data->addr + (y * data->line_length \
			+ x * (data->bits_per_pixel / 8));
	*(unsigned int *)pixel = color;
}

void						ft_cub3d_pixel_creation(t_data *data, ssize_t *x)
{
	ssize_t	i;
	int		color;

	data->draw_end = data->map_params->res_height - data->draw_start;
	if ((data->side == 0) && (data->ray_dir_x < 0))
		color = ft_cub3d_create_rgb_3(200, 0, 0);
	else if ((data->side == 0) && (data->ray_dir_x >= 0))
		color = ft_cub3d_create_rgb_3(0, 200, 0);
	else if ((data->side == 1) && (data->ray_dir_x < 0))
		color = ft_cub3d_create_rgb_3(0, 0, 200);
	else if ((data->side == 1) && (data->ray_dir_x >= 0))
		color = ft_cub3d_create_rgb_3(200, 0, 200);
	i = -1;
	while (++i < (ssize_t)data->map_params->res_height)
		ft_cub3d_pixel_put(data, *x, i, data->map_params->ceiling_color);
	if (i <= data->draw_end)
		ft_cub3d_put_texture(data, *x, &i);
	while (++i < (ssize_t)data->map_params->res_height)
		ft_cub3d_pixel_put(data, *x, i, data->map_params->floor_color);
}
