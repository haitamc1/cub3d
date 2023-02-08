/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wall.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arouzen <arouzen@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 12:43:42 by arouzen           #+#    #+#             */
/*   Updated: 2023/02/08 22:52:12 by arouzen          ###   ########.fr       */
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
	if (xcheck < 0 || ycheck < 0 || ycheck >= p->y_map || xcheck >= p->x_map)
		return (TRUE);
	if (map[ycheck][xcheck] == '1')
		return (TRUE);
	if (corner_check == TRUE)
		return (wall_corner_check(p, y, x));
	return (FALSE);
}

t_bool	wall_corner_check(t_ply *p, double ycheck, double xcheck)
{
	char	**map;

	map = p->map;
	if (is_facing_right(p->rotation_angle) && is_facing_up(p->rotation_angle))
		return (has_wall(p, xcheck + 15, ycheck, FALSE));
	if (is_facing_right(p->rotation_angle) && !is_facing_up(p->rotation_angle))
		return (has_wall(p, xcheck + 15, ycheck, FALSE));
	if (!is_facing_right(p->rotation_angle) && is_facing_up(p->rotation_angle))
		return (has_wall(p, xcheck + 15, ycheck, FALSE));
	if (!is_facing_right(p->rotation_angle) && !is_facing_up(p->rotation_angle))
		return (has_wall(p, xcheck + 15, ycheck, FALSE));
	return (FALSE);
}
