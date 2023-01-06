/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arouzen <arouzen@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 18:48:26 by hchahid           #+#    #+#             */
/*   Updated: 2023/01/06 17:16:01 by arouzen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

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
