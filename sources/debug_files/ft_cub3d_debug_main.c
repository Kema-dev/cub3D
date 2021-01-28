/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cub3d_debug_main.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjourdan <jjourdan@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/26 15:58:19 by jjourdan          #+#    #+#             */
/*   Updated: 2021/01/28 13:05:01 by jjourdan         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int             main(void)
{
    t_vars    vars;
    t_input   *input_values;

	if (!(input_values = malloc(sizeof(t_input))))
		return (-1);
    vars.mlx = mlx_init();
    vars.win = mlx_new_window(vars.mlx, 1920, 1080, "Hello world!");
	mlx_hook(vars.win, 2, 1L<<0, ft_cub3d_check_key_event, &vars);
    mlx_hook(vars.win, 17, 10001, ft_cub3d_kill_all, &vars);
    mlx_loop(vars.mlx);
	return (0);
}
// ! 17, 10001 for redcross
/*
** add_shading
** int	main(void)
** {
** 	int	test = RED;
** 
** 	printf("base=%.8X\n", test);
** 	test = ft_cub3d_add_shading_from_distance(test, 0);
** 	printf("func=%.8X\n", test);
** }
*/
