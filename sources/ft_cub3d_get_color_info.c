/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cub3d_get_color_info.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjourdan <jjourdan@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/27 10:31:56 by jjourdan          #+#    #+#             */
/*   Updated: 2021/02/02 10:05:44 by jjourdan         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

int		ft_cub3d_create_trgb(int t, \
							int r, \
							int g, \
							int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

int		ft_cub3d_get_t(int trgb)
{
	return (trgb & (0xFF << 24));
}

int		ft_cub3d_get_r(int trgb)
{
	return (trgb & (0xFF << 16));
}

int		ft_cub3d_get_g(int trgb)
{
	return (trgb & (0xFF << 8));
}

int		ft_cub3d_get_b(int trgb)
{
	return (trgb & 0xFF);
}
