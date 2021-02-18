/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cub3d_draw_texture.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjourdan <jjourdan@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/16 15:04:14 by jjourdan          #+#    #+#             */
/*   Updated: 2021/02/18 12:10:30 by jjourdan         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void						ft_cub3d_text_init(t_data *data)
{
	if ((data->side == 0) && (data->ray_dir_x) < 0)
		data->tex_val.dir = 0;
	if (data->side == 0 && data->ray_dir_x >= 0)
		data->tex_val.dir = 1;
	if (data->side == 1 && data->ray_dir_y < 0)
		data->tex_val.dir = 2;
	if (data->side == 1 && data->ray_dir_y >= 0)
		data->tex_val.dir = 3;
	if (data->side == 0)
		data->tex_val.wall_x = data->pos_y + data->perp_wall_dist \
							* data->ray_dir_y;
	else
		data->tex_val.wall_x = data->pos_x + data->perp_wall_dist \
							* data->ray_dir_x;
	data->tex_val.wall_x -= floor((data->tex_val.wall_x));
}

void						ft_cub3d_put_texture(t_data *data, \
										int x, ssize_t *i)
{
	*i = data->draw_start - 1;
	ft_cub3d_text_init(data);
	data->tex_val.step = 1.0 * data->texture[0].rows \
		/ data->line_height;
	data->tex_val.x = (int)(data->tex_val.wall_x * \
			(double)data->texture[data->tex_val.dir].cols);
	if (data->side == 0 && data->ray_dir_x > 0)
		data->tex_val.x = data->texture[data->tex_val.dir].cols -\
			data->tex_val.x - 1;
	if (data->side == 1 && data->ray_dir_y < 0)
		data->tex_val.x = data->texture[data->tex_val.dir].cols -\
			data->tex_val.x - 1;
	data->tex_val.pos = (data->draw_start - data->map_params->res_width / 2 +\
			data->line_height / 2) * data->tex_val.step;
	while (++*i <= data->draw_end)
	{
		data->tex_val.y = (int)data->tex_val.pos &\
			(data->texture[data->tex_val.dir].rows - 1);
		data->tex_val.pos += data->tex_val.step;
		if (*i < (ssize_t)data->map_params->res_width && \
				(size_t)x < data->map_params->res_width)
			ft_cub3d_swap_addr(data, x, i);
	}
}
