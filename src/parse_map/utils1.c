/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arouzen <arouzen@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/31 16:30:41 by hchahid           #+#    #+#             */
/*   Updated: 2023/01/06 17:27:00 by arouzen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void	str(char *s)
{
	int	i;

	i = 0;
	if (!s)
		return ;
	while (s[i])
		write (1, &s[i++], 1);
}

void	exit_msg(char *msg)
{
	str(msg);
	exit (0);
}


int	map_line_count(int fd)
{
	char	**map;
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


char	**allocate_dp(int	size)
{
	char	**dp;
	
	dp = malloc ((size + 1) * sizeof(char *));
	if (!dp)
		exit_msg("ERROR ALLOCATING MEMORY\n");
	dp[size] = NULL;
	return (dp);
}
