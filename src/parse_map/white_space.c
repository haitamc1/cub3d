/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   white_space.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arouzen <arouzen@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 12:24:41 by arouzen           #+#    #+#             */
/*   Updated: 2023/02/08 12:25:11 by arouzen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

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

bool	is_space(char c)
{
	if (c == '\t' || c == '\n' || c == ' ' || c == '\v'
		|| c == '\f' || c == '\r')
		return (1);
	return (0);
}

bool	just_space(char *s)
{
	int	i;

	i = 0;
	while (s[i] && is_space(s[i]))
		i++;
	if (s[i] && s[i] != '\n')
		return (0);
	return (1);
}
