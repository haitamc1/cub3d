/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchahid <hchahid@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 21:30:02 by hchahid           #+#    #+#             */
/*   Updated: 2023/02/07 21:35:07 by hchahid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	my_mlx_pixel_put(t_ply *p, int x, int y, int color)
{
	char	*dst;

	dst = p->addr + (y * p->line_length + x * (p->bits_per_pixel / 8));
	*(unsigned int *) dst = color;
}

int	get_mlx_pixel_color(t_ply *p, char *txt, int x, int y)
{
	char	*dst;

	dst = txt + (y * p->txt.len + x * (p->txt.bpp / 8));
	return (*(unsigned int *) dst);
}

double	normalize_angle(double angle)
{
	double	new_angle;

	new_angle = fmod(angle, 2 * PI);
	if (new_angle < 0)
		return ((2 * PI) + new_angle);
	return (new_angle);
}
