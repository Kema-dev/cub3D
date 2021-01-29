/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cub3d_debug_main.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjourdan <jjourdan@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/26 15:58:19 by jjourdan          #+#    #+#             */
/*   Updated: 2021/01/29 14:29:26 by jjourdan         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int             main(void)
{
    t_vars		vars;
    t_input		*input_values;
	t_data		img;

	if (!(input_values = malloc(sizeof(t_input))))
		return (-1);
    vars.mlx = mlx_init();
    vars.win = mlx_new_window(vars.mlx, 1920, 1080, "Leche moi le cub");
	img.img = mlx_new_image(vars.mlx, 1920, 1080);
    img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, \
									&img.endian);
    ft_cub3d_pixel_put(&img, 5, 5, GREEN);
	mlx_put_image_to_window(vars.mlx, vars.win, img.img, 0, 0);
	mlx_hook(vars.win, 2, 1L<<0, ft_cub3d_check_key_event, &vars);
    mlx_hook(vars.win, 17, 10001, ft_cub3d_kill_all, &vars);
    mlx_loop(vars.mlx);
	return (0);
}
