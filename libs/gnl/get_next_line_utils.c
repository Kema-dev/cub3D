/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjourdan <jjourdan@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/01 13:36:50 by jjourdan          #+#    #+#             */
/*   Updated: 2021/01/26 14:32:07 by jjourdan         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_gnl_strlen(const char *s)
{
	size_t i;

	if (!s)
		return (0);
	i = 0;
	while (s[i] != 0)
		i++;
	return (i);
}

char	*ft_gnl_strcat(char *dest, const char *src, size_t i)
{
	size_t j;

	j = 0;
	if (!src)
		return ((char *)dest);
	if (!dest)
		return (NULL);
	while (src[j] != 0)
	{
		dest[i] = src[j];
		j++;
		i++;
	}
	dest[i] = 0;
	return (dest);
}

char	*ft_gnl_strjoin(char *s1, char *s2)
{
	size_t	i;
	size_t	tot_len;
	char	*out;

	if (!s2)
		return ((char *)s1);
	i = ft_gnl_strlen(s1);
	tot_len = i + ft_gnl_strlen(s2);
	if (!(out = malloc(sizeof(char) * (tot_len + 1))))
		return (NULL);
	*out = 0;
	ft_gnl_strcat(out, (char *)s1, 0);
	ft_gnl_strcat(out, (char *)s2, i);
	out[tot_len] = 0;
	free(s1);
	return (out);
}

int		ft_gnl_new_line(char *save)
{
	size_t i;

	i = 0;
	if (!save)
		return (-1);
	while (save[i] != 0)
	{
		if (save[i] == '\n')
			return (0);
		i++;
	}
	return (-1);
}
