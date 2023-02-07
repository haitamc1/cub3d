/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arouzen <arouzen@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 20:23:37 by arouzen           #+#    #+#             */
/*   Updated: 2023/02/07 20:24:27 by arouzen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"


int	parse_map(t_ply	*p)
{
	int	x;

	x = 0;
	while (p->map[x])
	{
		parse_line(p, x);
		x++;
	}
	return (1);
}

void	parse_line(t_ply *p, int x)
{
	int			y;
	static int	ply_pos = 0;
	char		**map;

	y = 0;
	map = p->map;
	while (map[x][y])
	{
		if (is_valid_token(map[x][y]) == FALSE)
			exit_msg("INVALID TOKEN IN MAP\n");
		if (map[x][y] == ' ')
			check_space(map, x, y);
		else if (map[x][y] == '0')
			check_zero(map, x, y);
		else if (is_player_pos(map[x][y]))
		{
			set_player_pos(p, x, y);
			set_player_angle(p, map[x][y]);
			ply_pos += is_player_pos(map[x][y]);
		}
		y++;
	}
	if (map[x + 1] == NULL && ply_pos != 1)
		exit_msg("Player error\n");
}

void	check_space(char **map, int x, int y)
{
	if (y > 0 && (map[x][y - 1] != ' ' && map[x][y - 1] != '1'))
		(printf("SPACE ERR: 1\n"), exit_msg(&map[x][y]));
	if ((map[x][y + 1] != ' ' && map[x][y + 1] != '1'))
		(printf("SPACE ERR: 2\n"), exit_msg(&map[x][y]));
	if (ft_strlen(map[x - 1]) > y && (map[x - 1][y] != ' ' \
		&& map[x - 1][y] != '1'))
		(printf("SPACE ERR: 3\n"), exit_msg(&map[x][y]));
	if (ft_strlen(map[x + 1]) > y && (map[x + 1][y] != ' ' \
		&& map[x + 1][y] != '1'))
		(printf("SPACE ERR: 4\n"), exit_msg(&map[x][y]));
}

void	check_zero(char **map, int x, int y)
{
	if (y < 1)
		exit_msg("MAP ZERO\n");
	else if (map[x][y + 1] == '\0')
		exit_msg("MAP ZERO\n");
	else if (ft_strlen(map[x - 1]) <= y)
		exit_msg("MAP ZERO\n");
	else if (ft_strlen(map[x + 1]) <= y)
		exit_msg("MAP ZERO\n");
}
