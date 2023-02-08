/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arouzen <arouzen@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 19:24:54 by arouzen           #+#    #+#             */
/*   Updated: 2023/02/08 22:57:19 by arouzen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	print_map(char **map)
{
	int	x;
	int	y;

	y = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			printf("%c", map[y][x]);
			x++;
		}
		printf("\n");
		y++;
	}
}

void	print_player_info(t_ply *p)
{
	printf("player y[%d]x[%d]\n", (int)(p->y / TILE_SIZE), \
	(int)(p->x / TILE_SIZE));
	printf("in map x = %f| y = %f\n", p->x, p->y);
	printf("angle [%.2f]\n", (p->rotation_angle * 180) / PI);
	printf("map[%d][%d]\n", p->y_map, p->x_map);
}
