/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cub3d_misc.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjourdan <jjourdan@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/09 10:35:20 by jjourdan          #+#    #+#             */
/*   Updated: 2021/02/18 12:10:39 by jjourdan         ###   ########lyon.fr   */
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
		data->texture[data->tex_val.dir].cols + data->tex_val.x *\
		(data->texture[data->tex_val.dir].bits_per_pixel) / 8];
	data->addr[*y * data->line_length + x *\
			(data->bits_per_pixel) / 8 + 1] =
		data->texture[data->tex_val.dir].addr[data->tex_val.y *\
		data->texture[data->tex_val.dir].cols + data->tex_val.x *\
		(data->texture[data->tex_val.dir].bits_per_pixel) / 8 + 1];
	data->addr[*y * data->line_length + x *\
			(data->bits_per_pixel) / 8 + 2] =
		data->texture[data->tex_val.dir].addr[data->tex_val.y *\
		data->texture[data->tex_val.dir].cols + data->tex_val.x *\
		(data->texture[data->tex_val.dir].bits_per_pixel) / 8 + 2];
	data->addr[*y * data->line_length + x *\
			(data->bits_per_pixel) / 8 + 3] =
		data->texture[data->tex_val.dir].addr[data->tex_val.y *\
		data->texture[data->tex_val.dir].cols + data->tex_val.x *\
		(data->texture[data->tex_val.dir].bits_per_pixel) / 8 + 3];
}

int							ft_cub3d_parse_text_infos(t_data *data, \
													int fd, int i)
{
	char	*str;
	int		j;

	j = -1;
	while (++j < 4)
		get_next_line(fd, &str);
	while ((str[0] > '9') || (str[0] < '0'))
		str++;
	data->texture[i].cols = ft_atoi(str);
	ft_cub3d_pass_digit(&str);
	data->texture[i].rows = ft_atoi(str);
	ft_cub3d_pass_digit(&str);
	data->texture[i].colors = ft_atoi(str);
	ft_cub3d_pass_digit(&str);
	data->texture[i].bits_per_pixel = ft_atoi(str);
	j = 0;
	if (!(data->texture[i].line = ft_calloc(data->texture[i].rows, \
					sizeof(data->texture[i].line))))
		return (MALLOC_FAIL);
	while ((get_next_line(fd, &str) != 0) && (j < data->texture[i].rows))
		data->texture[i].line[j++] = str;
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
	ft_cub3d_parse_text_infos(data, fd, ++i);
	if ((fd = ft_cub3d_check_map_is_dir(data->map_params->south_text)) < 0)
		return (TEXT_FAILURE);
	ft_cub3d_parse_text_infos(data, fd, ++i);
	close(fd);
	if ((fd = ft_cub3d_check_map_is_dir(data->map_params->east_text)) < 0)
		return (TEXT_FAILURE);
	ft_cub3d_parse_text_infos(data, fd, ++i);
	close(fd);
	if ((fd = ft_cub3d_check_map_is_dir(data->map_params->west_text)) < 0)
		return (TEXT_FAILURE);
	ft_cub3d_parse_text_infos(data, fd, ++i);
	close(fd);
	if ((fd = ft_cub3d_check_map_is_dir(data->map_params->sprite_text)) < 0)
		return (TEXT_FAILURE);
	ft_cub3d_parse_text_infos(data, fd, ++i);
	close(fd);
	return (SUCCESS);
}
