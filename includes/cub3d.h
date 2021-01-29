/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjourdan <jjourdan@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/27 10:37:22 by jjourdan          #+#    #+#             */
/*   Updated: 2021/01/29 17:05:57 by jjourdan         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef _CUB3D_H
# define _CUB3D_H

# include "get_next_line.h"
# include "libft.h"
# include <sys/types.h>
# include <stdio.h>
# include <mlx.h>
# include <stdbool.h>

# define RED				0x00FF0000
# define GREEN				0x0000FF00
# define BLUE				0x000000FF

# define W_KEY				13
# define A_KEY				0
# define S_KEY				1
# define D_KEY				2
# define ESC_KEY			53
# define LEFT_ARROW_KEY		123
# define RIGHT_ARROW_KEY	124

typedef struct	s_data {
	void		*img;
	char		*addr;
	int			bits_per_pixel;
	int			line_length;
	int			endian;
}				t_data;

typedef struct	s_vars {
	void		*mlx;
	void		*win;
}				t_vars;

typedef struct	s_input {
	bool		W;
	bool		A;
	bool		S;
	bool		D;
	bool		RIGHT;
	bool		LEFT;
	int			OTHER;
	int			x;
	int			y;
}				t_input;

/*
** get_color_info
*/

int				ft_cub3d_create_trgb(int t, int r, int g, int b);
int				ft_cub3d_get_t(int trgb);
int				ft_cub3d_get_r(int trgb);
int				ft_cub3d_get_g(int trgb);
int				ft_cub3d_get_b(int trgb);

/*
** shading_utils
*/

int				ft_cub3d_add_shading(int trgb, int t);
int				ft_cub3d_add_shading_from_distance(int trgb, double distance);

/*
** pixel_manipulation
*/

void			ft_cub3d_pixel_put(t_data *data, int x, int y, int color);

/*
** key_events
*/

int				ft_cub3d_check_key_event(int keycode, t_vars *vars, t_input *input_values);
int				ft_cub3d_invalid_input(int keycode, t_vars *vars, t_input *input_values);
void			ft_cub3d_reset_input(t_input *input_values);
void			ft_cub3d_treat_input(t_vars *vars, t_input *input_values);

/*
** kill_process
*/

int				ft_cub3d_kill_all(t_vars *vars);

/*
** image_creation
*/

t_data ft_cub3d_render_next_img(t_vars *vars, int x, int y);

#endif
