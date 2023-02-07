/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchahid <hchahid@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 16:23:39 by arouzen           #+#    #+#             */
/*   Updated: 2023/02/07 21:11:22 by hchahid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

t_point	scale_coordinat_for_minimap(int x_origin, int y_origin, int	x, int y)
{
	t_point	new_point;

	new_point.x = x - x_origin;
	new_point.y = y - y_origin;
	return (new_point);
}

t_point	get_new_width_height(int x, int y, int x_limit, int	y_limit)
{
	t_point	draw_offset;

	draw_offset.x = TILE_SIZE;
	draw_offset.y = TILE_SIZE;
	if (x % TILE_SIZE != 0)
		draw_offset.x = TILE_SIZE - (x % TILE_SIZE);
	if (y % TILE_SIZE != 0)
		draw_offset.y = TILE_SIZE - (y % TILE_SIZE);
	while (x + draw_offset.x > x_limit)
		draw_offset.x--;
	while (y + draw_offset.y > y_limit)
		draw_offset.y--;
	return (draw_offset);
}

void	draw_player(t_ply *p)
{
	t_point	offset;
	t_point	dimension;

	dimension.x = 5;
	dimension.y = 5;
	offset.x = p->x - (p->x - 150);
	offset.y = p->y - (p->y - 150);
	if (offset.x < 0)
		offset.x = 0;
	if (offset.y < 0)
		offset.y = 0;
	draw_rect(p, offset, dimension, 255);
}

int	correct_value_i(int init, int failure)
{
	int	r;

	r = init;
	if (r < failure)
		r = failure;
	return (r);
}

int	correct_value_s(int init, int failure)
{
	int	r;

	r = init;
	if (r > failure)
		r = failure;
	return (r);
}

int	correct_incrementation(int v1, int v2)
{
	if (v1 != v2)
		return (v1);
	return (v2);
}

void	minimap(t_ply *p, t_point point, t_point limits)
{
	t_point	draw_offset;
	t_point	new_point;

	while (point.y < limits.y)
	{
		point.x = correct_value_i(p->x - 150, 0);
		while (point.x < limits.x)
		{
			draw_offset = get_new_width_height(point.x, point.y, limits.x, limits.y);
			new_point = scale_coordinat_for_minimap(p->x - 150, p->y - 150, point.x, point.y);
			if (p->map[(int )point.y / TILE_SIZE][(int )point.x / TILE_SIZE] == '1')
			{
				if (point.x >= 0 && point.x <= p->x_map * TILE_SIZE && point.y >= 0 && point.y <= p->y_map * TILE_SIZE)
					draw_rect(p, new_point, draw_offset, 0xFA4FFF);
			}
			else
				draw_rect(p, new_point, draw_offset, 0xffe4b5);
			point.x += correct_incrementation(draw_offset.x, TILE_SIZE);
		}
		point.y += correct_incrementation(draw_offset.y, TILE_SIZE);
	}
}

void	draw_map(t_ply *p)
{
	t_ray	ray[NUM_RAYS];
	t_point	point;
	t_point	limits;

	init_rays(p, ray);
	draw_walls(p, ray);
	point.y = correct_value_i(p->y - 150, 0);
	limits.x = correct_value_s(p->x + 150, p->x_map * TILE_SIZE);
	limits.y = correct_value_s(p->y + 150, p->y_map * TILE_SIZE);
	minimap(p, point, limits);
	draw_player(p);
	mlx_put_image_to_window(p->mlx, p->win, p->img, 0, 0);
}

void	draw_rect(t_ply *p, t_point origin, t_point limit, int color)
{
	int	i;
	int	j;

	j = 0;
	while (j < limit.y - 1)
	{
		i = 0;
		while (i < limit.x - 1)
		{
			my_mlx_pixel_put(p, origin.x + i, origin.y + j, color);
			i++;
		}
		j++;
	}
}

void	draw_ray(t_ply *p)
{
	t_point	a;
	t_ray	ray;

	ray.origin = set_point(p->x + p->player_size / 2, p->y + p->player_size / 2);
	set_wall_hit_point(p, &ray, p->rotation_angle);
	if (is_facing_right(p->rotation_angle))
		printf("facing right\n");
	else
		printf("facing left\n");
	if (is_facing_up(p->rotation_angle))
		printf("facing up\n");
	else
		printf("facing down\n");
	printf("=============== hit point fount at y[%.2f]x[%.2f]\n", ray.hit_wall.y, ray.hit_wall.x);
	render_ray(p, ray);
}

double	normalize_angle(double angle)
{
	double	new_angle;

	new_angle = fmod(angle, 2 * PI);
	if (new_angle < 0)
		return ((2 * PI) + new_angle );
	return (new_angle);
}

void	draw_wall_strip(t_ply *p, t_ray ray, int x)
{
	double	y_top;
	double	y_bottom;
	double	wall_height;
	double	distance_from_top;
	double	plane_distance;
	double	y;

	plane_distance = (WIDTH / 2) / tan(FOV / 2);
	wall_height = TILE_SIZE / ray.distance * plane_distance;
	y_top = (WIDTH / 2) - (wall_height / 2);
	if (y_top < 0)
		y_top = 0;
	y_bottom = (WIDTH / 2) + (wall_height / 2);
	if (y_bottom >= HEIGHT)
		y_bottom = HEIGHT - 1;
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
		//printf("drawing strip %d\n", i);
		i++;
	}
}

void	my_mlx_pixel_put(t_ply *p, int x, int y, int color)
{
	char	*dst;

	dst = p->addr + (y * p->line_length + x * (p->bits_per_pixel / 8));
	*(unsigned int *) dst = color;
}

int	get_mlx_pixel_color(t_ply *p, char *txt, int x, int y)
{
	char	*dst;

	dst = txt + (y * p->txt.len + x * (p->txt.bpp / 8));
	return (*(unsigned int *) dst);
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
	while (j < HEIGHT)
	{
		my_mlx_pixel_put(p, x, j, p->txt.floor_clr);
		j++;
	}
}

void	draw_pxl(t_ply *p, t_ray *ray, int x, double y)
{
	int		color;
	double	distance_from_top;
	double	wall_height;
	int		y_color;

	wall_height = (TILE_SIZE / ray->distance) * (WIDTH / 2) / tan(FOV / 2);
	distance_from_top = y + wall_height / 2 - WIDTH / 2;
	y_color = distance_from_top * TILE_SIZE / wall_height;
	if (ray->hit_type == HORZ && is_facing_up(ray->angle))
		color = get_mlx_pixel_color(p, p->txt.no_txtr, ray->x_txt, y_color);
	else if (ray->hit_type == HORZ && is_facing_up(ray->angle) == FALSE)
		color = get_mlx_pixel_color(p, p->txt.so_txtr, ray->x_txt, y_color);
	else if (ray->hit_type == VERT && is_facing_right(ray->angle))
		color = get_mlx_pixel_color(p, p->txt.ea_txtr, ray->x_txt, y_color);
	else if (ray->hit_type == VERT && is_facing_right(ray->angle) == FALSE)
		color = get_mlx_pixel_color(p, p->txt.we_txtr, ray->x_txt, y_color);
	else
		return ;
	my_mlx_pixel_put(p, x, y, color);
}