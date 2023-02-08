/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resource.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arouzen <arouzen@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 16:07:31 by arouzen           #+#    #+#             */
/*   Updated: 2023/02/08 12:28:10 by arouzen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

char	**parse_resources(t_ply *p, char **map)
{
	int	i;

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

void	check_resource(char *direction, char *path, t_texture *check)
{
	if (!ft_strcmp(direction, "EA") && !check->ea_file)
		check->ea_file = ft_strtrim(path, "\n");
	else if (!ft_strcmp(direction, "WE") && !check->we_file)
		check->we_file = ft_strtrim(path, "\n");
	else if (!ft_strcmp(direction, "NO") && !check->no_file)
		check->no_file = ft_strtrim(path, "\n");
	else if (!ft_strcmp(direction, "SO") && !check->so_file)
		check->so_file = ft_strtrim(path, "\n");
	else if (!ft_strcmp(direction, "F") && check->floor_clr == -1)
		check->floor_clr = get_clr(path);
	else if (!ft_strcmp(direction, "C") && check->ceiling_clr == -1)
		check->ceiling_clr = get_clr(path);
	else
		exit_msg("MAP ERROR\n");
}
