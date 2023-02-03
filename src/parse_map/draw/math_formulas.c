/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math_formulas.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchahid <hchahid@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/31 13:33:06 by hchahid           #+#    #+#             */
/*   Updated: 2023/01/13 14:25:31 by hchahid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

double	pythagore(double adjacent, double opposite)
{
	return (sqrt(pow(opposite, 2) + pow(adjacent, 2)));
}

double	ray_lenght(double ray_x, double ray_y, double player_x, double player_y)
{
	return (pythagore(ray_x - player_x, ray_y - player_y));
}

 // for floored_value used int so that the value we get gets floored but it will not work if 
 // the tile size was double or float
 
void	horizontal_intersection(t_ply *p, t_intersection data)
{
	int	floored_value;

	data.horizontal_y = p->y / TILE_SIZE;
	data.horizontal_y *= TILE_SIZE;
	data.horizontal_x = p->x + (p->y - data.horizontal_y) / tan(p->rotation_angle);
	data.y_step_hoz = TILE_SIZE;
	data.x_step_hoz = TILE_SIZE / tan (p->rotation_angle);
	
}

void	vertical_intersection(t_ply *p, t_intersection data)
{
	data.x_step_vrt = TILE_SIZE;
	data.y_step_vrt = tan(p->rotation_angle) * TILE_SIZE;
}
