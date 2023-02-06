/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   control.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arouzen <arouzen@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 18:48:26 by hchahid           #+#    #+#             */
/*   Updated: 2023/01/26 13:36:53 by arouzen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	reinitialze_img(t_ply *p)
{
	mlx_destroy_image(p->mlx, p->img);
	//printf("player pointer [%p]\n", p);
	p->img = mlx_new_image(p->mlx, MAP_ROWS * TILE_SIZE, MAP_COLS * TILE_SIZE);
	if (p->img == NULL)
		exit_msg("Failed to get new image\n");
	p->addr = mlx_get_data_addr(p->img, &p->bits_per_pixel,
			&p->line_length, &p->endian);
	if (p->addr == NULL)
		exit_msg("Failed to get new image address\n");
}

void	field_of_view(t_ply *p, int key)
{
	reinitialze_img(p);
	if (key == RIGHT || key == SCROLL_DOWN)
		p->rotation_angle += p->rotation_speed;//3 * (PI / 180);
	else if (key == LEFT || key == SCROLL_UP)
		p->rotation_angle -= p->rotation_speed ;//3 * (PI / 180);
	p->rotation_angle = normalize_angle(p->rotation_angle);
	//printf("Rotation angle [%f]\n", p->rotation_angle);
	draw_map(p);
}

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

int key(int key, t_ply *p)
{
	if (key == ESC)
	{
		mlx_destroy_window(p->mlx, p->win);
		exit (0);
	}
	if (key == RIGHT || key == LEFT || key == SCROLL_DOWN || key == SCROLL_UP)
		field_of_view(p, key);
	else if (key == A || key == S || key == D || key == W)
		move_player(p, key);
}

int	cross(t_ply *p)
{
	mlx_destroy_window(p->mlx, p->win);
	exit(0);
}

int	mouse_hook(int	key, int x, int y, t_ply * p)
{
	(void) x;
	(void) y;
	field_of_view(p, key);
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
	offset_y = sin(p->rotation_angle + (90 * PI / 180)) * p->step * p->walk_direction;
	offset_x = cos(p->rotation_angle + (90 * PI / 180)) * p->step * p->walk_direction;
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
	offset_y = sin(p->rotation_angle + (90 * PI / 180)) * p->step * p->walk_direction;
	offset_x = cos(p->rotation_angle + (90 * PI / 180)) * p->step * p->walk_direction;
	if (has_wall(p, p->x + offset_x, p->y + offset_y, TRUE))
		return ;
	p->x += offset_x;
	p->y += offset_y;
}
