/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cub3d_key_events_manager.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjourdan <jjourdan@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/27 13:04:01 by jjourdan          #+#    #+#             */
/*   Updated: 2021/01/27 14:17:12 by jjourdan         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_cub3d_check_key_event(int keycode, t_vars *vars)
{
	if (keycode == 53)
		ft_cub3d_kill_all(vars);
	return (0);
}

int	ft_cub3d_print_key_code(int keycode, t_vars *vars)
{
	printf("kc=%d\n", keycode);
	(void)vars;
	return (0);
}
