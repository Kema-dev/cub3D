/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cub3d_image_creater.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjourdan <jjourdan@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/29 16:32:11 by jjourdan          #+#    #+#             */
/*   Updated: 2021/02/12 11:16:43 by jjourdan         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_data		ft_cub3d_render_next_img(t_data *data, \
									int x, \
									int y)
{
	data->img = mlx_new_image(data->mlx, data->res_width, data->res_height);
	data->addr = mlx_get_data_addr(data->img, data->bits_per_pixel, \
								data->line_length, data->endian);
	ft_cub3d_pixel_put(data, y, x, GREEN);
	mlx_put_image_to_window(data->mlx, data->win, data->img, 0, 0);
	return (data);
}
