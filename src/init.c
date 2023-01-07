/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arouzen <arouzen@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 16:19:16 by arouzen           #+#    #+#             */
/*   Updated: 2023/01/07 16:25:20 by arouzen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	init_textures(t_texture *data)
{
	data->ea_file = NULL;
	data->so_file = NULL;
	data->no_file = NULL;
	data->we_file = NULL;
	data->floor_clr = -1;
	data->ceiling_clr = -1;
}