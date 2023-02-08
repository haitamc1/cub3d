/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arouzen <arouzen@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 12:40:16 by arouzen           #+#    #+#             */
/*   Updated: 2023/02/08 12:41:48 by arouzen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

double	get_distance(t_point a, t_point b)
{
	return (sqrt(pow(b.x - a.x, 2) + pow(b.y - a.y, 2)));
}

void	line_dda(t_ply *p, t_point a, t_point b)
{
	double	dx;
	double	dy;
	t_point	point;
	double	step;

	dx = b.x - a.x;
	dy = b.y - a.y;
	if (fabs(dx) >= fabs(dy))
		step = fabs(dx);
	else
		step = fabs(dy);
	dx = dx / step;
	dy = dy / step;
	point.x = a.x;
	point.y = a.y;
	while (step)
	{
		point.x = point.x + dx;
		point.y = point.y + dy;
		if (point.y < 0 || point.x < 0 || point.y >= TILE_SIZE * MAP_COLS \
		|| point.x >= TILE_SIZE * MAP_ROWS)
			break ;
		my_mlx_pixel_put(p, point.x, point.y, 0xf80011);
		step--;
	}
}

t_point	set_point(double x, double y)
{
	t_point	p;

	p.x = x;
	p.y = y;
	return (p);
}
