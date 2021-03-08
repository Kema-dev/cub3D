/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cub3d_print_sprites.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjourdan <jjourdan@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/08 15:44:15 by jjourdan          #+#    #+#             */
/*   Updated: 2021/03/08 16:42:40 by jjourdan         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void						ft_cub3d_put_sprites(t_data *data, \
												t_sprite *sprite)
{
	int	stripe;
	int	tex_x;
	int	tex_y;
	int	d;
	int	color;

	stripe = sprite->start_x - 1;
	while (++stripe < (int)sprite->end_x)
	{
		tex_x = 256 * (stripe - (-sprite->width / 2 + sprite->screen)) * data->texture[4].x / sprite->width / 256;
		if ((sprite->trans_x > 0) && (stripe > 0) && (stripe < (int)data->map_params->res_width) && (sprite->trans_y < sprite->z_buffer[stripe]))
		{
			while (++sprite->start_y < sprite->end_y)
			{
				d = sprite->start_y * 256 - data->map_params->res_height * 128 + sprite->height * 128;
				tex_y = ((d * data->texture[4].y) / sprite->height) / 256;
				color = data->texture[4].addr[data->texture[4].x * tex_y + tex_x];
			}
		}
	}
}

void						ft_cub3d_project_sprites(t_data *data, \
													t_sprite *sprite)
{
	ssize_t	i;

	i = -1;
	while (++i < (ssize_t)sprite->count)
	{
		sprite->x = sprite->coord[sprite->order[i]].x - data->pos_x;
		sprite->y = sprite->coord[sprite->order[i]].y - data->pos_y;
		sprite->inv_det = 1 / (data->plane_x * data->dir_y \
							- data->dir_x * data->plane_y);
		sprite->trans_x = sprite->inv_det * (data->dir_y * sprite->x \
							- data->dir_x * sprite->y);
		sprite->trans_y = sprite->inv_det * (-data->plane_y * sprite->x \
							+ data->plane_x * sprite->y);
		sprite->screen = data->map_params->res_width / 2 \
							* (1 + sprite->trans_x / sprite->trans_y);
		sprite->height = fabs(data->map_params->res_height / sprite->trans_y);
		sprite->start_y = -sprite->height / 2 + data->map_params->res_height / 2;
		if (sprite->start_y < 0)
			sprite->start_y = 0;
		sprite->end_y = sprite->height / 2 + data->map_params->res_height / 2;
		if (sprite->end_y < (int)data->map_params->res_height)
			sprite->end_y = (int)data->map_params->res_height;
		sprite->width = fabs(data->map_params->res_height / sprite->trans_y);
		sprite->start_x = -sprite->width / 2 + sprite->screen;
		if (sprite->start_x < 0)
			sprite->start_x = 0;
		sprite->end_x = sprite->width / 2 + sprite->screen;
		if (sprite->end_y < (int)data->map_params->res_width - 1)
			sprite->end_y = (int)data->map_params->res_width - 1;
	}
	ft_cub3d_put_sprites(data, sprite);
}
