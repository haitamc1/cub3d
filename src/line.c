/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchahid <hchahid@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 12:40:16 by arouzen           #+#    #+#             */
/*   Updated: 2023/02/07 19:44:48 by hchahid          ###   ########.fr       */
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
	double	x;
	double	y;
	int		i;
	double	step;

	dx = b.x - a.x;
	dy = b.y - a.y;
	if (fabs(dx) >= fabs(dy))
		step = fabs(dx);
	else
		step = fabs(dy);
	dx = dx / step;
	dy = dy / step;
	x = a.x;
	y = a.y;
	i = 0;
	while (i < step)
	{
		x = x + dx;
		y = y + dy;
		i++;
		if (y < 0 || x < 0 || y >= TILE_SIZE * MAP_COLS || x >= TILE_SIZE * MAP_ROWS)
			break ;
		// if ((x <= p->x + 50 && y <= p->y + 50) && (x >= p->x - 50 && y >= p->y - 50))
			my_mlx_pixel_put(p, x, y, 0xf80011);
	}
}

t_point	set_point(double x, double y)
{
	t_point	p;
	p.x = x;
	p.y = y;
	return (p);
}
