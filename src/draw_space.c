/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_space.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arouzen <arouzen@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 21:33:00 by hchahid           #+#    #+#             */
/*   Updated: 2023/02/08 23:08:38 by arouzen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	draw_wall_strip(t_ply *p, t_ray ray, int x)
{
	double	y_top;
	double	y_bottom;
	double	wall_height;
	double	y;

	wall_height = TILE_SIZE / ray.distance * (p->width / 2) / tan(p->fov / 2);
	y_top = (p->width / 2) - (wall_height / 2);
	if (y_top < 0)
		y_top = 0;
	y_bottom = (p->width / 2) + (wall_height / 2);
	if (y_bottom >= p->height)
		y_bottom = p->height - 1;
	draw_ceiling(p, x, y_top);
	y = y_top;
	while (y < y_bottom)
		draw_pxl(p, &ray, x, y++);
	draw_floor(p, x, y_bottom);
}

void	draw_walls(t_ply *p, t_ray *ray)
{
	int	i;

	i = 0;
	while (i < NUM_RAYS)
	{
		draw_wall_strip(p, ray[i], i);
		i++;
	}
}

void	draw_ceiling(t_ply *p, int x, int y_end)
{
	int	j;

	j = 0;
	while (j < y_end)
	{
		my_mlx_pixel_put(p, x, j, p->txt.ceiling_clr);
		j++;
	}
}

void	draw_floor(t_ply *p, int x, int y_start)
{
	int	j;

	j = y_start;
	while (j < p->height)
	{
		my_mlx_pixel_put(p, x, j, p->txt.floor_clr);
		j++;
	}
}
