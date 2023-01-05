/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchahid <hchahid@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 20:01:09 by hchahid           #+#    #+#             */
/*   Updated: 2023/01/04 19:49:31 by hchahid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_strcmp(const char *s1, const char *s2)
{
	int	len1;
	int	len2;
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (s1 == NULL || s2 == NULL)
		return (1);
	len1 = ft_strlen (s1);
	len2 = ft_strlen (s2);
	if (len1 != len2)
		return (1);
	else
		j = len2;
	while (i < j)
	{
		if (s1[i] == s2[i])
			i++;
		else
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
	}
	return (0);
}

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

int	is_space(char c)
{
	if (c == '\t' || c == '\n' || c == ' ' || c == '\v'
		|| c == '\f' || c == '\r')
		return (1);
	return (0);
}

int	just_space(char *s)
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
