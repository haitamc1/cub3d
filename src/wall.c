/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wall.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arouzen <arouzen@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 12:43:42 by arouzen           #+#    #+#             */
/*   Updated: 2023/01/25 16:29:26 by arouzen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

t_point	get_horizontal_wall_hit_point(t_ply *p, t_point a, double angle)
{
	double	xstep;
	double	ystep;
	t_point	first_intersection;
	double	ycheck;

	ystep = TILE_SIZE;
	first_intersection.y = floor(a.y / TILE_SIZE) * (TILE_SIZE);
	if (is_facing_up(angle))
		ystep = - ystep;
	else
		first_intersection.y += TILE_SIZE;
	xstep = TILE_SIZE / tan(angle);
	if ((is_facing_right(angle) == TRUE && xstep < 0) || \
		(is_facing_right(angle) == FALSE && xstep > 0))
		xstep = - xstep;
	first_intersection.x = a.x + (first_intersection.y - a.y) / tan(angle);
	while (first_intersection.x >= 0 && first_intersection.y >= 0)
	{
		if (is_facing_up(angle))
			ycheck = first_intersection.y - 1;
		else
			ycheck = first_intersection.y + 1;
		if (has_wall(p, first_intersection.x, ycheck))
			return (first_intersection);
		first_intersection.x += xstep;
		first_intersection.y += ystep;
	}
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
		xstep = - xstep;
	else
		first_intersection.x += TILE_SIZE;
	ystep = tan(angle) * TILE_SIZE;
	if ((is_facing_up(angle) == TRUE && ystep > 0) || \
		(is_facing_up(angle) == FALSE && ystep < 0))
		ystep = - ystep;
	first_intersection.y = a.y + (first_intersection.x - a.x) * tan(angle);	
	while (first_intersection.x >= 0 && first_intersection.y >= 0)
	{
		if (is_facing_right(angle))
			xcheck = first_intersection.x + 1;
		else
			xcheck = first_intersection.x - 1;
		if (has_wall(p, xcheck, first_intersection.y))
			return (first_intersection);
		first_intersection.x += xstep;
		first_intersection.y += ystep;
	}
}

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
		ray->x_txt =  (int) horizontal_hit_point.x % TILE_SIZE;
	}
	else
	{
		ray->hit_wall = vertical_hit_point;
		ray->hit_type = VERT;
		ray->x_txt = (int) vertical_hit_point.y % TILE_SIZE;
	}
}

t_bool	has_wall(t_ply *p, double x, double y)
{
	int		xcheck;
	int		ycheck;
	char	**map;

	map = p->map;
	xcheck = floor(x / TILE_SIZE);
	ycheck = floor(y/ TILE_SIZE);
	//printf("check wall for y[%d]x[%d]\n", ycheck, xcheck);
	if (xcheck < 0 || ycheck < 0 || ycheck > ft_parr_len(p->map) || xcheck > ft_strlen(p->map[ycheck]))
		return (TRUE);
	if (map[ycheck] == NULL || map[ycheck][xcheck] == '1')
		return (TRUE);
	if (ycheck - 1 < 0 || xcheck - 1 < 0)
		return (TRUE);
	return (wall_corner_check(p, ycheck, xcheck));
}

t_bool	wall_corner_check(t_ply *p, int ycheck, int xcheck)
{
	char **map;

	map = p->map;
	if (is_facing_right(p->rotation_angle) && is_facing_up(p->rotation_angle) 
		&& map[ycheck][xcheck - 1] == '1' &&  map[ycheck + 1][xcheck] == '1')
		return (TRUE);
	if (is_facing_right(p->rotation_angle) && !is_facing_up(p->rotation_angle)
		&& map[ycheck - 1][xcheck] == '1' && map[ycheck][xcheck - 1] == '1')
		return (TRUE);
	if (!is_facing_right(p->rotation_angle) && is_facing_up(p->rotation_angle)
		&& map[ycheck + 1][xcheck] == '1' &&  map[ycheck][xcheck + 1] == '1' )
		return (TRUE);
	if (!is_facing_right(p->rotation_angle) && !is_facing_up(p->rotation_angle)
		&& map[ycheck - 1][xcheck] == '1' &&  map[ycheck][xcheck + 1] == '1' )
		return (TRUE);
	return (FALSE);
}
