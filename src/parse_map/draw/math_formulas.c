/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math_formulas.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchahid <hchahid@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/31 13:33:06 by hchahid           #+#    #+#             */
/*   Updated: 2023/01/27 19:32:03 by hchahid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/cub3d.h"

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
 
void	horizontal_intersection(t_ply *p, t_intersection *data, double angle)
{
	data->horizontal_y = floor(p->y / TILE_SIZE) * TILE_SIZE;
	if (!looking_up(angle))
		data->horizontal_y += TILE_SIZE;
	data->horizontal_x = p->x + (data->horizontal_y - p->y) / tan(angle);
	data->y_step_hoz = TILE_SIZE;
	if (looking_up(angle))
	{
		data->y_step_hoz *= -1;
		// // data->y_step_hoz -= 1;
		// data->horizontal_y -= 1;
	}
	// else
	// 	data->horizontal_y += 1;
		// data->y_step_hoz += 1;
	data->x_step_hoz = TILE_SIZE / tan (angle);
	if ((facing_right(angle) && data->x_step_hoz < 0)
		|| (!facing_right(angle) && data->x_step_hoz > 0))
		data->x_step_hoz *= -1;
// 	printf("point.x = %f| point.y = %f\n", data->horizontal_x, data->horizontal_y);
// 	printf("step.x = %f| step.y = %f\n", data->x_step_hoz, data->y_step_hoz);
}

void	vertical_intersection(t_ply *p, t_intersection *data, double angle)
{
	data->vertical_x = floor(p->x / TILE_SIZE) * TILE_SIZE;
	data->x_step_vrt = TILE_SIZE;
	if (facing_right(angle))
		data->vertical_x += TILE_SIZE;
	else
		data->x_step_vrt *= -1;
	data->vertical_y = p->y + (data->vertical_x - p->x) * tan (angle);
	data->y_step_vrt = tan(angle) * TILE_SIZE;
	if ((looking_up(angle) && data->y_step_vrt > 0)
		|| (!looking_up(angle) && data->y_step_vrt < 0))
		data->y_step_vrt *= -1;
	// if (!facing_right(angle))
	// 	data->vertical_x -= 1;
}
