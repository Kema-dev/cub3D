/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjourdan <jjourdan@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/27 10:37:22 by jjourdan          #+#    #+#             */
/*   Updated: 2021/01/27 11:20:42 by jjourdan         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef _CUB3D_H
# define _CUB3D_H

# include "get_next_line.h"
# include "libft.h"
# include <mlx.h>

# define RED	0x00FF0000
# define GREEN	0x0000FF00
# define BLUE	0x000000FF

/*
** get_color_info
*/

int		ft_cub3d_create_trgb(int t, int r, int g, int b);
int		ft_cub3d_get_t(int trgb);
int		ft_cub3d_get_r(int trgb);
int		ft_cub3d_get_g(int trgb);
int		ft_cub3d_get_b(int trgb);

/*
** shading_utils
*/

int		ft_cub3d_add_shading(int trgb, int t);
int		ft_cub3d_add_shading_from_distance(int trgb, double distance);

#endif
