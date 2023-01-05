/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchahid <hchahid@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 18:48:26 by hchahid           #+#    #+#             */
/*   Updated: 2022/12/30 17:48:43 by hchahid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int key(int key, t_ply *p)
{
	if (key == ESC)
	{
		mlx_destroy_window(p->mlx, p->win);
		exit (0);
	}
}

int	cross(t_ply *p)
{
	mlx_destroy_window(p->mlx, p->win);
	exit(0);
}
