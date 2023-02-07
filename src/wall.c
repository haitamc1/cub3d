/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wall.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arouzen <arouzen@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 12:43:42 by arouzen           #+#    #+#             */
/*   Updated: 2023/02/07 19:21:48 by arouzen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

t_bool	has_wall(t_ply *p, double x, double y, t_bool corner_check)
{
	int		xcheck;
	int		ycheck;
	char	**map;

	map = p->map;
	xcheck = floor(x / TILE_SIZE);
	ycheck = floor(y / TILE_SIZE);
	if (xcheck < 0 || ycheck < 0 || ycheck > p->y_map || xcheck > p->x_map)
		return (TRUE);
	if (map[ycheck][xcheck] == '1')
		return (TRUE);
	if (corner_check == TRUE)
		return (wall_corner_check(p, ycheck, xcheck));
	return (FALSE);
}

t_bool	wall_corner_check(t_ply *p, int ycheck, int xcheck)
{
	char	**map;

	map = p->map;
	if (is_facing_right(p->rotation_angle) && is_facing_up(p->rotation_angle) \
		&& xcheck - 1 >= 0 && ycheck + 1 <= p->y_map && \
		map[ycheck][xcheck - 1] == '1' && map[ycheck + 1][xcheck] == '1')
		return (TRUE);
	if (is_facing_right(p->rotation_angle) && !is_facing_up(p->rotation_angle) \
		&& ycheck - 1 >= 0 && xcheck - 1 >= 0 && \
		map[ycheck - 1][xcheck] == '1' && map[ycheck][xcheck - 1] == '1')
		return (TRUE);
	if (!is_facing_right(p->rotation_angle) && is_facing_up(p->rotation_angle) \
		&& ycheck + 1 <= p->y_map && xcheck + 1 <= p->x_map && \
		map[ycheck + 1][xcheck] == '1' && map[ycheck][xcheck + 1] == '1' )
		return (TRUE);
	if (!is_facing_right(p->rotation_angle) && !is_facing_up(p->rotation_angle) \
		&& ycheck - 1 >= 0 && xcheck + 1 <= p->x_map && \
		map[ycheck - 1][xcheck] == '1' && map[ycheck][xcheck + 1] == '1' )
		return (TRUE);
	return (FALSE);
}
