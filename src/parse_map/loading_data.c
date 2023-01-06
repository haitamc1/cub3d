/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loading_data.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchahid <hchahid@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 12:05:38 by hchahid           #+#    #+#             */
/*   Updated: 2023/01/06 19:04:44 by hchahid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

int	get_clr(char *clr)
{
	char	**data;
	long	holder;
	int		j;
	int		i;

	i = 0;
	data = ft_split(clr, ',');
	if (!data)
		exit_msg("ERROR ALLOCATING MEMORY\n");
	if (arg_len(data) != 3 && data[3][0] != '\n')
		exit_msg("INVALID COLOR\n");
	while (data[i])
	{
		j = 0;
		while (data[i][j] && ft_isdigit(data[i][j]))
			j++;
		if (data[i][j] && data[i][j] != '\n')
			exit_msg("INVALID COLOR\n");
		holder = ft_atoi(data[i++]);
		if (holder > 255 || holder < 0)
			exit_msg("COLOR OUT OF RGB RANGE\n");
	}
	return ((ft_atoi(data[0]) << 16) + (ft_atoi(data[1]) << 8) + (ft_atoi(data[2])));
}

char	*get_texture_file(char *s)
{
	char	*path;
	int		begin;
	int		i;

	i = 0;
	while (is_space(s[i]))
		i++;
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
	if (s.ea && s.we && s.no && s.so && s.floor && s.ceiling)
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
	return (map);
}

void	get_texture(char *data, t_texture *check)
{
	char	**tmp;

	tmp = ft_split(data, ' ');
	if (!tmp)
		exit_msg("ERROR ALLOCATING MEMORY\n");
	check_space(tmp[0], tmp[1], check);
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
	while (!filled_texture_check(data) && map[i])
	{
		if (just_space(map[i]) || map[i][0] == '\n')
			i++;
		else
			get_texture(map[i++], &data);
	}
	if (!map[i])
		exit_msg("INCOMPLETE MAP\n");
	while (just_space(map[i]) || map[i][0] == '\n')
			i++;
	j = skip_space(map[i][j], j);
	while (map[i][j] && !is_space(map[i][j]) && map[i][j != '\n'])
	{
		if (map[i][j] != '1')
			exit_msg("MAP ERROR\n");
		j++;
	}
	if (map[i][j] && map[i][j] != '\n')
		exit_msg("MAP ERROR\n");
	while (map[++i])
	{
		
	}
}