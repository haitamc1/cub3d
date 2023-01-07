/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_resource.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arouzen <arouzen@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 16:07:31 by arouzen           #+#    #+#             */
/*   Updated: 2023/01/07 17:42:51 by arouzen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

char **parse_resources(char **map)
{
	int			i;
	t_texture	data;

	i = 0;
	while (!filled_texture_check(data) && map[i])
	{
		if (just_space(map[i]) || map[i][0] == '\n')
			i++;
		else
			get_texture(map[i++], &data);
	}
	return (map[i]);
}