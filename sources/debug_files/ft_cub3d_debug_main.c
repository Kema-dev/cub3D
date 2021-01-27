/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cub3d_debug_main.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjourdan <jjourdan@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/26 15:58:19 by jjourdan          #+#    #+#             */
/*   Updated: 2021/01/27 13:30:08 by jjourdan         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include <sys/types.h>

int             ft_close(int keycode, t_vars *vars)
{
    printf("")
	return (0);
}

int             main(void)
{
    t_vars    vars;

    vars.mlx = mlx_init();
    vars.win = mlx_new_window(vars.mlx, 1920, 1080, "Hello world!");
    mlx_hook(vars.win, 2, 1L<<0, ft_close, &vars);
    mlx_loop(vars.mlx);
}

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
