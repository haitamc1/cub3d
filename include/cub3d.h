/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchahid <hchahid@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 18:44:08 by hchahid           #+#    #+#             */
/*   Updated: 2023/02/04 19:34:49 by hchahid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "../lib/get_next_line/get_next_line_bonus.h"
# include "../lib/libft/libft.h"
# include <stdio.h>
# include <stdlib.h>
# include <stdbool.h>
# include <unistd.h>
# include <fcntl.h>
# include <math.h>
# include "mlx.h"

# define ESC 53

//*********FOR_CHANGING_THE_FIELD_OF_VIEW**********//

#ifdef __linux__ 

# define ESC 65307
# define A 97
# define S 115
# define D 100
# define W 119
# define RIGHT 65363 
# define LEFT 65361

#else

# define ESC 53
# define RIGHT 124 
# define LEFT 123
# define SCROLL_UP 4
# define SCROLL_DOWN 5
# define LEFT_CLICK 1
# define RIGHT_CLICK 2

//*************************************************//

//*********FOR_MOVEMENT**********//

# define A 0
# define S 1
# define D 2
# define W 13

#endif
//******************************//

# define WALL_CLR 0x00f00ff0
# define MAP_ROWS 15
# define MAP_COLS 15

# define TILE_SIZE 64
# define WIDTH (MAP_COLS * TILE_SIZE)
# define HEIGHT (MAP_ROWS * TILE_SIZE)
# define PI 3.14159265359

typedef struct coordinates
{
	double	x;
	double	y;
	double	ray_lenght;
	bool	vertical_hit;

}	t_coordinates;

typedef struct intersection_coordinates
{
	double	horizontal_x;
	double	horizontal_y;
	double	x_step_hoz;
	double	y_step_hoz;
	
	double	vertical_x;
	double	vertical_y;
	double	x_step_vrt;
	double	y_step_vrt;
}	t_intersection;

typedef struct texture
{
	char	*no_file;
	char	*so_file;
	char	*ea_file;
	char	*we_file;
	char	*no_txtr;
	char	*so_txtr;
	char	*ea_txtr;
	char	*we_txtr;
	int		floor_clr;
	int		ceiling_clr;
	int		len;
	int		bpp;
}			t_texture;

typedef struct player
{
	double	x;
	double	y;
	int		step;
	int		tile_size;
	int		player_size;
	double	turn_direction;
	double	walk_direction;
	double	rotation_angle;
	double	rotation_speed;
	void	*img;
	void	*mlx;
	void	*win;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	char	space_type;
	char	**map;
	int		x_map;
	int		y_map;
	t_texture	txt;

}	t_ply;

extern t_texture data;



void creat_wall(void);


void	init_values(t_ply *p);
int		is_there_wall(double new_x, double new_y);

void	horizontal_intersection(t_ply *p, t_intersection *data, double angle);
void	vertical_intersection(t_ply *p, t_intersection *data, double angle);
double	ray_lenght(double ray_x, double ray_y, double player_x, double player_y);

double	normilaze_angle(double	angle);

double	wall_strip_height(double ray_lenght);
void	draw_wall(t_ply *p, double strip_height, int i);

t_coordinates	distance_to_wall(t_ply *p, double angle);

int	my_view(t_ply *p);

/****************************************
----------------- UTILS -----------------
*****************************************/

void	my_mlx_pixel_put(t_ply *p, int x, int y, int color);

void	exit_msg(char *msg);
int		arg_len(char **s);
void	str(char *s);
int		ft_isdigit(int c);
void	free_dp(char **s);
int		cub_fd(char *file_name);
int		map_line_count(int fd);
char	**allocate_dp(int size);
bool	just_space(char *s);
void	load_colors(bool *space, int *clr, char *description);
int		get_rgb_color(int *rgb);
double	deg_to_rad(double n);
void	my_mlx_pixel_put(t_ply *p, int x, int y, int color);

/*****************************************/

