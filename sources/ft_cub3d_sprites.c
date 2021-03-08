/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cub3d_sprites.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjourdan <jjourdan@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/08 14:05:16 by jjourdan          #+#    #+#             */
/*   Updated: 2021/03/08 16:42:00 by jjourdan         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_sprite					*ft_cub3d_init_sprites(t_data *data)
{
	ssize_t		i;
	ssize_t		j;
	t_sprite	*sprite;

	if (!(sprite = ft_calloc(1, sizeof(t_sprite))))
		exit(ft_cub3d_print_errno(MALLOC_FAIL));
	i = -1;
	while (data->map_params->map[++i])
	{
		j = -1;
		while (data->map_params->map[i][++j])
		{
			if (data->map_params->map[i][j] == '2')
				sprite->count++;
		}
	}
	if (!(sprite->order = ft_calloc(sprite->count, sizeof(int))))
		exit(ft_cub3d_print_errno(MALLOC_FAIL));
	if (!(sprite->z_buffer = ft_calloc(sprite->count, sizeof(double))))
		exit(ft_cub3d_print_errno(MALLOC_FAIL));
	if (!(sprite->dist = ft_calloc(sprite->count, sizeof(double))))
		exit(ft_cub3d_print_errno(MALLOC_FAIL));
	if (!(sprite->coord = ft_calloc(sprite->count, sizeof(t_coord))))
		exit(ft_cub3d_print_errno(MALLOC_FAIL));
	ft_cub3d_fill_sprites(data, sprite);
	return (sprite);
}

void						ft_cub3d_fill_sprites(t_data *data, t_sprite *sprite)
{
	ssize_t	i;
	ssize_t	j;
	ssize_t	k;

	i = 0;
	k = 0;
	while (data->map_params->map[++i])
	{
		j = -1;
		while (data->map_params->map[i][++j])
		{
			if (data->map_params->map[i][j] == '2')
			{
				sprite->coord[k].y = (double)i + 0.5;
				sprite->coord[k].x = (double)j + 0.5;
				k++;
			}
		}
	}
}

static void					ft_cub3d_swap_array(t_sprite *sprite, ssize_t i)
{
	double	tmp;
	tmp = sprite->dist[i];
	sprite->dist[i] = sprite->dist[i + 1];
	sprite->dist[i + 1] = tmp;
}

void						ft_cub3d_sort_sprites(t_data *data, t_sprite *sprite)
{
	ssize_t	i;
	i = -1;
	while (++i < (ssize_t)sprite->count)
	{
		sprite->order[i] = (int)i;
		sprite->dist[i] = ((data->pos_x - sprite->coord[i].x) * (data->pos_x \
				- sprite->coord[i].x) + (data->pos_y - sprite->coord[i].y) \
				* (data->pos_y - sprite->coord[i].y));
	}
	i = -1;
	while (++i < (ssize_t)sprite->count - 1)
	{
		if (sprite->dist[i] > sprite->dist[i + 1])
		{
			ft_cub3d_swap_array(sprite, i);
			i -= 2;
		}
	}
	i = -1;
}
