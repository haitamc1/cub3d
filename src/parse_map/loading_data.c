/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loading_data.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arouzen <arouzen@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 12:05:38 by hchahid           #+#    #+#             */
/*   Updated: 2023/01/07 22:03:38 by arouzen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

int	get_clr(char *clr)
{
	char	**data;
	long	holder;
	int		rgb[3];
	int		i;

	i = 0;
	data = ft_split(clr, ',');
	// if (!data)
	// 	exit_msg("ERROR GETTING COLOR\n");
	if (ft_chardp_len(data) < 3) // && data[3][0] != '\n')
		exit_msg("INVALID COLOR\n");
	while (i < 3)
	{
		// if (data[i][j] && data[i][j] != '\n')
		// 	exit_msg("INVALID COLOR\n");
		// if (ft_isnum(data[i]) == FALSE)
		// 	exit_msg("INVALID COLOR NUMBER\n");
		rgb[i] = ft_atoi(data[i]);
		if (rgb[i] > 255 || rgb[i] < 0)
			exit_msg("COLOR OUT OF RGB RANGE\n");
		i++;
	}
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
	// while (is_space(s[i]))
	// 	i++;
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

// int	map_start(char *s)
// {
// 	int	i;

// 	i = 0;
// 	while (s[i])
// 	{
// 		if (s[i] == '0' || s[i] == '1')
// 		{
// 			if (s[i] == '0')
// 				return (1);
// 		}
// 		return (0);	
// 	}
// }

bool	filled_texture_check(t_texture s)
{
	if (s.ea_file && s.we_file && s.no_file && s.so_file \
		&& s.floor_clr != -1 && s.ceiling_clr != -1)
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
	int			fd;
	int			i;

	i = 0;
	fd = cub_fd(file);
	map = allocate_dp(map_line_count(fd));
	fd = cub_fd(file);
	map[i] = get_next_line(fd);
	while (map[i])
	{
		i++;
		map[i] = get_next_line(fd);
	}
	map[++i] = NULL;
	return (map);
}

void	get_texture(char *data, t_texture *check)
{
	char	**tmp;

	tmp = ft_split(data, ' '); //what if tabs?
	if (ft_chardp_len(tmp) != 2)
		exit_msg("ERROR GETTING TEXTURE\n");
	check_resource(tmp[0], tmp[1], check);
}

int	skip_space(char *s, int	i)
{
	while (is_space(s[i]))
		i++;
	return (i);
}

t_texture	check_map(char **map)
{
	t_texture	data;
	int			i;
	int			j;

	i = 0;
	j = 0;

	map = parse_resources(map);
	printf("|%s|", *map);
	printf("|%s|", *(map + 1));
	// if (!map[i])
	// 	exit_msg("INCOMPLETE MAP\n");
	// while (just_space(map[i]) || map[i][0] == '\n')
	// 		i++;
	// j = skip_space(map[i][j], j);
	// while (map[i][j] && !is_space(map[i][j]) && map[i][j] != '\n')
	// {
	// 	if (map[i][j] != '1')
	// 		exit_msg("MAP ERROR\n");
	// 	j++;
	// }
	// if (map[i][j] &&       map[i][j] != '\n')
	// 	exit_msg("MAP ERROR\n");
	// while (map[++i])
	// {
		
	// }
}