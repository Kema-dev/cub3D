/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cub3d_image_renderer.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjourdan <jjourdan@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/09 11:14:55 by jjourdan          #+#    #+#             */
/*   Updated: 2021/02/12 11:19:55 by jjourdan         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int							ft_cub3d_init_mlx(t_data *data, t_map_params *map_params)
{
	data->mlx = mlx_init();
	data->win = mlx_new_window(data->mlx, map_params->res_width, \
								map_params->res_height, "leche moi le cub");
	data->img = mlx_new_image(data->mlx, map_params->res_width, \
								map_params->res_height);
	data->addr = mlx_get_data_addr(data->img, data->bits_per_pixel, \
									data->line_length, data->endian);
	return (SUCCESS);
}

int							ft_cub3d_save_file(t_map_params *map_params)
{
	int		return_value;
	t_data	*data;

	if (!(data = ft_calloc(1, sizeof(t_data) + 1)))
		return (MALLOC_FAIL);
	if ((return_value = ft_cub3d_init_mlx(data, map_params)) != SUCCESS)
		return (return_value);
	
	return (SUCCESS);
}

int							ft_cub3d_launch_game(t_map_params *map_params)
{
	int		return_value;
	t_data	*data;

	if (!(data = ft_calloc(1, sizeof(t_data) + 1)))
		return (MALLOC_FAIL);
	if ((return_value = ft_cub3d_init_mlx(data, map_params)) != SUCCESS)
		return (return_value);
	mlx_hook(data->win, 2, 1L << 0, ft_cub3d_check_key_event, data);
	mlx_hook(data->win, 17, 10001, ft_cub3d_kill_all, data);
	mlx_loop(data->mlx);
	return (SUCCESS);
}

/*
** int				main(void)
** {
** 	t_vars		vars;
** 	t_input		*input_values;
**
** 	if (!(input_values = malloc(sizeof(t_input))))
** 		return (-1);
** 	input_values->x = 5;
** 	input_values->y = 5;
** 	vars.mlx = mlx_init();
** 	vars.win = mlx_new_window(vars.mlx, 1920, 1080, "Leche moi le cub");
** 	mlx_hook(vars.win, 2, 1L << 0, ft_cub3d_check_key_event, &vars);
** 	mlx_hook(vars.win, 17, 10001, ft_cub3d_kill_all, &vars);
** 	mlx_loop(vars.mlx);
** 	return (0);
** }
*/
