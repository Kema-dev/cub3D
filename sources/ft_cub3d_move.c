/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cub3d_move.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjourdan <jjourdan@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/22 16:49:26 by jjourdan          #+#    #+#             */
/*   Updated: 2021/02/22 16:54:59 by jjourdan         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int						ft_cub3d_move_vert(t_data *data)
{
	if (data->forward == true)
	{
		if (data->map_params->map[floor(data->pos_x)])
	}
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
