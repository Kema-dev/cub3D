/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cub3d_image_creater.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjourdan <jjourdan@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/29 16:32:11 by jjourdan          #+#    #+#             */
/*   Updated: 2021/02/02 10:07:23 by jjourdan         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_data		ft_cub3d_render_next_img(t_vars *vars, \
									int x, \
									int y)
{
	t_data	img;

	img.img = mlx_new_image(vars->mlx, 1920, 1080);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, \
								&img.line_length, &img.endian);
	ft_cub3d_pixel_put(&img, y, x, GREEN);
	mlx_put_image_to_window(vars->mlx, vars->win, img.img, 0, 0);
	return (img);
}
