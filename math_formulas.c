/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math_formulas.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchahid <hchahid@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/31 13:33:06 by hchahid           #+#    #+#             */
/*   Updated: 2022/12/31 13:35:21 by hchahid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

double	pythagore(double adjacent, double opposite)
{
	return (sqrt(pow(opposite, 2) + pow(adjacent, 2)));
}