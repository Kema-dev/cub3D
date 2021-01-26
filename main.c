/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjourdan <jjourdan@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/26 13:32:58 by jjourdan          #+#    #+#             */
/*   Updated: 2021/01/26 14:45:18 by jjourdan         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"
#include "stdio.h"
#include "sys/types.h"

int	main(void)
{
	void *wind = mlx_init();
	mlx_new_window(wind, 800, 800, "TEST");
	return (0);
}
