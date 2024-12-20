/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arouzen <arouzen@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 19:29:11 by arouzen           #+#    #+#             */
/*   Updated: 2023/02/08 23:33:00 by arouzen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int	main(int ac, char **av)
{
	t_ply	p;

	if (ac == 2)
	{
		init_values(&p);
		init_textures(&p.txt);
		check_map(&p, av[1]);
		load_textures(&p);
		draw_map(&p);
		mlx_put_image_to_window(p.mlx, p.win, p.img, 0, 0);
		mlx_hook(p.win, 17, 0L, &cross, &p);
		mlx_hook(p.win, 2, 0L, &key, &p);
		mlx_mouse_hook(p.win, &mouse_hook, &p);
		mlx_loop(p.mlx);
	}
	else
		str("INVALID NUMBER OF ARGUMENTS\n");
}
