/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hai <hai@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 14:04:31 by hai               #+#    #+#             */
/*   Updated: 2025/01/29 11:28:30 by hai              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libs/libft/headers/libft.h"
#include <math.h>
#include <X11/X.h>
#include <X11/Xlib.h>
#include <X11/keysym.h>
#include <errno.h>
#include <fcntl.h>
#include <limits.h>
#include <mlx.h>
#include <stdbool.h>
// printf perror
#include <stdio.h>
// malloc free exit
#include <stdlib.h>
// open close read write
#include <unistd.h>
// strerror
#include <string.h>
// gettimeofday
#include <sys/time.h>
// Unit32
#include <stdint.h>
#include <png.h>

#define BLACK 0x000000 // Color for black cells
#define GREY  0xD3D3D3 // Color for grey cells
#define CELL_SIZE 8 // Size of each cell in pixels
#define WIN_WIDTH 960
#define WIN_HEIGHT 640
#define LIGHT_GREEN 0x90EE90 // Color light green
#define BLUE 0x0000FF // Color for ray
#define M_PI 3.14159265358979323846
#define CAMERA_FOV 66

typedef enum e_key_code
{
	CLOSE_KEY = 17,
	ESC = 65307,
	KEY_PRESS = 2,
	KEY_RELEASE = 3,
	UP = 65362,
	DOWN = 65364,
	LEFT = 65361,
	RIGHT = 65363,
	W = 119,
	A = 97,
	S = 115,
	D = 100
}			t_key_code;

typedef struct s_map
{
	char	*floor;
	char	*ceiling;
	int		floor_color;
	bool	floor_flag;
	bool	ceiling_flag;
	int		ceiling_color;
	char	**digit_map;
	char	**digit_map_copy;
	char	**full_map;
	int		digit_map_height;
	int		map_width;
	int		map_lines;
	char	*north;
	bool	north_flag;
	char	*south;
	bool	south_flag;
	char	*east;
	bool	east_flag;
	char	*west;
	bool	west_flag;
}			t_map;

typedef struct s_img
{
	void	*img;
	void	*img_addr;
	int		bpp;
	int		img_width;
	int		img_height;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}			t_img;

typedef struct s_ray
{
	double	ray_dir_x;
	double	ray_dir_y;
	double	side_dist_x;
	double	side_dist_y;
	double	delta_dist_x;
	double	delta_dist_y;
	int		step_x;
	int		step_y;
	int		map_x;
	int		map_y;
	int		hit;
	int		side;
	double	camera_x;
}			t_ray;

typedef struct s_keys
{
	bool	w;
	bool	a;
	bool	d;
	bool	s;
	bool	left;
	bool	right;
}	t_keys;

typedef struct s_player
{
	char	player_direction;
	double	player_x;
	double	player_y;
	double	player_dir_x;
	double	player_dir_y;
	double	player_speed;
	double	player_rot_speed;
	double	planex;
	double	planey;
	double	plane_length;
	double	angle;
	double	perp_dist;
	int		side;
}			t_player;

typedef struct s_texture
{
	double		wall_height;
	double		start;
	double		end;
	double		wall_x;
	int			tex_x;
	double		step;
	double		tex_pos;
	int			tex_y;
	uint32_t	color;
	int			tex_width;
	int			tex_height;
	uint32_t	**texture_array;
}				t_texture;
typedef struct s_cube
{
	void		*mlx;
	void		*win;
	t_img		*three_d_image;
	t_img		*map_image;
	long		oldtime;
	double		frametime;
	t_keys		keys;
	t_img		*texture_img;
	t_texture	*texture;
	t_ray		*ray;
	t_player	*player;
	t_map		*map;
}			t_cube;

// init images
void	start_game(t_cube *cube);
void	init_three_d_image(t_cube *cube);
void	init_map_image(t_cube *cube);
void	init_map(t_cube *cube);
void	init_ray(t_cube *cube);
void	init_player(t_cube *cube);
void	init_keys(t_cube *cube);
void	init_texture(t_cube *cube);
void	draw_image(t_cube *cube);
void	fill_pixel(double x, double y, int color, t_img *img);
void	draw_cell(t_cube *cube, int x, int y, int color);
void	renew_display(t_cube *cube);
void	dda_cast_ray(t_cube *cube);
void	draw_background(t_cube *cube);
void	draw_map(t_cube *cube);
void	find_wall(t_cube *cube, int i);
void	calculate_delta_dist(t_cube *cube);
void	draw_ray_on_map(t_cube *cube);
void	put_texture_to_wall(t_cube *cube, int x);
void	side_dist_x_y(t_cube *cube);
void	calculate_player_perp_dist(t_cube *cube);
void	check_wall_hit(t_cube *cube);
void	detect_side(t_cube *cube, int *tex_num);
void	fill_pixel_to_wall(t_cube *cube, int x, int tex_num);

//parse
void	init_cube_data(t_cube *cube);
void	get_map_data(t_cube *cube, char *argv);
void	parse_map(t_cube *cube, char *argv);
void	file_open_error(t_cube *cube, int fd);
void	dir_parse(t_cube *cube);
void	get_map_data(t_cube *cube, char *argv);
int		get_map_lines(t_cube *cube, int fd);
void	get_map_width(t_cube *cube);
void	read_full_map(t_cube *cube, char *argv);
void	digit_map_parse(t_cube *cube, int start_line);
void	copy_map_line_dir(t_cube *cube, char *line_copy, char *s);
void	parse_map_struct(t_cube *cube, char *line_copy);
void	search_player(t_cube *cube, char **map);
void	check_direction(t_cube *cube, char c);
void	check_direction_cal(t_cube *cube);
void	convert_cf_rgb(t_cube *cube, char *str, char *s);
void	free_split(char **split);
void	parse_map_struct_2(t_cube *cube, char *line_copy);
void	copy_map_line_dir_2(t_cube *cube, char *line_copy, char *s);
void	discard_empty_line(t_cube *cube);

//load texture
void	convert_color_to_buffer(t_cube *cube, int i);
void	load_texture(t_cube *cube);
void	load_xpm_to_array(t_cube *cube, char *s, int i);
void	malloc_texture_array(t_cube *cube);

//create display
void	create_display(t_cube *cube);
void	calculate_fps(t_cube *cube);

//check map
void	check_map(t_cube *cube, char *argv);
void	check_map_name(t_cube *cube, char *argv);
void	check_map_struct(t_cube *cube);
void	check_map_closed_elements(t_cube *cube);
void	check_first_last_line(t_cube *cube, int line_index);
void	check_map_line(t_cube *cube, int line_index);
void	find_space_start(t_cube *cube, int *i, int line_index,
			int *space_start);
void	find_check_space(t_cube *cube, int line_index, int *i);
void	check_start_end_number(t_cube *cube, int line_index);
void	check_space_surrounding(t_cube *cube, int line_index, int space_start);
void	check_map_player(t_cube *cube);
void	check_c_f(t_cube *cube, char *str);
void	check_c_f_line(t_cube *cube, char *line);
void	check_dif_size_line(t_cube *cube);
void	check_diff_part(t_cube *cube, int i, size_t size);

//operation
int		key_press(int keycode, t_cube *cube);
int		key_release(int keycode, t_cube *cube);
int		process_input(t_cube *cube);
void	move_forward(t_cube *cube);
void	move_backward(t_cube *cube);
void	move_left(t_cube *cube);
void	move_right(t_cube *cube);
void	rotate_left(t_cube *cube); //todo
void	rotate_right(t_cube *cube); //todo

// utils
char	*ft_strdup_nl(char *s1);
int		close_window(t_cube *cube, char *s);
int		ft_strcmp(const char *s1, const char *s2);
void	print_error_close_window(t_cube *cube, char *s);
double	normalize_angle(double angle);
void	ft_abs(double *x);

//free
void	free_all(t_cube *cube);
void	free_map_struct(t_map *map);
void	free_map(char **map);
void	free_texture_struct(t_texture *texture);
void	free_texture_array(uint32_t **buffer);
void	free_image_struct(t_img *image, void *mlx);
void	free_all_helper(t_cube *cube);
