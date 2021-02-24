/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cub3d_misc.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjourdan <jjourdan@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/09 10:35:20 by jjourdan          #+#    #+#             */
/*   Updated: 2021/02/24 12:36:33 by jjourdan         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void						ft_cub3d_print_map_params(t_map_params *map_params)
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

void						ft_cub3d_swap_addr(t_data *data, int x, ssize_t *y)
{
	data->addr[*y * data->line_length + x *\
			(data->bits_per_pixel) / 8] =
		data->texture[data->tex_val.dir].addr[data->tex_val.y *\
		data->texture[data->tex_val.dir].x + data->tex_val.x *\
		(data->texture[data->tex_val.dir].bits_per_pixel) / 8];
	data->addr[*y * data->line_length + x *\
			(data->bits_per_pixel) / 8 + 1] =
		data->texture[data->tex_val.dir].addr[data->tex_val.y *\
		data->texture[data->tex_val.dir].x + data->tex_val.x *\
		(data->texture[data->tex_val.dir].bits_per_pixel) / 8 + 1];
	data->addr[*y * data->line_length + x *\
			(data->bits_per_pixel) / 8 + 2] =
		data->texture[data->tex_val.dir].addr[data->tex_val.y *\
		data->texture[data->tex_val.dir].x + data->tex_val.x *\
		(data->texture[data->tex_val.dir].bits_per_pixel) / 8 + 2];
	data->addr[*y * data->line_length + x *\
			(data->bits_per_pixel) / 8 + 3] =
		data->texture[data->tex_val.dir].addr[data->tex_val.y *\
		data->texture[data->tex_val.dir].x + data->tex_val.x *\
		(data->texture[data->tex_val.dir].bits_per_pixel) / 8 + 3];
}

int							ft_cub3d_init_text_infos(t_data *data)
{
	int		fd;
	int		i;

	i = -1;
	while (++i < 5)
	{
		data->texture[i].x = 0;
		data->texture[i].y = 0;
		data->texture[i].bits_per_pixel = 0;
	}
	if ((fd = open(data->map_params->north_text, O_RDONLY)) < 0)
		return (TEXT_FAILURE);
	close(fd);
	if ((fd = open(data->map_params->south_text, O_RDONLY)) < 0)
		return (TEXT_FAILURE);
	close(fd);
	if ((fd = open(data->map_params->east_text, O_RDONLY)) < 0)
		return (TEXT_FAILURE);
	close(fd);
	if ((fd = open(data->map_params->west_text, O_RDONLY)) < 0)
		return (TEXT_FAILURE);
	close(fd);
	if ((fd = open(data->map_params->sprite_text, O_RDONLY)) < 0)
		return (TEXT_FAILURE);
	close(fd);
	return (SUCCESS);
}

int							ft_cub3d_get_text_infos(t_data *data)
{
	int		fd;
	int		i;

	i = -1;
	if ((fd = ft_cub3d_check_map_is_dir(data->map_params->north_text)) < 0)
		return (TEXT_FAILURE);
	close(fd);
	if ((fd = ft_cub3d_check_map_is_dir(data->map_params->south_text)) < 0)
		return (TEXT_FAILURE);
	close(fd);
	if ((fd = ft_cub3d_check_map_is_dir(data->map_params->east_text)) < 0)
		return (TEXT_FAILURE);
	close(fd);
	if ((fd = ft_cub3d_check_map_is_dir(data->map_params->west_text)) < 0)
		return (TEXT_FAILURE);
	close(fd);
	if ((fd = ft_cub3d_check_map_is_dir(data->map_params->sprite_text)) < 0)
		return (TEXT_FAILURE);
	close(fd);
	ft_cub3d_init_text_infos(data);
	return (SUCCESS);
}
