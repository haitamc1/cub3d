/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchahid <hchahid@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 18:44:08 by hchahid           #+#    #+#             */
/*   Updated: 2023/01/06 19:54:44 by hchahid          ###   ########.fr       */
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
	bool	no;
	char	*no_file;
	bool	so;
	char	*so_file;
	bool	ea;
	char	*ea_file;
	bool	we;
	char	*we_file;
	bool	floor;
	int		floor_clr;
	bool	ceiling;
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
char	**allocate_dp(int	size);
bool	just_space(char *s);

/*****************************************/

char	*get_texture_file(char *s);
int		get_clr(char *clr);
void	get_texture(char *data, t_texture *check);
void	check_space(char *direction, char *description, t_texture *check);

int		key(int key, t_ply *p);
int		cross(t_ply *p);
int		mouse_hook(int key, int i, int j, t_ply *p);
int		ft_strcmp(const char *s1, const char *s2);

#endif
