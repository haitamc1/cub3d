/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arouzen <arouzen@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 12:18:53 by arouzen           #+#    #+#             */
/*   Updated: 2023/02/08 12:35:49 by arouzen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

t_bool	is_valid_token(char c)
{
	if (c == '0' || c == '1' || c == ' ' || \
		c == 'N' || c == 'S' || c == 'E' || c == 'W')
		return (TRUE);
	return (FALSE);
}

int	cub_fd(char *file_name)
{
	int	fd;

	fd = open (file_name, O_RDONLY);
	if (fd < 0)
		exit_msg("COULD NOT OPEN FILE\n");
	return (fd);
}
