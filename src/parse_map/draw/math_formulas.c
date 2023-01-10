/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math_formulas.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchahid <hchahid@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/31 13:33:06 by hchahid           #+#    #+#             */
/*   Updated: 2023/01/10 12:21:32 by hchahid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

double	pythagore(double adjacent, double opposite)
{
	return (sqrt(pow(opposite, 2) + pow(adjacent, 2)));
}

double	ray_lenght(double ray_x, double ray_y, double player_x, double player_y)
{
	return (sqrt(pow(ray_x - player_x, 2) + pow(ray_y - player_y, 2)));
}
