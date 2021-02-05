/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cub3d_initial_checks.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjourdan <jjourdan@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/02 12:23:13 by jjourdan          #+#    #+#             */
/*   Updated: 2021/02/05 10:29:28 by jjourdan         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int							ft_cub3d_print_errno(int error_no)
{
	char	*strings[14];

	strings[0] = "SUCCESS";
	strings[1] = "FAILURE";
	strings[2] = "MALLOC FAILED!";
	strings[3] = "WRONG NUMBER OF ARGUMENTS! MUST BE '*.cub' OR '*.cub --save'";
	strings[4] = "INVALID ARGUMENT! MUST BE '*.cub' OR '*.cub --save'";
	strings[5] = "MAP IS NOT CLOSED!";
	strings[6] = "MAP CONTAINS AN INVALID CHAR!";
	strings[7] = "MAP HAS INVALID PARAMETERS!";
	strings[8] = "MAP PATH IS NOT REACHABLE!";
	strings[9] = "INVALID COLOR!";
	strings[10] = "MAP IS NOT ENDING WITH '.cub'!";
	strings[11] = "MAP CONTAINS INVALID STARTING POSITION!";
	strings[12] = "GOT AN INVALID READ ON MAP!";
	strings[13] = "REQUESTED RESOLUTION IS INVALID!";
	printf("Error\n%s\n", strings[error_no]);
	return (error_no);
}

int							ft_cub3d_check_arg(int argc,\
												char **argv, \
												int *save)
{
	if ((argc <= 1) || (argc >= 4))
		return (INVALID_ARG_NUM);
	if (argv[2])
	{
		if (ft_strncmp(argv[2], "--save", 7) != SUCCESS)
			return (INVALID_ARG);
		else
			*save = 1;
	}
	if (ft_strlen(argv[1]) <= 4)
		return (MAP_INVALID_EXT);
	if (ft_strncmp(argv[1] + ft_strlen(argv[1]) - 4, ".cub", 4) != SUCCESS)
		return (MAP_INVALID_EXT);
	return (SUCCESS);
}

int							ft_cub3d_check_map(char *map_path, \
												t_map_params *map_params, \
												char *map_lines)
{
	int		fd;
	int		return_value;
	char	*buf;

	return_value = 0;
	if ((fd = open(map_path, O_RDONLY)) < 0)
		return (MAP_INVALID_PATH);
	while ((return_value = get_next_line(fd, &buf)) > 0)
	{
		if (buf[0] != 0)
		{
			map_lines = ft_strjoin_free_s1(map_lines, buf);
			map_lines = ft_strjoin_free_s1(map_lines, "\n");
		}
		free(buf);
	}
	map_lines = ft_strjoin_free_s1(map_lines, buf);
	free(buf);
	if (return_value < 0)
		return (MAP_INVALID_READ);
	close(fd);
	if ((return_value = ft_cub3d_get_map_params(map_params, \
												map_lines)) != SUCCESS)
		return (return_value);
	return (SUCCESS);
}

/*
** MAP SAMPLE
**
** R 1280 720
** NO ./textures/bookshelf.xpm
** SO ./textures/cracked_stone_bricks.xpm
** WE ./textures/piston_top.xpm
** EA ./textures/purplestone.xpm
** S ./textures/barrel.xpm
** F 155,62,62
** C 51,204,255
**
** 1111111111111111111111111111111111
** 1000000000010202020100000111110111
** 1000000000010000000100000000000001
** 1000101000010202020111111100000001
** 10001010000100000001000000000000001
** 1000101000011100111111111110111111
** 120000W0002000000001      101
** 10002000000000000021111111101
** 100000000000000020000000000001
** 100000200000000000211111111111
** 11111111111111111111
*/
