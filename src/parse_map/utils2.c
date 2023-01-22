/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arouzen <arouzen@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 12:44:09 by arouzen           #+#    #+#             */
/*   Updated: 2023/01/22 12:44:45 by arouzen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

int	cub_fd(char *file_name)
{
	int	fd;

	fd = open (file_name, O_RDONLY);
	if (fd < 0)
		exit_msg("COULD NOT OPEN FILE\n");
	return (fd);
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
