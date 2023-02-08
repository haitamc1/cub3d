/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arouzen <arouzen@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 12:18:18 by arouzen           #+#    #+#             */
/*   Updated: 2023/02/08 12:26:29 by arouzen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void	check_file_extension(char *file, char *extension)
{
	char	*str;

	str = ft_strnstr(file, extension, ft_strlen(file));
	if (str == NULL || ft_strlen(str) != ft_strlen(extension))
		exit_msg("INVALID FILE EXTENTION\n");
}

char	**allocate_dp(int size)
{
	char	**dp;

	dp = malloc ((size + 1) * sizeof(char *));
	if (!dp)
		exit_msg("ERROR ALLOCATING MEMORY\n");
	return (dp);
}

