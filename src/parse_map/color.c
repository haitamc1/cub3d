/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arouzen <arouzen@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 12:16:44 by arouzen           #+#    #+#             */
/*   Updated: 2023/02/08 12:35:42 by arouzen          ###   ########.fr       */
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
