/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cub3d_main.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjourdan <jjourdan@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/26 13:32:58 by jjourdan          #+#    #+#             */
/*   Updated: 2021/02/09 14:46:15 by jjourdan         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int					main(int argc, char **argv)
{
	bool			save;
	int				return_value;
	char			*map_lines;
	t_map_params	*map_params;

	map_lines = NULL;
	save = false;
	if (!(map_params = ft_calloc(sizeof(t_map_params), 1)))
		return (MALLOC_FAIL);
	if ((return_value = ft_cub3d_check_arg(argc, argv, &save)) != SUCCESS)
		return (ft_cub3d_print_errno(return_value));
	if ((return_value = ft_cub3d_check_map(argv[1], map_params, \
											map_lines)) != SUCCESS)
		return (ft_cub3d_print_errno(return_value));
	if (save == true)
	{
		if ((return_value = (ft_cub3d_save_file(map_params)) != SUCCESS))
			return (return_value);
	}
	else
	{
		if ((return_value = (ft_cub3d_launch_game(map_params)) != SUCCESS))
			return (return_value);
	}
	return (ft_cub3d_exit_exec(return_value, map_params));
}
