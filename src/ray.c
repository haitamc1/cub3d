/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arouzen <arouzen@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 12:42:10 by arouzen           #+#    #+#             */
/*   Updated: 2023/01/15 16:27:43 by arouzen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	init_rays(t_ply *p, t_ray *ray)
{
	int		i;
	double	angle;
	double	angle_increment;
	t_point	p_pos;

	angle_increment = FOV / NUM_RAYS;
	angle = p->rotation_angle - (FOV / 2);
	p_pos = set_point(p->x, p->y);
	i = 0;
	while (i < NUM_RAYS)
	{
		ray[i].id = i;
		printf("angle for %d is {%.2f}\n", i, angle);
		angle = normalize_angle(angle);
		ray[i].angle = angle;
		ray[i].origin = p_pos;
		ray[i].hit_wall = get_wall_hit_point(p_pos, angle);
		printf("hit point for  %d y[%.2f]x[%.2f]\n", i, ray[i].hit_wall.y, ray[i].hit_wall.x);
		ray[i].distance = get_distance(p_pos, ray->hit_wall);
		angle += angle_increment;
		i++;
	}
}

void	render_ray_all(t_ply *p)
{
	int		i;
	t_ray	ray[NUM_RAYS];


	init_rays(p, ray);
	i = 0;
	while (i < NUM_RAYS)
	{
		render_ray(p, ray[i]);
		i++;
	}
}

void	render_ray(t_ply *p, t_ray ray)
{
	draw_line(p, ray.origin, ray.hit_wall);
}

t_bool	is_facing_up(double angle)
{
	if (angle >= PI)
		return (TRUE);
	return (FALSE);
}

t_bool	is_facing_right(double angle)
{
	if (angle < 0.5 * PI || angle > 1.5 * PI)
		return (TRUE);
	return (FALSE);
}