/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cub3d_initial_checks.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjourdan <jjourdan@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/02 12:23:13 by jjourdan          #+#    #+#             */
/*   Updated: 2021/02/15 14:17:58 by jjourdan         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int							ft_cub3d_print_errno(int error_no)
{
	char	*strings[18];

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
	strings[14] = "YOUR SPECIFIED MAP IS A DIRECTORY!";
	strings[15] = "MAP SPLIT FAILED!";
	strings[16] = "MAP CONTAINS NO STARTING POSITION!";
	strings[17] = "YOU KILLED ME D:";
	printf("Error\n%s\n", strings[error_no]);
	return (error_no);
}

int							ft_cub3d_check_arg(int argc,\
												char **argv, \
												bool *save)
{
	if ((argc <= 1) || (argc >= 4))
		return (INVALID_ARG_NUM);
	if (argv[2])
	{
		if (ft_strncmp(argv[2], "--save", 7) != SUCCESS)
			return (INVALID_ARG);
		else
			*save = true;
	}
	if (ft_strlen(argv[1]) <= 4)
		return (MAP_INVALID_EXT);
	if (ft_strncmp(argv[1] + ft_strlen(argv[1]) - 4, ".cub", 4) != SUCCESS)
		return (MAP_INVALID_EXT);
	return (SUCCESS);
}

int							ft_cub3d_check_map_is_dir(char *map_path)
{
	int		fd;

	if ((fd = open(map_path, O_DIRECTORY)) >= 0)
	{
		close(fd);
		return (MAP_IS_DIR);
	}
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

int							ft_cub3d_start_is_charset(t_map_params \
												*map_params, \
												ssize_t i, \
												ssize_t j, \
												char *charset)
{
	ssize_t	k;

	k = -1;
	while (charset[++k])
	{
		if (map_params->map[i][j] == charset[k])
		{
			if (map_params->orientation == 0)
			{
				map_params->orientation = charset[k];
				map_params->starting_pos_x = j;
				map_params->starting_pos_y = i;
			}
			else
				return (MAP_INVALID_POS);
		}
	}
	return (SUCCESS);
}
