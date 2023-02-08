/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arouzen <arouzen@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 12:22:30 by arouzen           #+#    #+#             */
/*   Updated: 2023/02/08 12:22:48 by arouzen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

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