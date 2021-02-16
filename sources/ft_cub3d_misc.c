/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cub3d_misc.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjourdan <jjourdan@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/09 10:35:20 by jjourdan          #+#    #+#             */
/*   Updated: 2021/02/16 14:41:55 by jjourdan         ###   ########lyon.fr   */
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

int							ft_cub3d_parse_text_infos(t_data *data, int fd, int i)
{
	char	*str;
	int		j;

	str = NULL;
	while (str[0] != '"')
	{
		if (str)
			free(str);
		str = get_next_line(fd, str)
	}
	while ((str[0] > '9') || (str[0] < '0'))
		str++;
	data->texture[i].col = ft_atoi(str);
	ft_cub3d_pass_digit(&str);
	data->texture[i].rows = ft_atoi(str);
	ft_cub3d_pass_digit(&str);
	data->texture[i].colors = ft_atoi(str);
	ft_cub3d_pass_digit(&str);
	data->texture[i].bits_per_pixel = ft_atoi(str);
	free(str);
	j = 0;
	while (get_next_line(fd, str) != 0)
	{
		if (data->line)
			free(data->line);
		if (!(data->line = ft_calloc(j + 1, sizeof(data->line))))
			return (MALLOC_FAIL);
		data->texture[i].line[j++] = str;
	}
	return (SUCCESS);
}

int							ft_cub3d_get_text_infos(t_data *data)
{
	int		fd;
	int		i;

	i = -1;
	if ((ft_check_map_is_dir(data->map_params->north_text)) \
		+ (ft_check_map_is_dir(data->map_params->south_text)) \
		+ (ft_check_map_is_dir(data->map_params->east_text)) \
		+ (ft_check_map_is_dir(data->map_params->west_text)) \
		+ (ft_check_map_is_dir(data->map_params->sprite_text)) != 0)
		return (TEXT_FAILURE);
	if ((fd = open(data->map_params->north_text)) < 0)
		return (TEXT_FAILURE);
	ft_cub3d_pars_text_infos(data, fd, ++i);
	if ((fd = open(data->map_params->south_text)) < 0)
		return (TEXT_FAILURE);
	ft_cub3d_pars_text_infos(data, fd, ++i);
	close(fd);
	if ((fd = open(data->map_params->east_text)) < 0)
		return (TEXT_FAILURE);
	ft_cub3d_pars_text_infos(data, fd, ++i);
	close(fd);
	if ((fd = open(data->map_params->west_text)) < 0)
		return (TEXT_FAILURE);
	ft_cub3d_pars_text_infos(data, fd, ++i);
	close(fd);
	if ((fd = open(data->map_params->sprite_text)) < 0)
		return (TEXT_FAILURE);
	ft_cub3d_pars_text_infos(data, fd, ++i);
	close(fd);
	return (SUCCESS);
}
