/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   control.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arouzen <arouzen@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 18:48:26 by hchahid           #+#    #+#             */
/*   Updated: 2023/01/24 17:44:10 by arouzen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	reinitialze_img(t_ply *p)
{
	mlx_destroy_image(p->mlx, p->img);
	p->img = mlx_new_image(p->mlx, MAP_ROWS * TILE_SIZE, MAP_COLS * TILE_SIZE);
	p->addr = mlx_get_data_addr(p->img, &p->bits_per_pixel,
			&p->line_length, &p->endian);
}

void	field_of_view(t_ply *p, int key)
{
	reinitialze_img(p);
	if (key == RIGHT)
		p->rotation_angle += p->rotation_speed;//3 * (PI / 180);
	else if (key == LEFT)
		p->rotation_angle -= p->rotation_speed ;//3 * (PI / 180);
	p->rotation_angle = normalize_angle(p->rotation_angle);
	//printf("Rotation angle [%f]\n", p->rotation_angle);
	draw_map(p);
}

void	move_player(t_ply *p, int key)
{
	int	new_x;
	int	new_y;

	reinitialze_img(p);
	if (key == S || key == W)
	{
		if (key == W)
			p->walk_direction = 1;
		else
			p->walk_direction = -1;
		new_y = sin(p->rotation_angle) * p->step * p->walk_direction;
		new_x = cos(p->rotation_angle) * p->step * p->walk_direction;
		if (has_wall(p, p->x + new_x, p->y + new_y))
			return ;
		p->x += new_x;
		p->y += new_y;
	}
	else if (key == D || key == A)
	{
		if (key == D)
			p->walk_direction = 1;
		else
			p->walk_direction = -1;
		new_y = sin(p->rotation_angle + (90 * PI / 180)) * p->step * p->walk_direction;
		new_x = cos(p->rotation_angle + (90 * PI / 180)) * p->step * p->walk_direction;
		if (has_wall(p, p->x + new_x, p->y + new_y))
			return ;
		p->y += new_y;
		p->x += new_x;
	}
	//printf("Player x[%.2f]y[%.2f]\n", p->x, p->y);
	draw_map(p);
}

int key(int key, t_ply *p)
{
	if (key == ESC)
	{
		mlx_destroy_window(p->mlx, p->win);
		exit (0);
	}
	if (key == RIGHT || key == LEFT)
		field_of_view(p, key);
	else if (key == A || key == S || key == D || key == W)
		move_player(p, key);
}

int	cross(t_ply *p)
{
	mlx_destroy_window(p->mlx, p->win);
	exit(0);
}
