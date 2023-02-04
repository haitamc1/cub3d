/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wall.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchahid <hchahid@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 01:11:59 by hchahid           #+#    #+#             */
/*   Updated: 2023/02/04 18:26:39 by hchahid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/cub3d.h"

#define TEXTURE_HEIGHT 40
#define TEXTURE_WIDTH 40
unsigned int	wall_texture[40 * 40];

void creat_wall(void) {
    for (int x = 0; x < 40; x++)
	{
        for (int y = 0; y < 40; y++)
		{
			if (x % 10 && y % 10)
            	wall_texture[(40 * y) + x] = 255;
			else
				wall_texture[(40 * y) + x] = 0;
		}
	}
}


double	wall_strip_height(double ray_lenght)
{
	double	dis_proj_plane;
	double	wall_strip_height;
	int		width;

	width = MAP_COLS * TILE_SIZE;
	dis_proj_plane = (width / 2) / tan(PI / 6);
	wall_strip_height = (TILE_SIZE / ray_lenght) * dis_proj_plane;
	return (wall_strip_height);
}

int	texture_offset_x(t_coordinates hit_point)
{
	int	x_texture_offset;

	if (hit_point.vertical_hit)
		x_texture_offset = (int )fmod(hit_point.y, TILE_SIZE);
	else
		x_texture_offset = (int )fmod(hit_point.x, TILE_SIZE);
	return (x_texture_offset);
}

int	texture_offset_y(int dis_from_top_wall, double strip_height)
{	
	return(dis_from_top_wall * ((double )(TEXTURE_HEIGHT) / strip_height));
	
}
void	wall(t_ply *p, int i, int j, double strip_height, t_coordinates hit_point)
{
	// static bool flag = true;
	int	dis_from_top_wall;
	int	j_holder;
	int	i_holder;
	int	y_texture_offset;
	int	x_texture_offset;
	int	color;

	j_holder = j;
	i_holder = i;
	dis_from_top_wall = j + (strip_height / 2) - (HEIGHT / 2);
	x_texture_offset = texture_offset_x(hit_point);
	// color = 0x00f00ff0;
	// if (flag)
	// {
	// 	flag = false;
	// 	for (int x = 0; x < 40; x++)
	// 	{
	// 		for (int y = 0; y < 40; y++)
	// 		{
	// 			printf("%d   ", wall_texture[y * TEXTURE_WIDTH + x]);
	// 		}
	// 		printf("\n");
	// 	}
	// }
	if (j > HEIGHT)
		j = HEIGHT;
	else if (j < 0)
	{
		j = 0;
		j_holder = 0;
		strip_height = HEIGHT;
	}
	while (j < j_holder + strip_height)
	{
		y_texture_offset = texture_offset_y(j, strip_height);
		// if (j % 10 == 0 || i % 10 == 0)
		// 	my_mlx_pixel_put(p, i, j, 0xff000000);
		// else
		color = wall_texture[(TEXTURE_WIDTH * y_texture_offset) + x_texture_offset];
		my_mlx_pixel_put(p, i, j, color);
		j++;
	}
}

void	draw_wall(t_ply *p, double angle, int i)
{
	double	fish_bowl_fix;
	double	strip_height;
	t_coordinates	hit_point;

	hit_point = distance_to_wall(p, angle);
	fish_bowl_fix = cos(p->rotation_angle - angle) * hit_point.ray_lenght;
	strip_height = wall_strip_height(fish_bowl_fix);
	wall(p, i, floor((HEIGHT / 2) - (strip_height / 2)), strip_height, hit_point);
}


// int	texture(t_ply *p, t_coordinates hit_point)
// {
// 	int	x_texture_offset;
// 	int	y_texture_offset;
// 	int	dis_from_top_wall;
// 	int	color;

// 	dis_from_top_wall = j + (strip_height / 2) - (HEIGHT / 2);
// 	if (hit_point.vertical_hit)
// 		x_texture_offset = (int )fmod(hit_point.y, TILE_SIZE);
// 	else
// 		x_texture_offset = (int )fmod(hit_point.x, TILE_SIZE);
// 	// should be done in the loop that draws 
// 	// j represents where to start drawing 
// 	y_texture_offset = dis_from_top_wall * ((double )(TEXTURE_HEIGHT) / strip_height);
// 	color = wall_texture[(TEXTURE_WIDTH * y_texture_offset) + x_texture_offset];
	
// }