/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cub3d_exit_process.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjourdan <jjourdan@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/27 14:01:00 by jjourdan          #+#    #+#             */
/*   Updated: 2021/02/15 14:53:48 by jjourdan         ###   ########lyon.fr   */
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

int					ft_cub3d_exit(void)
{
	printf("%s\n", "YOU KILLED ME D:");
	exit(SUCCESS);
}
