/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arouzen <arouzen@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 17:44:50 by arouzen           #+#    #+#             */
/*   Updated: 2023/02/07 17:46:38 by arouzen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	move_player(t_ply *p, int key)
{
	reinitialze_img(p);
	if (key == S)
		move_down(p);
	else if (key == W)
		move_up(p);
	else if (key == D)
		move_right(p);
	else if (key == A)
		move_left(p);
	draw_map(p);
}

void	move_up(t_ply *p)
{
	int	offset_x;
	int	offset_y;

	p->walk_direction = 1;
	offset_y = sin(p->rotation_angle) * p->step * p->walk_direction;
	offset_x = cos(p->rotation_angle) * p->step * p->walk_direction;
	if (has_wall(p, p->x + offset_x, p->y + offset_y, TRUE))
		return ;
	p->x += offset_x;
	p->y += offset_y;
}

void	move_down(t_ply *p)
{
	int	offset_x;
	int	offset_y;

	p->walk_direction = -1;
	offset_y = sin(p->rotation_angle) * p->step * p->walk_direction;
	offset_x = cos(p->rotation_angle) * p->step * p->walk_direction;
	if (has_wall(p, p->x + offset_x, p->y + offset_y, TRUE))
		return ;
	p->x += offset_x;
	p->y += offset_y;
}

void	move_right(t_ply *p)
{
	int	offset_x;
	int	offset_y;

	p->walk_direction = 1;
	offset_y = sin(p->rotation_angle + (90 * PI / 180)) * \
	p->step * p->walk_direction;
	offset_x = cos(p->rotation_angle + (90 * PI / 180)) * \
	p->step * p->walk_direction;
	if (has_wall(p, p->x + offset_x, p->y + offset_y, TRUE))
		return ;
	p->x += offset_x;
	p->y += offset_y;
}

void	move_left(t_ply *p)
{
	int	offset_x;
	int	offset_y;

	p->walk_direction = -1;
	offset_y = sin(p->rotation_angle + (90 * PI / 180)) * \
	p->step * p->walk_direction;
	offset_x = cos(p->rotation_angle + (90 * PI / 180)) * \
	p->step * p->walk_direction;
	if (has_wall(p, p->x + offset_x, p->y + offset_y, TRUE))
		return ;
	p->x += offset_x;
	p->y += offset_y;
}
