/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersection.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arouzen <arouzen@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 19:18:56 by arouzen           #+#    #+#             */
/*   Updated: 2023/02/07 19:19:50 by arouzen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	set_wall_hit_point(t_ply *p, t_ray *ray, double angle)
{
	t_point	vertical_hit_point;
	t_point	horizontal_hit_point;

	vertical_hit_point = get_vertical_wall_hit_point(p, ray->origin, angle);
	horizontal_hit_point = get_horizontal_wall_hit_point(p, ray->origin, angle);
	if (get_distance(ray->origin, vertical_hit_point) > \
		get_distance(ray->origin, horizontal_hit_point))
	{
		ray->hit_wall = horizontal_hit_point;
		ray->hit_type = HORZ;
		ray->x_txt = (int) horizontal_hit_point.x % TILE_SIZE;
	}
	else
	{
		ray->hit_wall = vertical_hit_point;
		ray->hit_type = VERT;
		ray->x_txt = (int) vertical_hit_point.y % TILE_SIZE;
	}
}

t_point	get_horizontal_wall_hit_point(t_ply *p, t_point a, double angle)
{
	double	xstep;
	double	ystep;
	t_point	first_intersection;
	double	ycheck;

	ystep = TILE_SIZE;
	first_intersection.y = floor(a.y / TILE_SIZE) * (TILE_SIZE);
	if (is_facing_up(angle))
		ystep = -ystep;
	else
		first_intersection.y += TILE_SIZE;
	xstep = TILE_SIZE / tan(angle);
	if ((is_facing_right(angle) == TRUE && xstep < 0) || \
		(is_facing_right(angle) == FALSE && xstep > 0))
		xstep = -xstep;
	first_intersection.x = a.x + (first_intersection.y - a.y) / tan(angle);
	return (get_horz_intersection_point(p, first_intersection, \
	set_point(xstep, ystep), angle));
}

t_point	get_vertical_wall_hit_point(t_ply *p, t_point a, double angle)
{
	double	xstep;
	double	ystep;
	t_point	first_intersection;
	double	xcheck;

	xstep = TILE_SIZE;
	first_intersection.x = floor(a.x / TILE_SIZE) * (TILE_SIZE);
	if (is_facing_right(angle) == FALSE)
		xstep = -xstep;
	else
		first_intersection.x += TILE_SIZE;
	ystep = tan(angle) * TILE_SIZE;
	if ((is_facing_up(angle) == TRUE && ystep > 0) || \
		(is_facing_up(angle) == FALSE && ystep < 0))
		ystep = -ystep;
	first_intersection.y = a.y + (first_intersection.x - a.x) * tan(angle);
	return (get_vert_intersection_point(p, first_intersection, \
	set_point(xstep, ystep), angle));
}

t_point	get_horz_intersection_point(t_ply *p, t_point begin, \
t_point step, double angle)
{
	double	y_check;

	while (begin.x >= 0 && begin.y >= 0)
	{
		if (is_facing_up(angle))
			y_check = begin.y - 1;
		else
			y_check = begin.y + 1;
		if (has_wall(p, begin.x, y_check, FALSE))
			return (begin);
		begin.x += step.x;
		begin.y += step.y;
	}
	return (begin);
}

t_point	get_vert_intersection_point(t_ply *p, t_point begin, \
t_point step, double angle)
{
	double	x_check;

	while (begin.x >= 0 && begin.y >= 0)
	{
		if (is_facing_right(angle))
			x_check = begin.x + 1;
		else
			x_check = begin.x - 1;
		if (has_wall(p, x_check, begin.y, FALSE))
			return (begin);
		begin.x += step.x;
		begin.y += step.y;
	}
	return (begin);
}
