/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cub3d_image_renderer.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjourdan <jjourdan@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/09 11:14:55 by jjourdan          #+#    #+#             */
/*   Updated: 2021/02/15 10:18:42 by jjourdan         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int							ft_cub3d_render_next_img(t_data *data, \
										t_map_params *map_params, int x, int y)
{
	(void)data;
	(void)map_params;
	(void)x;
	(void)y;
	return (SUCCESS);
}

int							ft_cub3d_save_file(t_map_params *map_params)
{
	(void)map_params;
	return (SUCCESS);
}

int							ft_cub3d_launch_game(t_map_params *map_params)
{
	t_data	*data;

	if (!(data = ft_calloc(1, sizeof(data) + 1)))
		return (MALLOC_FAIL);
	data->mlx = mlx_init();
	data->mlx_win = mlx_new_window(data->mlx, map_params->res_width, map_params->res_height, "Cub3D");
	mlx_hook(data->mlx_win, 2, 1L << 0, ft_cub3d_check_key_event, &data);
	mlx_hook(data->mlx_win, 17, 10001, ft_cub3d_kill_all, &data);
	mlx_loop(data->mlx);
	(void)map_params;
	return (SUCCESS);
}
