/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cub3d_move.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjourdan <jjourdan@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/22 16:49:26 by jjourdan          #+#    #+#             */
/*   Updated: 2021/02/24 11:11:18 by jjourdan         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int						ft_cub3d_move_vert(t_data *data)
{
	if (data->forward == true)
	{
		if (data->map_params->map[(int)floor(data->pos_y) + 1][(int)floor(data->pos_x) + 1] != '1')
			data->pos_y += data->dir_y * data->move_speed;
		if (data->map_params->map[(int)floor(data->pos_y) + 1][(int)floor(data->pos_x) + 1] != '1')
			data->pos_y += data->dir_x * data->move_speed;
	}
	else if (data->backward == true)
	{
		if (data->map_params->map[(int)floor(data->pos_y) - 1][(int)floor(data->pos_x) - 1] != '1')
			data->pos_y -= data->dir_y * data->move_speed;
		if (data->map_params->map[(int)floor(data->pos_y) - 1][(int)floor(data->pos_x) - 1] != '1')
			data->pos_y -= data->dir_x * data->move_speed;
	} // ! SEGV (use dir x dir y)
	ft_cub3d_reset_input(data);
	return (SUCCESS);
}

int						ft_cub3d_move_horiz(t_data *data)
{
	(void)data;
	return (SUCCESS);
}

int						ft_cub3d_move_rotate(t_data *data)
{
	(void)data;
	return (SUCCESS);
}
