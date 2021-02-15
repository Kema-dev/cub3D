/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjourdan <jjourdan@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/27 10:37:22 by jjourdan          #+#    #+#             */
/*   Updated: 2021/02/15 16:07:19 by jjourdan         ###   ########lyon.fr   */
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
# include <math.h>
# include <time.h>

/*
** colors
*/

# define RED					0x00FF0000
# define GREEN					0x0000FF00
# define BLUE					0x000000FF

/*
** keys
*/

# define W_KEY					13
# define A_KEY					0
# define S_KEY					1
# define D_KEY					2
# define ESC_KEY				53
# define LEFT_ARROW_KEY			123
# define RIGHT_ARROW_KEY		124

/*
** return values
*/

# define EXIT					-2
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
# define MLX_INIT_FAIL			17

/*
** GNL
*/

# define BUFFER_SIZE		16

typedef struct				s_input {
	bool					w;
	bool					a;
	bool					s;
	bool					d;
	bool					right;
	bool					left;
	int						other;
	size_t					x;
	size_t					y;
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

typedef struct				s_data {
	void					*img;
	char					*addr;
	int						bits_per_pixel;
	int						line_length;
	int						endian;
	void					*mlx;
	void					*mlx_win;
	clock_t					time;
	clock_t					prev_time;
	float					frame_rate;
	double					pos_x;
	double					pos_y;
	double					dir_x;
	double					dir_y;
	double					plane_x;
	double					plane_y;
	double					camera_x;
	double					camera_y;
	double					ray_dir_x;
	double					ray_dir_y;
	double					map_x;
	double					map_y;
	double					side_dist_x;
	double					side_dist_y;
	double					delta_dist_x;
	double					delta_dist_y;
	double					perp_wall_dist;
	int						step_x;
	int						step_y;
	int						hit;
	int						side;
}							t_data;

/*
** initial_checks
*/

int							ft_cub3d_check_arg(int argc, \
												char **argv, \
												bool *save);
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
int							ft_cub3d_init_rgb(int *r, \
											int *g, \
											int *b);

/*
** parsing_utils
*/

int							ft_cub3d_go_next_word(char **str, \
													char sep, \
													char end);
char						*ft_cub3d_get_first_word(char **str, \
													char sep, \
													char end);
int							ft_cub3d_check_map_is_dir(char *map_path);
void						ft_cub3d_print_map_params(t_map_params *map_params);
int							ft_cub3d_pass_digit(char **str);
int							ft_cub3d_last_checks(char **tmp);
int							ft_cub3d_param_return(int return_value);
int							ft_cub3d_2d_map(t_map_params *map_params);
int							ft_cub3d_is_charset(char **map, char *charset);
int							ft_cub3d_get_starting_pos(t_map_params \
												*map_params, char *charset);
int							ft_cub3d_check_walls(t_map_params *map_params);
char						**ft_cub3d_get_test_map(char **map);
char						**ft_cub3d_fill_test_map(ssize_t nb_rows, \
													char **map, \
													char **test_map);
int							ft_cub3d_recursive_wall(char **test_map, \
													size_t x, \
													size_t y);
int							ft_cub3d_start_is_charset(t_map_params \
													*map_params, \
													ssize_t i, \
													ssize_t j, \
													char *charset);

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
** misc
*/

void						ft_cub3d_print_map(char **map);

/*
** key_events_manager
*/

int							ft_cub3d_check_key_event(int keycode, \
													t_data *data, \
													t_input *input_values, \
													t_map_params *map_params);
void						ft_cub3d_treat_input(t_data *data, \
												t_input *input_values, \
												t_map_params *map_params);
int							ft_cub3d_invalid_input(int keycode, \
												t_data *data, \
												t_input *input_values);

/*
** image_rendering
*/

int							ft_cub3d_exit(void);
int							ft_cub3d_render_next_img(t_data *data, \
										t_map_params *map_params);
int							ft_cub3d_launch_game(t_map_params *map_params);
int							ft_cub3d_save_file(t_map_params *map_params);

/*
** ray_casting
*/

int							ft_cub3d_cast_rays(t_data *data, \
											t_map_params *map_params);
int							ft_cub3d_init_player(t_data *data, \
											t_map_params *map_params);
int							ft_cub3d_init_walls(t_data *data, \
											t_map_params *map_params);

#endif
