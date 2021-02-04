/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cub3d_word_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjourdan <jjourdan@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/04 12:33:55 by jjourdan          #+#    #+#             */
/*   Updated: 2021/02/04 13:15:32 by jjourdan         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		ft_cub3d_go_next_word(char **str, char sep, char end)
{
	while ((*str[0] != 0) && (*str[0] != sep) && (*str[0] != end))
		(*str) += 1;
	if (*str[0] == 0)
		return (-1);
	else if (*str[0] == end)
	{
		while (*str[0] == end)
			(*str) += 1;
		return (1);
	}
	while (*str[0] == sep)
		(*str) += 1;
	return (0);
}
