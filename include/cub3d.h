/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arouzen <arouzen@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 18:44:08 by hchahid           #+#    #+#             */
/*   Updated: 2023/01/13 18:24:47 by arouzen          ###   ########.fr       */
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

# define RIGHT 124 
# define LEFT 123

//*************************************************//

//*********FOR_MOVEMENT**********//

# define A 0
# define S 1
# define D 2
# define W 13

//******************************//

# define WALL_CLR 0x00f00ff0
# define MAP_ROWS 15
# define MAP_COLS 15

# define TILE_SIZE 40
# define WIDTH (MAP_COLS * TILE_SIZE)
# define HEIGHT (MAP_ROWS * TILE_SIZE)
# define PI 3.14159265359

typedef struct texture
{
	char	*no_file;
	char	*so_file;
	char	*ea_file;
	char	*we_file;
	int		floor_clr;
	int		ceiling_clr;
}			t_texture;

typedef struct player
{
	double	x;
	double	y;
	int		step_lenght;
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

}	t_ply;

typedef struct s_ray
{
	int	ray_id;
	int	ray_color;
}				t_ray;

extern t_texture data;


void	init_values(t_ply *p);
int	is_there_wall(double new_x, double new_y);


/****************************************
----------------- UTILS -----------------
*****************************************/

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
char 		**parse_resources(char **map);
void		init_textures(t_texture *data);
void		check_map(char **map);
char		**get_map(char *file);
bool		is_space(char c);
void		check_space(char **map, int x, int y);
void		check_zero(char **map, int x, int y);
int			parse_map(char **map);
void		parse_line(char **map, int x);
t_bool		is_valid_token(char c);
t_bool		is_player_pos(char c);
bool		filled_texture_check(t_texture s);
void		check_player(char **map, int x, int y);


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

void	draw_rect(t_ply *p, int x, int y, int len, int color);
void	draw_map(t_ply *p);
void	draw_playert(t_ply *p);
void	draw_line(t_ply *p, t_point a, t_point b);
t_lineq	cal_alpha(t_point a, t_point b);
void	draw_rays(t_ply *p);
void	draw_ray(t_ply *p);
t_point	set_point(int x, int y);

# define FOV (60 * PI / 180)
# define NUM_RAYS 100
# define RAY_LEN TILE_SIZE * 4
extern int grid[15][15];

#endif
