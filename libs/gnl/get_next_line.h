/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjourdan <jjourdan@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/01 13:35:49 by jjourdan          #+#    #+#             */
/*   Updated: 2020/12/20 23:14:12 by jjourdan         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>

char	*ft_get_save(char *save);
char	*ft_get_line(char *save);
int		get_next_line(int fd, char **line);
void	*ft_memset(void *s, int c, size_t n);
size_t	ft_strlen(const char *s);
char	*ft_strcat(char *dest, const char *src, size_t i);
char	*ft_strjoin(char *s1, char *s2);
int		ft_new_line(char *save);

#endif
