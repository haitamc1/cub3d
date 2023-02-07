/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loading_data.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchahid <hchahid@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 12:05:38 by hchahid           #+#    #+#             */
/*   Updated: 2023/02/07 19:44:24 by hchahid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

int	get_clr(char *clr)
{
	char	**data;
	int		rgb[3];
	int		i;

	i = 0;
	data = ft_split(clr, ',');
	if (ft_chardp_len(data) < 3)
		exit_msg("INVALID COLOR\n");
	while (i < 3)
	{
		rgb[i] = ft_atoi(data[i]);
		if (rgb[i] > 255 || rgb[i] < 0)
			exit_msg("COLOR OUT OF RGB RANGE\n");
		i++;
	}
	ft_freesplit(data);
	return (get_rgb_color(rgb));
}

int	get_rgb_color(int *rgb)
{
	return ((rgb[0] << 16) + (rgb[1] << 8) + rgb[2]);
}

char	*get_texture_file(char *s)
{
	char	*path;
	int		begin;
	int		i;

	i = 0;
	if (!s[i] && s[i] != '\n')
		exit_msg("NO PATH WAS FOUND TO LOAD DATA FROM\n");
	begin = i;
	while (s[i] && s[i] != '\n' && !is_space(s[i]))
		i++;
	i--;
	path = ft_substr(s, begin, begin - i);
	if (!path)
		exit_msg("ERROR ALLOCATING MEMORY\n");
	return (path);
}

bool	filled_texture_check(t_texture *s)
{
	if (s->ea_file && s->we_file && s->no_file && s->so_file \
		&& s->floor_clr != -1 && s->ceiling_clr != -1)
		return (1);
	return (0);
}

bool	valid_map_part(char c)
{
	if (c == '1' || c == '0' || c == 'E' || c == 'S'
		 || c == 'N' || c == 'W')
		return (1);
	return (0);
}

char	**get_map(char *file)
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

void	get_texture(char *data, t_texture *check)
{
	char	**tmp;

	tmp = ft_split(data, ' ');
	if (ft_chardp_len(tmp) != 2)
		exit_msg("ERROR GETTING TEXTURE\n");
	check_resource(tmp[0], tmp[1], check);
	ft_freesplit(tmp);
}

int	skip_space(char *s, int	i)
{
	while (is_space(s[i]))
		i++;
	return (i);
}

void	check_map(t_ply *p, char **map)
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
	char 	**map;
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
	char 	*tmp;
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

char	*fill_space(char *line, int size)
{
	int		i;
	int		len;
	char	*buff;

	i = 0;
	buff = malloc(sizeof(char) * (size + 1));
	len = ft_strlen(line);
	while (i < size)
	{
		if (i < len)
			buff[i] = line[i];
		else
			buff[i] = '1';
		i++;
	}
	buff[i] = '\0';
	return (buff);
}

void	check_file_extension(char *file, char *extension)
{
	char	*str;
	// len = ft_strlen(file);
	// if (len < 5)
	// 	return (exit_msg("INVALID FILE\n"));
	str = ft_strnstr(file, extension, ft_strlen(file));
	if (str == NULL || ft_strlen(str) != ft_strlen(extension))
		exit_msg("INVALID FILE EXTENTION\n");
}
