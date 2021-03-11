/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cub3d_misc.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjourdan <jjourdan@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/09 10:35:20 by jjourdan          #+#    #+#             */
/*   Updated: 2021/03/11 15:50:56 by jjourdan         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void						ft_cub3d_print_map_params(t_map_params *map_params)
{
	printf("\nres width            :%d:\n", map_params->res_width);
	printf("res height           :%d:\n", map_params->res_height);
	printf("north texture path   :%s:\n", map_params->north_text);
	printf("south texture path   :%s:\n", map_params->south_text);
	printf("east texture path    :%s:\n", map_params->east_text);
	printf("west texture path    :%s:\n", map_params->west_text);
	printf("sprite texture path  :%s:\n", map_params->sprite_text);
	printf("floor col            :%d:\n", map_params->floor_color);
	printf("ceiling col          :%d:\n", map_params->ceiling_color);
	printf("propermap\n:%s:\n", map_params->field);
}

int							ft_cub3d_exit(void)
{
	printf("\n%s\n", "YOU KILLED ME D:");
	printf("uptime : %zu sec\n", clock() / CLOCKS_PER_SEC);
	exit(SUCCESS);
}

unsigned long				ft_cub3d_create_rgb_3(int r, int g, int b)
{
	return ((r & 0xff) << 16) + ((g & 0xff) << 8) + (b & 0xff);
}

int							ft_cub3d_print_errno(int error_no)
{
	char	*strings[22];

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
	strings[18] = "TEXTURE LOADING FAILED!";
	strings[19] = "BMP FILE CREATION FAILED!";
	strings[20] = "DOUBLE PARAMETER DEFINITION!";
	strings[21] = "MISSING PARAMETER!";
	printf("Error\n%s\n", strings[error_no]);
	return (error_no);
}
