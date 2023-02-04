/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchahid <hchahid@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 13:06:57 by hchahid           #+#    #+#             */
/*   Updated: 2023/01/26 19:51:08 by hchahid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

bool	looking_up(double angle)
{
	if (angle >= PI)
		return (1);
	return (0);
}

bool	facing_right(double angle)
{
	if (angle <= (PI / 2) || angle >= 3 * (PI / 2))
		return (1);
	return (0);
}