/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cub3d_key_events_manager.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjourdan <jjourdan@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/27 13:04:01 by jjourdan          #+#    #+#             */
/*   Updated: 2021/02/15 15:30:34 by jjourdan         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		ft_cub3d_check_key_event(int keycode, \
								t_data *data, \
								t_input *input_values, \
								t_map_params *map_params)
{
	(void)map_params;
	if (keycode == ESC_KEY)
		ft_cub3d_exit();
	else if (keycode == W_KEY)
		input_values->w = true;
	else if (keycode == A_KEY)
		input_values->a = true;
	else if (keycode == S_KEY)
		input_values->s = true;
	else if (keycode == D_KEY)
		input_values->d = true;
	else if (keycode == LEFT_ARROW_KEY)
		input_values->left = true;
	else if (keycode == RIGHT_ARROW_KEY)
		input_values->right = true;
	else
		return (ft_cub3d_invalid_input(keycode, data, input_values));
	return (SUCCESS);
}

void	ft_cub3d_treat_input(t_data *data, \
							t_input *input_values, \
							t_map_params *map_params)
{
	(void)data;
	(void)input_values;
	(void)map_params;
}

int		ft_cub3d_invalid_input(int keycode, \
							t_data *data, \
							t_input *input_values)
{
	input_values->other = true;
	printf("keycode %d does nothing!\n", keycode);
	(void)data;
	return (SUCCESS);
}
