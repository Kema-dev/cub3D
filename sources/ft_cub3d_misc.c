/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cub3d_misc.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjourdan <jjourdan@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/09 10:35:20 by jjourdan          #+#    #+#             */
/*   Updated: 2021/02/09 13:53:14 by jjourdan         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int					ft_cub3d_exit_exec(int return_value, \
										t_map_params *map_params)
{
	ssize_t	i;

	i = -1;
	free(map_params->north_text);
	free(map_params->south_text);
	free(map_params->east_text);
	free(map_params->west_text);
	free(map_params->sprite_text);
	free(map_params->field);
	while (map_params->map[++i])
		free(map_params->map[i]);
	free(map_params->map);
	free(map_params);
	return (return_value);
}

void				ft_cub3d_print_map_params(t_map_params *map_params)
{
	printf("\nres width            :%zu:\n", map_params->res_width);
	printf("res height           :%zu:\n", map_params->res_height);
	printf("north texture path   :%s:\n", map_params->north_text);
	printf("south texture path   :%s:\n", map_params->south_text);
	printf("east texture path    :%s:\n", map_params->east_text);
	printf("west texture path    :%s:\n", map_params->west_text);
	printf("sprite texture path  :%s:\n", map_params->sprite_text);
	printf("floor col            :%d:\n", map_params->floor_color);
	printf("ceiling col          :%d:\n", map_params->ceiling_color);
	printf("propermap\n:%s:\n", map_params->field);
}

int					ft_cub3d_init_rgb(int *r, int *g, int *b)
{
	*r = 0;
	*g = 0;
	*b = 0;
	return (SUCCESS);
}
