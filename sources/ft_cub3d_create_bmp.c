/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cub3d_create_bmp.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjourdan <jjourdan@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/16 15:01:34 by jjourdan          #+#    #+#             */
/*   Updated: 2021/02/26 12:49:41 by jjourdan         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int							ft_cub3d_create_bmp(t_data *data)
{
	int				fd;
	t_bmp_header	bmp_header;

	if ((fd = open("image.bmp", O_CREAT, S_IRWXU) < 0))
		exit(ft_cub3d_print_errno(BMP_FAIL));
	if (!(bmp_header = ft_calloc(1, sizeof(bmp_header))))
		exit(ft_cub3d_print_errno(MALLOC_FAIL));
	return (SUCCESS);
}
