/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cub3d_exit_process.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjourdan <jjourdan@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/27 14:01:00 by jjourdan          #+#    #+#             */
/*   Updated: 2021/03/02 11:15:42 by jjourdan         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int					ft_cub3d_exit(void)
{
	printf("\n%s\n", "YOU KILLED ME D:");
	printf("uptime : %zu sec\n", clock() / CLOCKS_PER_SEC);
	exit(SUCCESS);
}
