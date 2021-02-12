/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cub3d_exit_process.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjourdan <jjourdan@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/27 14:01:00 by jjourdan          #+#    #+#             */
/*   Updated: 2021/02/12 15:16:06 by jjourdan         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		ft_cub3d_kill_all(t_vars vars)
{
	mlx_destroy_window(vars.mlx, vars.mlx_win);
	printf("%s\n", "YOU KILLED ME D:");
	return (EXIT);
}
