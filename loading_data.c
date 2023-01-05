/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loading_data.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchahid <hchahid@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 12:05:38 by hchahid           #+#    #+#             */
/*   Updated: 2023/01/04 19:51:43 by hchahid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

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
	if (arg_len(data) != 3)
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

char	*get_texture(char *s)
{
	char	*path;
	int		begin;
	int		i;

	i = 0;
	while (is_space(s[i]))
		i++;
	if (!s[i])
		exit_msg("NO PATH WAS FOUND TO LOAD DATA FROM\n");
	begin = i;
	while (s[i] && s[i] != '\n')
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

int	filled_texture_check(t_texture s)
{
	if (s.ea && s.we && s.no && s.so && s.floor && s.ceiling)
		return (1);
	return (0);
}

int	valid_map_part(char c)
{
	if (c == '1' || c == '0' || c == 'E' || c == 'S'
		 || c == 'N' || c == 'W')
		return (1);
	return (0);
}

void	map(char *s)
{
	int	i;

	i = 0;
	while (s[i] && is_space(s[i]))
		i++;
}

char	**get_map(int fd)
{
	char	**map;
	char	**data;
	char	*line;
	t_texture	check;

	line = get_next_line(fd);
	if (!line)
		exit_msg("EMPTY MAP FILE\n");
	while (line)
	{
		free(line);
		if (!filled_space_check(check))
		{
			line = get_next_line(fd);
			data = ft_split(line, ' ');
			check_space(line[0], line[1], &check);
			free(line);
			free_dp(data);
		}
		else
		{
			if (just_space(line) || line[0] == 0)
				line = get_next_line(fd);
			else
			{
				
			}
			
		}
	}
	return (map);
}
