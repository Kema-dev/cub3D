/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cub3d_initial_checks.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjourdan <jjourdan@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/02 12:23:13 by jjourdan          #+#    #+#             */
/*   Updated: 2021/02/03 13:27:34 by jjourdan         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int							ft_cub3d_print_errno(int error_no)
{
	char	*strings[12];

	strings[0] = "SUCCESS";
	strings[1] = "FAILURE";
	strings[2] = "MALLOC FAILED!";
	strings[3] = "WRONG NUMBER OF ARGUMENTS! MUST BE '*.cub' OR '*.cub --save'";
	strings[4] = "INVALID ARGUMENT! MUST BE '*.cub' OR '*.cub --save'";
	strings[5] = "MAP IS NOT CLOSED!";
	strings[6] = "MAP CONTAINS AN INVALID CHAR!";
	strings[7] = "MAP IS NOT SORTED PROPERLY!";
	strings[8] = "MAP PATH IS NOT REACHABLE!";
	strings[9] = "INVALID COLOR!";
	strings[10] = "MAP IS NOT ENDING WITH '.cub'!";
	strings[11] = "MAP CONTAINS INVALID STARTING POSITION!";
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
	int		ret;
	char	*buf;

	ret = 0;
	if ((fd = open(map_path, O_RDONLY)) < 0)
		return (MAP_INVALID_PATH);
	while ((ret = get_next_line(fd, &buf)) > 0)
	{
		if (buf[0] != 0)
		{
			map_lines = ft_strjoin(map_lines, buf);
			map_lines = ft_strjoin(map_lines, "\n");
		}
	}
	if (ret < 0)
		return (MAP_INVALID_READ);
	close(fd);
	ft_cub3d_get_map_params(map_params, map_lines);
	(void)map_params;
	return (SUCCESS);
}