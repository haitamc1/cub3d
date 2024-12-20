/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_cub3d.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arouzen <arouzen@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 16:19:16 by arouzen           #+#    #+#             */
/*   Updated: 2023/02/08 23:04:59 by arouzen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	init_textures(t_texture *data)
{
	data->ea_file = NULL;
	data->so_file = NULL;
	data->no_file = NULL;
	data->we_file = NULL;
	data->floor_clr = -1;
	data->ceiling_clr = -1;
}

void	init_values(t_ply *p)
{
	p->step = 15;
	p->width = MAP_COLS * TILE_SIZE;
	p->height = MAP_ROWS * TILE_SIZE;
	p->num_rays = p->width;
	p->fov = (60 * PI / 180);
	p->tile_size = TILE_SIZE;
	p->walk_direction = 0;
	p->turn_direction = 0;
	p->rotation_speed = 7 * (PI / 180);
	p->player_size = 12;
	p->mlx = mlx_init();
	p->win = mlx_new_window(p->mlx, MAP_ROWS * TILE_SIZE, \
	MAP_COLS * TILE_SIZE, "CUB3D");
	p->img = mlx_new_image(p->mlx, MAP_ROWS * TILE_SIZE, MAP_COLS * TILE_SIZE);
	p->addr = mlx_get_data_addr(p->img, &p->bits_per_pixel, \
	&p->line_length, &p->endian);
}
