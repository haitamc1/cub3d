/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchahid <hchahid@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 21:21:52 by hchahid           #+#    #+#             */
/*   Updated: 2023/02/07 21:28:22 by hchahid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

t_point	scale_coordinat_for_minimap(int x_origin, int y_origin, int x, int y)
{
	t_point	new_point;

	new_point.x = x - x_origin;
	new_point.y = y - y_origin;
	return (new_point);
}

t_point	get_new_width_height(int x, int y, int x_limit, int y_limit)
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
			draw_offset = get_new_width_height(point.x,
					point.y, limits.x, limits.y);
			new_point = scale_coordinat_for_minimap(p->x - 150,
					p->y - 150, point.x, point.y);
			if (p->map[(int )point.y / TILE_SIZE] \
				[(int )point.x / TILE_SIZE] == '1')
			{
				if (point.x >= 0 && point.x <= p->x_map * TILE_SIZE
					&& point.y >= 0 && point.y <= p->y_map * TILE_SIZE)
					draw_rect(p, new_point, draw_offset, 0xFA4FFF);
			}
			else
				draw_rect(p, new_point, draw_offset, 0xffe4b5);
			point.x += correct_incrementation(draw_offset.x, TILE_SIZE);
		}
		point.y += correct_incrementation(draw_offset.y, TILE_SIZE);
	}
}
