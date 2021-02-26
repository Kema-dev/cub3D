/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cub3d_image_renderer.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjourdan <jjourdan@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/09 11:14:55 by jjourdan          #+#    #+#             */
/*   Updated: 2021/02/26 12:45:19 by jjourdan         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int							ft_cub3d_render_next_img(t_data *data)
{
	ft_cub3d_cast_rays(data);
	data->time = clock();
	data->frame_time = (float)(data->time - data->prev_time) / CLOCKS_PER_SEC;
	if (++data->frame_uni > 30)
	{
		printf("\rfps:%.2f", 1 / data->frame_time);
		fflush(stdout);
		data->frame_uni = 0;
	}
	data->prev_time = data->time;
	mlx_put_image_to_window(data->mlx, data->mlx_win, data->img, 0, 0);
	mlx_do_sync(data->mlx);
	ft_cub3d_move_vert(data);
	ft_cub3d_move_horiz(data);
	ft_cub3d_move_rotate(data);
	ft_cub3d_reset_input(data);
	return (SUCCESS);
}

int							ft_cub3d_save_file(t_map_params *map_params)
{
	t_data	*data;

	if (!(data = ft_calloc(1, sizeof(data))))
		return (MALLOC_FAIL);
	data->map_params = map_params;
	data->mlx = mlx_init();
	ft_cub3d_raycast_param(data);
	ft_cub3d_raycast_orientation(data);
	data->img = mlx_new_image(data->mlx, data->map_params->res_width, \
								data->map_params->res_height);
	data->addr = mlx_get_data_addr(data->img, &data->bits_per_pixel, \
									&data->line_length, &data->endian);
	ft_cub3d_cast_rays(data);
	ft_cub3d_create_bmp(data);
	printf("%s\n", "IMAGE SAVED TO \"image.bmp\"!");
	return (SUCCESS);
}

void						ft_cub3d_get_text_addr(t_data *data)
{
	data->texture[0].addr = mlx_get_data_addr(data->texture[0].img, \
											&data->texture[0].bits_per_pixel, \
											&data->texture[0].x, \
											&data->endian);
	data->texture[1].addr = mlx_get_data_addr(data->texture[1].img, \
											&data->texture[1].bits_per_pixel, \
											&data->texture[1].x, \
											&data->endian);
	data->texture[2].addr = mlx_get_data_addr(data->texture[2].img, \
											&data->texture[2].bits_per_pixel, \
											&data->texture[2].x, \
											&data->endian);
	data->texture[3].addr = mlx_get_data_addr(data->texture[3].img, \
											&data->texture[3].bits_per_pixel, \
											&data->texture[3].x, \
											&data->endian);
	data->texture[4].addr = mlx_get_data_addr(data->texture[4].img, \
											&data->texture[4].bits_per_pixel, \
											&data->texture[4].x, \
											&data->endian);
}

int							ft_cub3d_raycast_load_text(t_data *data)
{
	if (ft_cub3d_get_text_infos(data) != SUCCESS)
		return (TEXT_FAILURE);
	if (!(data->texture[0].img = mlx_xpm_file_to_image(data->mlx, \
		data->map_params->north_text, \
					&data->texture[0].x, &data->texture[0].y)))
		return (TEXT_FAILURE);
	if (!(data->texture[1].img = mlx_xpm_file_to_image(data->mlx, \
		data->map_params->south_text, \
					&data->texture[1].x, &data->texture[1].y)))
		return (TEXT_FAILURE);
	if (!(data->texture[2].img = mlx_xpm_file_to_image(data->mlx, \
		data->map_params->east_text, \
					&data->texture[2].x, &data->texture[2].y)))
		return (TEXT_FAILURE);
	if (!(data->texture[3].img = mlx_xpm_file_to_image(data->mlx, \
		data->map_params->west_text, \
					&data->texture[3].x, &data->texture[3].y)))
		return (TEXT_FAILURE);
	if (!(data->texture[4].img = mlx_xpm_file_to_image(data->mlx, \
		data->map_params->sprite_text, \
					&data->texture[4].x, &data->texture[4].y)))
		return (TEXT_FAILURE);
	ft_cub3d_get_text_addr(data);
	return (SUCCESS);
}

int							ft_cub3d_launch_game(t_map_params *map_params)
{
	t_data	*data;

	if (!(data = ft_calloc(1, sizeof(data))))
		return (MALLOC_FAIL);
	data->map_params = map_params;
	data->mlx = mlx_init();
	ft_cub3d_raycast_param(data);
	ft_cub3d_raycast_orientation(data);
	//if ((ft_cub3d_raycast_load_text(data)) != SUCCESS)
	//	return (TEXT_FAILURE);
	data->mlx_win = mlx_new_window(data->mlx, data->map_params->res_width, \
									data->map_params->res_height, "Cub3D");
	data->img = mlx_new_image(data->mlx, data->map_params->res_width, \
								data->map_params->res_height);
	data->addr = mlx_get_data_addr(data->img, &data->bits_per_pixel, \
									&data->line_length, &data->endian);
	mlx_hook(data->mlx_win, 2, 1L << 0, ft_cub3d_check_key_event, data);
	mlx_hook(data->mlx_win, 17, 10001, ft_cub3d_exit, &data);
	mlx_loop_hook(data->mlx, ft_cub3d_render_next_img, data);
	mlx_loop(data->mlx);
	return (SUCCESS);
}
