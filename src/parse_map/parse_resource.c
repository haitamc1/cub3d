/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_resource.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arouzen <arouzen@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 16:07:31 by arouzen           #+#    #+#             */
/*   Updated: 2023/02/07 20:24:53 by arouzen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

char	**parse_resources(t_ply *p, char **map)
{
	int			i;

	i = 0;
	while (!filled_texture_check(&p->txt) && map[i])
	{
		if (just_space(map[i]) || map[i][0] == '\n')
			i++;
		else
			get_texture(map[i++], &p->txt);
	}
	while (map[i] && (just_space(map[i]) || map[i][0] == '\n'))
	{
		i++;
	}
	return (&map[i]);
}


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
