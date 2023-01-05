/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchahid <hchahid@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 18:44:08 by hchahid           #+#    #+#             */
/*   Updated: 2023/01/05 16:21:51 by hchahid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "get_next_line.h"
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

char	**ft_split(char const *str, char c);
void	exit_msg(char *msg);
int		arg_len(char **s);
int		ft_atoi(const char *str);
void	str(char *s);
int		is_space(char c);
int		ft_isdigit(int c);
void	free_dp(char **s);
int		cub_fd(char *file_name);
int		map_line_count(int fd);
char	**allocate_dp(int	size);
bool	just_space(char *s);

/*****************************************/

char	*get_texture_file(char *s);
int		get_clr(char *clr);

void	check_space(char *direction, char *description, t_texture *check);

int		key(int key, t_ply *p);
int		cross(t_ply *p);
int		mouse_hook(int key, int i, int j, t_ply *p);
int		ft_strcmp(const char *s1, const char *s2);

#endif
