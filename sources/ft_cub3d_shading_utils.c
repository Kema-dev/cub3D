/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cub3d_shading_utils.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjourdan <jjourdan@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/27 11:00:01 by jjourdan          #+#    #+#             */
/*   Updated: 2021/01/27 11:22:42 by jjourdan         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		ft_cub3d_add_shading(int trgb, int t)
{
	return(t << 24 | trgb);
}

int		ft_cub3d_add_shading_from_distance(int trgb, double distance)
{
	int	shading_value;

	shading_value = distance * 255;
	return (ft_cub3d_add_shading(trgb, shading_value));
}
