/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_resource.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arouzen <arouzen@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 16:07:31 by arouzen           #+#    #+#             */
/*   Updated: 2023/01/23 21:12:47 by arouzen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

char **parse_resources(t_ply *p, char **map)
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
		i++;
	return (&map[i]);
}

int	parse_map(char **map)
{
	int	x;

	x = 0;
	while (map[x])
	{
		parse_line(map, x);
		//printf("%s\n", map[x]);
		x++;
		//break ;

	}
	return (1);
}

void	parse_line(char **map, int x)
{
	int			y;
	static int	ply_pos = 0;

	y = 0;
	while (map[x][y])
	{
		//printf("%c", map[x][y]);
		if (is_valid_token(map[x][y]) == FALSE)
		{
			exit_msg("INVALID TOKEN IN MAP\n");
		}
		if (map[x][y] == ' ')
			check_space(map, x, y);
		else if (map[x][y] == '0')
			check_zero(map, x, y);
		// if (map[x][y] == '0');
		// 	check_space(map, x, y);
		else if (is_player_pos(map[x][y]))
		{
			//check_player(map, x, y);
			ply_pos += is_player_pos(map[x][y]);
		}
		y++;
	}
	if (map[x + 1] == NULL && ply_pos != 1)
		exit_msg("Player error\n");
}

void	check_space(char **map, int x, int y)
{
	// printf("Check space [%d][%d]\n", x, y);
	// printf("map [%s]\n", map[x - 1]);
	if (y > 0 && (map[x][y - 1] != ' ' &&  map[x][y - 1] != '1'))
		(printf("SPACE ERR: 1\n"), exit_msg(&map[x][y]));
	//	return ;
	if ((map[x][y + 1] != ' ' &&  map[x][y + 1] != '1'))
		(printf("SPACE ERR: 2\n"), exit_msg(&map[x][y]));
	//	return ;
	if (ft_strlen(map[x - 1]) > y && (map[x - 1][y] != ' ' &&  map[x - 1][y] != '1'))
		(printf("SPACE ERR: 3\n"), exit_msg(&map[x][y]));
	//	return ;
	if (ft_strlen(map[x + 1]) > y && (map[x + 1][y] != ' ' &&  map[x + 1][y] != '1'))
		(printf("SPACE ERR: 4\n"), exit_msg(&map[x][y]));
	//	return ;
	//exit_msg(&map[x][y]);
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

