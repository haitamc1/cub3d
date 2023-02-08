/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arouzen <arouzen@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 16:23:39 by arouzen           #+#    #+#             */
/*   Updated: 2023/02/08 23:07:05 by arouzen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	draw_map(t_ply *p)
{
	t_ray	ray[NUM_RAYS];
	t_point	point;
	t_point	limits;

	init_rays(p, ray);
	draw_walls(p, ray);
	point.y = correct_value_i(p->y - 150, 0);
	limits.x = correct_value_s(p->x + 150, p->x_map * TILE_SIZE);
	limits.y = correct_value_s(p->y + 150, p->y_map * TILE_SIZE);
	minimap(p, point, limits);
	draw_player(p);
	mlx_put_image_to_window(p->mlx, p->win, p->img, 0, 0);
}

void	draw_rect(t_ply *p, t_point origin, t_point limit, int color)
{
	int	i;
	int	j;

	j = 0;
	while (j < limit.y - 1)
	{
		i = 0;
		while (i < limit.x - 1)
		{
			my_mlx_pixel_put(p, origin.x + i, origin.y + j, color);
			i++;
		}
		j++;
	}
}

void	draw_pxl(t_ply *p, t_ray *ray, int x, double y)
{
	int		color;
	double	distance_from_top;
	double	wall_height;
	int		y_color;

	wall_height = (TILE_SIZE / ray->distance) * (p->width / 2) \
	/ tan(p->fov / 2);
	distance_from_top = y + wall_height / 2 - p->width / 2;
	y_color = distance_from_top * TILE_SIZE / wall_height;
	if (ray->hit_type == HORZ && is_facing_up(ray->angle))
		color = get_mlx_pixel_color(p, p->txt.no_txtr, ray->x_txt, y_color);
	else if (ray->hit_type == HORZ && is_facing_up(ray->angle) == FALSE)
		color = get_mlx_pixel_color(p, p->txt.so_txtr, ray->x_txt, y_color);
	else if (ray->hit_type == VERT && is_facing_right(ray->angle))
		color = get_mlx_pixel_color(p, p->txt.ea_txtr, ray->x_txt, y_color);
	else if (ray->hit_type == VERT && is_facing_right(ray->angle) == FALSE)
		color = get_mlx_pixel_color(p, p->txt.we_txtr, ray->x_txt, y_color);
	else
		return ;
	my_mlx_pixel_put(p, x, y, color);
}
