/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchahid <hchahid@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 18:48:26 by hchahid           #+#    #+#             */
/*   Updated: 2023/01/09 16:17:24 by hchahid          ###   ########.fr       */
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
		p->rotation_angle -= 3 * (PI / 180);
	else if (key == LEFT)
		p->rotation_angle += 3 * (PI / 180);
	draw_map(p);
}

void	move_player(t_ply *p, int key)
{
	reinitialze_img(p);
	if (key == A && !is_there_wall(p->x, p->y - p->step_lenght))
		p->y -= p->step_lenght;
	else if (key == S && !is_there_wall(p->x + p->step_lenght, p->y))
		p->x += p->step_lenght;
	else if (key == D && !is_there_wall(p->x, p->y + p->step_lenght))
		p->y += p->step_lenght;
	else if (key == W && !is_there_wall(p->x - p->step_lenght, p->y))
		p->x -= p->step_lenght;
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
