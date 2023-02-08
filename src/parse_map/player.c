/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arouzen <arouzen@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 12:23:17 by arouzen           #+#    #+#             */
/*   Updated: 2023/02/08 12:31:17 by arouzen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void	set_player_pos(t_ply *p, int x, int y)
{
	p->x = (y + 1) * TILE_SIZE - TILE_SIZE / 2;
	p->y = (x + 1) * TILE_SIZE - TILE_SIZE / 2;
}

void	set_player_angle(t_ply *p, char c)
{
	if (c == 'N')
		p->rotation_angle = (PI / 180) * 270;
	else if (c == 'S')
		p->rotation_angle = (PI / 180) * 90;
	else if (c == 'E')
		p->rotation_angle = (PI / 180) * 0;
	else if (c == 'W')
		p->rotation_angle = (PI / 180) * 180;
}

t_bool	is_player_pos(char c)
{
	if (c == 'N' || c == 'S' || c == 'E' || c == 'W')
		return (TRUE);
	return (FALSE);
}
