/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wall.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arouzen <arouzen@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 12:43:42 by arouzen           #+#    #+#             */
/*   Updated: 2023/01/22 13:00:52 by arouzen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

t_point	get_horizontal_wall_hit_point(t_point a, double angle)
{
	double	xstep;
	double	ystep;
	t_point	first_intersection;
	double	ycheck;

	ystep = TILE_SIZE;
	if (is_facing_up(angle))
		ystep = - ystep;
	xstep = TILE_SIZE / tan(angle);
	if (is_facing_right(angle) && xstep < 0)
		xstep = - xstep;
	if (is_facing_right(angle) == FALSE && xstep > 0)
		xstep = - xstep;
	first_intersection.y = floor(a.y / TILE_SIZE) * (TILE_SIZE);
	if (is_facing_up(angle) == FALSE)
		first_intersection.y += TILE_SIZE;
	first_intersection.x = a.x + (first_intersection.y - a.y) / tan(angle);
	if (is_facing_up(angle))
		ycheck = first_intersection.y - 1;
	else 
		ycheck = first_intersection.y + 1;
	if (has_wall(first_intersection.x, ycheck))
		return (first_intersection);
	while (first_intersection.x < WIDTH && first_intersection.y < HEIGHT \
		&& first_intersection.x >=0 && first_intersection.y >= 0)
	{
		first_intersection.x += xstep;
		first_intersection.y += ystep;
		if (is_facing_up(angle))
			ycheck = first_intersection.y - 1;
		else
			ycheck = first_intersection.y + 1;
		if (has_wall(first_intersection.x, ycheck))
			return (first_intersection);
	}
}

t_point	get_vertical_wall_hit_point(t_point a, double angle)
{
	double	xstep;
	double	ystep;
	t_point	first_intersection;
	double	xcheck;

	xstep = TILE_SIZE;
	if (is_facing_right(angle) == FALSE)
		xstep = - xstep;
	ystep = tan(angle) * TILE_SIZE;
	if (is_facing_up(angle) == TRUE && ystep > 0)
		ystep = - ystep;
	if (is_facing_up(angle) == FALSE && ystep < 0)
		ystep = - ystep;
	first_intersection.x = floor(a.x / TILE_SIZE) * (TILE_SIZE);
	if (is_facing_right(angle) == TRUE)
		first_intersection.x += TILE_SIZE;
	first_intersection.y = a.y + (first_intersection.x - a.x) * tan(angle);
	
	if (is_facing_right(angle))
		xcheck = first_intersection.x + 1;
	else
		xcheck = first_intersection.x - 1;
	if (has_wall(xcheck, first_intersection.y))
		return (first_intersection);
	while (first_intersection.x < WIDTH && first_intersection.y < HEIGHT \
	&& first_intersection.x >= 0 && first_intersection.y >= 0)
	{
		first_intersection.x += xstep;
		first_intersection.y += ystep;
		if (is_facing_right(angle))
			xcheck = first_intersection.x + 1;
		else
			xcheck = first_intersection.x - 1;
		if (has_wall(xcheck, first_intersection.y))
			return (first_intersection);
	}
}

t_point	get_wall_hit_point(t_point a, double angle)
{
	t_point	vertical_hit_point;
	t_point	horizontal_hit_point;

	vertical_hit_point = get_vertical_wall_hit_point(a, angle);
	horizontal_hit_point = get_horizontal_wall_hit_point(a, angle);
	if (get_distance(a, vertical_hit_point) > get_distance(a, horizontal_hit_point))
		return (horizontal_hit_point);
	return (vertical_hit_point);
}

t_bool	has_wall(double x, double y)
{
	int	xcheck;
	int	ycheck;
	if (x > WIDTH || y > HEIGHT || x < 0 || y < 0)
		return (/*printf("out of bounds y[%.2f]x[%.2f]\n", y, x),*/ TRUE);
	xcheck = floor(x / TILE_SIZE);
	ycheck = floor(y/ TILE_SIZE);
	//printf("Wall check y[%d]x[%d]\n", ycheck, xcheck);
	if (grid[ycheck][xcheck] == 1)
		return (TRUE);
	return (FALSE);
}
