/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arouzen <arouzen@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 18:44:08 by hchahid           #+#    #+#             */
/*   Updated: 2023/01/07 22:56:30 by arouzen          ###   ########.fr       */
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

# define UP 126
# define DOWN 125
# define RIGHT 124
# define LEFT 123

# define A 0
# define S 0
# define D 0
# define W 13

# define TILE_SIZE 32
# define WIDTH 600
# define HEIGHT 600
# define PI 3.14159265359

typedef struct texture
{
	char	*no_file;
	char	*so_file;
	char	*ea_file;
	char	*we_file;
	int		floor_clr;
	int		ceiling_clr;
}	t_texture;

typedef struct image
{
	char	*img_addr;
	int		width;
	int		height;

}	t_img;

typedef struct player
{
	double	x;
	double	y;
	void	*img;
	void	*mlx;
	void	*win;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	char	space_type;

}	t_ply;
extern t_texture data;

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
t_texture	check_map(char **map);
char		**get_map(char *file);
bool		is_space(char c);
void		check_space(char *map, int pos);
int			parse_map(char **map);
void		parse_line(char *line);

#endif
