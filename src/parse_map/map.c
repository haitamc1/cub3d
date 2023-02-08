/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arouzen <arouzen@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 12:13:53 by arouzen           #+#    #+#             */
/*   Updated: 2023/02/08 12:26:08 by arouzen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void	get_map(t_ply *p, char *file)
{
	char		**map;
	char		*tmp;
	int			fd;
	int			i;

	check_file_extension(file, ".cub");
	i = 0;
	fd = cub_fd(file);
	map = allocate_dp(map_line_count(fd));
	fd = cub_fd(file);
	tmp = get_next_line(fd);
	map[i] = ft_strtrim(tmp, "\n");
	free (tmp);
	while (map[i])
	{
		i++;
		tmp = get_next_line(fd);
		map[i] = ft_strtrim(tmp, "\n");
		free(tmp);
	}
	map[++i] = NULL;
	p->map_raw = map;
}

void	check_map(t_ply *p, char *map_file)
{
	get_map(p, map_file);
	p->map = parse_resources(p, p->map_raw);
	get_map_xy(p);
	get_full_map(p);
	parse_map(p);
}

void	get_map_xy(t_ply *p)
{
	int		x;
	int		y;
	char	**map;
	int		x_max;

	map = p->map;
	y = 0;
	x_max = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			x++;
		}
		if (x > x_max)
			x_max = x;
		y++;
	}
	p->x_map = x_max;
	p->y_map = y - 1;
}

void	get_full_map(t_ply *p)
{
	int		y;
	char	*tmp;
	char	**map;

	y = 0;
	map = p->map;
	while (map[y])
	{
		tmp = map[y];
		map[y] = fill_space(map[y], p->x_map);
		free(tmp);
		y++;
	}
}

int	map_line_count(int fd)
{
	char	*line;
	int		count;

	count = 1;
	line = get_next_line(fd);
	if (!line)
		exit_msg("EMPTY MAP FILE\n");
	free(line);
	while (line)
	{
		line = get_next_line(fd);
		free(line);
		count++;
	}
	close(fd);
	return (count);
}