char		*get_texture_file(char *s);
int			get_clr(char *clr);
void		get_texture(char *data, t_texture *check);
void		check_resource(char *direction, char *description, t_texture *check);
int			key(int key, t_ply *p);
int			cross(t_ply *p);
int			mouse_hook(int key, int i, int j, t_ply *p);
void		init(t_ply *p);
void		check_file_extension(char *file, char *extension);
char 		**parse_resources(t_ply *p, char **map);
void		init_textures(t_texture *data);
void		check_map(t_ply *p, char *map_file);
void		get_map(t_ply *p, char *file);
void		get_full_map(t_ply *p);
char		*fill_space(char *line, int size);
bool		is_space(char c);
void		check_space(char **map, int x, int y);
void		check_zero(char **map, int x, int y);
int			parse_map(t_ply *p);
void		parse_line(t_ply *p, int x);
t_bool		is_valid_token(char c);
t_bool		is_player_pos(char c);
bool		filled_texture_check(t_texture *s);
void		check_player(char **map, int x, int y);
void		check_file_extension(char *file, char *extension);


void	player_direction(t_ply *p);
void	draw_map(t_ply *p);
//void	draw_player(t_ply *p);

 /* ************************************** TESTS*/
typedef struct s_point 
{
	double	x;
	double	y;
}				t_point;

typedef struct s_lineq
{
	double	alpha;
	double	beta;
} 				t_lineq;

typedef enum hit_type
{
	HORZ,
	VERT,
}			e_hit_type;

typedef struct s_ray
{
	int			id;
	t_point		origin;
	double		angle;
	t_bool		is_facing_up;	
	t_bool		is_facing_down;	
	t_bool		is_facing_left;	
	t_bool		is_facing_right;
	t_point		hit_wall;
	e_hit_type	hit_type;
	double		distance;
	int			x_txt;
}				t_ray;


void	draw_rect(t_ply *p, int x, int y, int len, int color);
void	draw_map(t_ply *p);
void	draw_playert(t_ply *p);
void	draw_line(t_ply *p, t_point a, t_point b);
t_lineq	cal_alpha(t_point a, t_point b);
void	draw_rays(t_ply *p);
void	draw_ray(t_ply *p);
t_point	set_point(int x, int y);
t_bool	has_wall(t_ply *p, double x, double y, t_bool corner_check);
t_point	get_vertical_wall_hit_point(t_ply *p, t_point a, double angle);
t_point	get_horizontal_wall_hit_point(t_ply *p, t_point a, double angle);
double	get_distance(t_point a, t_point b);
void	set_wall_hit_point(t_ply *p, t_ray *ray, double angle);
double	normalize_angle(double angle);
void	init_rays(t_ply *p, t_ray *ray);
void	render_ray(t_ply *p, t_ray ray);
void	render_ray_all(t_ply *p);
t_bool	is_facing_right(double angle);
t_bool	is_facing_up(double angle);
void	line_dda(t_ply *p, t_point a, t_point b);
void	draw_walls(t_ply *p, t_ray *ray);
void	draw_wall_strip(t_ply *p, t_ray ray, int x);
void	draw_ceiling(t_ply *p, int x, int y_end);
void	draw_floor(t_ply *p, int x, int y_start);
e_hit_type	get_wall_hit_type(t_point a, double angle);
int		get_mlx_pixel_color(t_ply *p, char *txt, int x, int y);
char	*get_txtr(t_ply *p, char *file);
void	load_textures(t_ply *p);
void	set_player_pos(t_ply *p, int x, int y);
void	set_player_angle(t_ply *p, char c);
void	draw_pxl(t_ply *p, t_ray *ray, int x, double y);
t_bool	wall_corner_check(t_ply *p, int ycheck, int xcheck);
void	move_up(t_ply *p);
void	move_down(t_ply *p);
void	move_right(t_ply *p);
void	move_left(t_ply *p);
int		mouse_hook(int	key, int x, int y, t_ply * p);
void	get_map_xy(t_ply *p);


# define FOV (60 * PI / 180)
# define NUM_RAYS WIDTH
# define RAY_LEN TILE_SIZE * 4
extern int grid[15][15];
# define ZOOM 1
#endif
