/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cub3d_image_renderer.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjourdan <jjourdan@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/09 11:14:55 by jjourdan          #+#    #+#             */
/*   Updated: 2021/02/15 16:05:35 by jjourdan         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int							ft_cub3d_render_next_img(t_data *data, \
										t_map_params *map_params)
{
	(void)map_params;
	data->time = clock();
	data->frame_rate = (float)(data->prev_time - data->time) / CLOCKS_PER_SEC;
	data->prev_time = data->time;
	mlx_put_image_to_window(data->mlx, data->mlx_win, data->img, 0, 0);
	mlx_do_sync(data->mlx);
	return (SUCCESS);
}

int							ft_cub3d_save_file(t_map_params *map_params)
{
	(void)map_params;
	printf("%s\n", "IMAGE SAVED TO \"image.bmp\"!");
	return (SUCCESS);
}

int							ft_cub3d_launch_game(t_map_params *map_params)
{
	t_data	*data;

	if (!(data = ft_calloc(1, sizeof(data) + 1)))
		return (MALLOC_FAIL);
	data->mlx = mlx_init();
	data->mlx_win = mlx_new_window(data->mlx, map_params->res_width, \
									map_params->res_height, "Cub3D");
	mlx_hook(data->mlx_win, 2, 1L << 0, ft_cub3d_check_key_event, &data);
	mlx_hook(data->mlx_win, 17, 10001, ft_cub3d_exit, &data);
	mlx_loop_hook(data->mlx, ft_cub3d_cast_rays, &data);
	mlx_loop(data->mlx);
	return (SUCCESS);
}
