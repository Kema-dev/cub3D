/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cub3d_image_renderer.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjourdan <jjourdan@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/09 11:14:55 by jjourdan          #+#    #+#             */
/*   Updated: 2021/02/12 15:47:05 by jjourdan         ###   ########lyon.fr   */
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
	t_vars		vars;

	vars.mlx = mlx_init();
	sleep(-1);
	(void)map_params;
	return (SUCCESS);
}
