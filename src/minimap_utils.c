/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchahid <hchahid@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 21:28:04 by hchahid           #+#    #+#             */
/*   Updated: 2023/02/07 21:28:25 by hchahid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int	correct_value_i(int init, int failure)
{
	int	r;

	r = init;
	if (r < failure)
		r = failure;
	return (r);
}

int	correct_value_s(int init, int failure)
{
	int	r;

	r = init;
	if (r > failure)
		r = failure;
	return (r);
}
