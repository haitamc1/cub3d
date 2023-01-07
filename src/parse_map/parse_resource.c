/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_resource.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arouzen <arouzen@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 16:07:31 by arouzen           #+#    #+#             */
/*   Updated: 2023/01/07 22:55:48 by arouzen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

char **parse_resources(char **map)
{
	int			i;

	i = 0;
	while (!filled_texture_check(data) && map[i])
	{
		if (just_space(map[i]) || map[i][0] == '\n')
			i++;
		else
			get_texture(map[i++], &data);
	}
	while (map[i] && (just_space(map[i]) || map[i][0] == '\n'))
		i++;
	return (&map[i]);
}

int	parse_map(char **map)
{
	int	i;

	i = 0;
	while (map[i])
		parse_line(map[i]);
}

void	parse_line(char *line)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (line[i] == ' ');
			check_space(line[i], i);
	}
}

void	check_space(char *map, int pos)
{
	if (pos > 0 && (*(map - 1) != ' ' || *(map - 1) != '1'))
		exit_msg("MAP SPACE\n");
	if (map[1] && (*(map + 1) == ' ' || *(map + 1) == '1'))
		exit_msg("MAP SPACE\n");
	if (map[1] && (*(map + 1) == ' ' || *(map + 1) == '1'))
		exit_msg("MAP SPACE\n");
	
}