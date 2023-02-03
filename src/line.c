/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arouzen <arouzen@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 12:40:16 by arouzen           #+#    #+#             */
/*   Updated: 2023/01/24 20:59:14 by arouzen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

t_lineq	cal_alpha(t_point a, t_point b)
{
	t_lineq	t;

	if (b.x == a.x)
		t.alpha = 0;
	else t.alpha = (b.y - a.y) / (b.x - a.x);
	t.beta = (b.y) - (t.alpha * b.x);
	return (t);
}

void	draw_line(t_ply *p, t_point a, t_point b)
{
	double		x;
	double		y;
	double		x_end;
	double		step;
	t_lineq		ln;

	ln = cal_alpha(a,b);
	x = fmin(a.x, b.x);
	x_end = fmax(a.x, b.x);
	step =  (x_end - x) / (RAY_LEN * 3);
	printf("alpha[%f] | beta[%f]\n", ln.alpha, ln.beta);
	printf("step [%f]\n", step);
	while (x < x_end)
	{
		y = ln.alpha * x + ln.beta;
		if (y < 0 || x < 0 || y >= TILE_SIZE * MAP_COLS || x >= TILE_SIZE * MAP_ROWS)
			break ;
		my_mlx_pixel_put(p, x, y, 0xff0011);
		x += step;
	}
}

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

	printf("A: x[%.2f] | y[%.2f]\n", a.x, a.y);
	printf("B: x[%.2f] | y[%.2f]\n", b.x, b.y);
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
		my_mlx_pixel_put(p, x, y, 0xf80011);
	}
}

t_point	set_point(int x, int y)
{
	t_point	p;
	p.x = x;
	p.y = y;
	return (p);
}
