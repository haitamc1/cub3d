/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arouzen <arouzen@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 20:01:09 by hchahid           #+#    #+#             */
/*   Updated: 2023/01/06 17:20:21 by arouzen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

int	arg_len(char **s)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i])
		i++;
	return (i);
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

void	free_dp(char **s)
{
	int	i;

	i = 0;
	if (!s)
		return ;
	while (s[i])
		free(s[i++]);
	free(s);
}
