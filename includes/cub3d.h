/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjourdan <jjourdan@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/27 10:37:22 by jjourdan          #+#    #+#             */
/*   Updated: 2021/02/05 15:28:09 by jjourdan         ###   ########lyon.fr   */
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

/*
** colors
*/

# define RED				0x00FF0000
# define GREEN				0x0000FF00
# define BLUE				0x000000FF

/*
** keys
*/

# define W_KEY				13
# define A_KEY				0
# define S_KEY				1
# define D_KEY				2
# define ESC_KEY			53
# define LEFT_ARROW_KEY		123
# define RIGHT_ARROW_KEY	124

/*
** return values
*/

# define PASS					-1
# define SUCCESS				0
# define FAILURE				1
# define MALLOC_FAIL			2
# define INVALID_ARG_NUM		3
# define INVALID_ARG			4
# define MAP_IS_OPEN			5
# define MAP_INVALID_CHAR		6
# define MAP_INVALID_CONFIG		7
# define MAP_INVALID_PATH		8
# define MAP_INVALID_COLOR		9
# define MAP_INVALID_EXT		10
# define MAP_INVALID_POS		11
# define MAP_INVALID_READ		12
# define MAP_INVALID_RES		13
# define MAP_IS_DIR				14
# define MAP_SPLIT_FAIL			15
# define MAP_NO_STARTING_POS	16

/*
** GNL
*/

# define BUFFER_SIZE		16

typedef struct				s_data {
	void					*img;
	char					*addr;
	int						bits_per_pixel;
	int						line_length;
	int						endian;
}							t_data;

typedef struct				s_vars {
	void					*mlx;
	void					*win;
}							t_vars;

typedef struct				s_input {
	bool					w;
	bool					a;
	bool					s;
	bool					d;
	bool					right;
	bool					left;
	int						other;
	int						x;
	int						y;
}							t_input;

typedef struct				s_map_params {
	size_t					res_width;
	size_t					res_height;
	char					*north_text;
	char					*south_text;
	char					*east_text;
	char					*west_text;
	char					*sprite_text;
	int						floor_color;
	int						ceiling_color;
	char					*field;
	char					**map;
	char					orientation;
	int						starting_pos_x;
	int						starting_pos_y;
}							t_map_params;

/*
** initial_checks
*/

int							ft_cub3d_check_arg(int argc, \
												char **argv, \
												int *save);
int							ft_cub3d_check_map(char *map_path, \
												t_map_params *map_params, \
												char *map_lines);
int							ft_cub3d_print_errno(int error_no);

int							ft_cub3d_get_map_params(t_map_params *map_params, \
												char *map_lines);
int							ft_cub3d_get_next_param(char **tmp, \
													t_map_params *map_params);
int							ft_cub3d_get_resolution(char **str, \
													t_map_params *map_params);
int							ft_cub3d_get_texture(char **str, \
													t_map_params *map_params);
int							ft_cub3d_get_plane(char **str, \
													t_map_params *map_params);
int							ft_cub3d_get_field(char **str, \
													t_map_params *map_params);

/*
** utils
*/

int							ft_cub3d_go_next_word(char **str, \
													char sep, \
													char end);
char						*ft_cub3d_get_first_word(char **str, \
													char sep, \
													char end);
void						ft_cub3d_print_map_params(t_map_params *map_params);
int							ft_cub3d_pass_digit(char **str);
int							ft_cub3d_last_checks(char **tmp);
int							ft_cub3d_param_return(int return_value);
int							ft_cub3d_exit_exec(int return_value, \
												t_map_params *map_params);
int							ft_cub3d_2d_map(t_map_params *map_params);
int							ft_cub3d_is_charset(char **map, char *charset);
int							ft_cub3d_get_starting_pos(t_map_params *map_params, \
														char *charset);
int							ft_cub3d_check_walls(t_map_params map_params, \
													char empty, \
													char wall, \
													char sprite);
char						**ft_cub3d_get_test_map(char **map);

/*
** get_color_info
*/

int							ft_cub3d_create_trgb(int t, \
												int r, \
												int g, \
												int b);
int							ft_cub3d_get_t(int trgb);
int							ft_cub3d_get_r(int trgb);
int							ft_cub3d_get_g(int trgb);
int							ft_cub3d_get_b(int trgb);

/*
** shading_utils
*/

int							ft_cub3d_add_shading(int trgb, \
												int t);
int							ft_cub3d_add_shading_from_distance(int trgb, \
															double distance);

/*
** pixel_manipulation
*/

void						ft_cub3d_pixel_put(t_data *data, \
											int x, \
											int y, \
											int color);

/*
** key_events
*/

int							ft_cub3d_check_key_event(int keycode, \
													t_vars *vars, \
													t_input *input_values);
int							ft_cub3d_invalid_input(int keycode, \
													t_vars *vars, \
													t_input *input_values);
void						ft_cub3d_reset_input(t_input *input_values);
void						ft_cub3d_treat_input(t_vars *vars, \
													t_input *input_values);

/*
** kill_process
*/

int							ft_cub3d_kill_all(t_vars *vars);

/*
** image_creation
*/

t_data						ft_cub3d_render_next_img(t_vars *vars, \
											int x, \
											int y);

#endif
