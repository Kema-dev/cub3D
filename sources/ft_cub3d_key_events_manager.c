/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cub3d_key_events_manager.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjourdan <jjourdan@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/27 13:04:01 by jjourdan          #+#    #+#             */
/*   Updated: 2021/01/29 17:22:39 by jjourdan         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		ft_cub3d_check_key_event(int keycode, t_vars *vars, t_input *input_values)
{
	ft_cub3d_reset_input(input_values);
	if (keycode == ESC_KEY)
		ft_cub3d_kill_all(vars);
	else if (keycode == W_KEY)
		input_values->W = true;
	else if (keycode == A_KEY)
		input_values->A = true;
	else if (keycode == S_KEY)
		input_values->S = true;
	else if (keycode == D_KEY)
		input_values->D = true;
	else if (keycode == LEFT_ARROW_KEY)
		input_values->LEFT = true;
	else if (keycode == RIGHT_ARROW_KEY)
		input_values->RIGHT = true;
	else
		return (ft_cub3d_invalid_input(keycode, vars, input_values));
	ft_cub3d_treat_input(vars, input_values);
	return (0);
}

void	ft_cub3d_treat_input(t_vars *vars, t_input *input_values)
{
	if (input_values->W == true)
		input_values->x -= 1;
	if (input_values->S == true)
		input_values->x += 1;
	if (input_values->A == true)
		input_values->y -= 1;
	if (input_values->D == true)
		input_values->y += 1;
	ft_cub3d_render_next_img(vars, input_values->x, input_values->y);
}

void	ft_cub3d_reset_input(t_input *input_values)
{
	input_values->W = false;
	input_values->A = false;
	input_values->S = false;
	input_values->D = false;
	input_values->LEFT = false;
	input_values->RIGHT = false;
}

int		ft_cub3d_invalid_input(int keycode, t_vars *vars, t_input *input_values)
{
	input_values->OTHER = true;
	printf("keycode %d does nothing!\n", keycode);
	(void)vars;
	return (0);
}
