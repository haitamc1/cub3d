/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wall_hit.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arouzen <arouzen@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 12:43:42 by arouzen           #+#    #+#             */
/*   Updated: 2023/01/15 12:58:58 by arouzen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

t_point	get_vertical_wall_hit_point(t_point a, double angle)
{
	double	xstep;
	double	ystep;
	t_point	first_intersection;

	xstep = TILE_SIZE;
	ystep = tan(angle) * xstep;
	first_intersection.x = floor(a.x / TILE_SIZE) * (TILE_SIZE + 1 );
	first_intersection.y = a.y - tan(angle) * (first_intersection.x - a.x);
	if (has_wall(first_intersection.x, first_intersection.y))
		return (first_intersection);
	while (first_intersection.x < WIDTH && first_intersection.y < HEIGHT)
	{
		first_intersection.x += xstep;
		first_intersection.y += ystep;
		if (has_wall(first_intersection.x, first_intersection.y))
			return (first_intersection);
	}
}

t_point	get_horizontal_wall_hit_point(t_point a, double angle)
{
	double	xstep;
	double	ystep;
	t_point	first_intersection;

	xstep = TILE_SIZE;
	ystep = tan(angle) * xstep;
	first_intersection.y = floor(a.y / TILE_SIZE) * (TILE_SIZE);
	first_intersection.x = a.x + (a.y - first_intersection.y) / tan(angle);
	if (has_wall(first_intersection.x, first_intersection.y))
		return (first_intersection);
	while (first_intersection.x < WIDTH && first_intersection.y < HEIGHT)
	{
		first_intersection.x += xstep;
		first_intersection.y += ystep;
		if (has_wall(first_intersection.x, first_intersection.y))
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

t_bool	has_wall(int x, int y)
{
	//printf("Wall check x[%d]y[%d]\n", x / TILE_SIZE, y / TILE_SIZE);
	if (grid[y / TILE_SIZE][x / TILE_SIZE] == 1)
		return (TRUE);
	return (FALSE);
}
