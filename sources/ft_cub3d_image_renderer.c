/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cub3d_image_renderer.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjourdan <jjourdan@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/09 11:14:55 by jjourdan          #+#    #+#             */
/*   Updated: 2021/02/09 13:23:56 by jjourdan         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int							ft_cub3d_save_file(t_map_params *map_params)
{
	(void)map_params;
	return (SUCCESS);
}

int							ft_cub3d_launch_game(t_map_params *map_params)
{
	(void)map_params;
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
