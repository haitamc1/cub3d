/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arouzen <arouzen@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 18:43:24 by hchahid           #+#    #+#             */
/*   Updated: 2023/01/06 17:15:53 by arouzen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	init(t_ply *p)
{
	p->mlx = mlx_init();
	p->win = mlx_new_window(p->mlx, WIDTH, HEIGHT, "CUB3D");
	p->img = mlx_new_image(p->mlx, WIDTH, HEIGHT);
	p->addr = mlx_get_data_addr(p->img, &p->bits_per_pixel,
			&p->line_length, &p->endian);
}

int	cub_fd(char *file_name)
{
	int	fd;

	fd = open (file_name, O_RDWR, 0644);
	if (fd < 0)
		exit_msg("COULD NOT OPEN FILE\n");
	return (fd);
}

void	load_textures(bool *direction, char **file, char *description)
{
	*direction = true;
	*file = get_texture(description);
}

void	load_colors(bool *space, int *clr, char *description)
{
	*space = true;
	*clr = get_clr(description);
}

void	check_space(char *direction, char *description, t_texture *check)
{
	if (!ft_strcmp(direction, "EA") && !check->ea)
		return (load_textures(&check->ea, &check->ea_file, description));
	if (!ft_strcmp(direction, "WE") && !check->we)
		return (load_textures(&check->we, &check->we_file, description));
	if (!ft_strcmp(direction, "NO") && !check->no)
		return (load_textures(&check->no, &check->no_file, description));
	if (!ft_strcmp(direction, "SO") && !check->so)
		return (load_textures(&check->so, &check->so_file, description));
	if (!ft_strcmp(direction, "F") && !check->floor)
		return (load_colors(&check->floor, &check->floor_clr, description));
	if (!ft_strcmp(direction, "C") && !check->ceiling)
		return (load_colors(&check->ceiling, &check->ceiling_clr, description));
	exit_msg("MAP ERROR\n");
}

void	check_file_extention(char *file)
{
	int	len;

	len = ft_strlen(file);
	if (len < 5)
		return (exit_msg("INVALID FILE\n"));
	if (ft_strcmp((file + len - 4), ".cub"))
		return (exit_msg("INVALID FILE EXTENTION\n"));
}

int	main(int ac, char **av)
{
	t_ply	p;

	if (ac == 2)
	{
		check_file_extention(av[1]);
		init(&p);
		mlx_hook(p.win, 17, 0, &cross, &p);
		mlx_hook(p.win, 2, 1L << 0, &key, &p);
		mlx_loop(p.mlx);
	}
	else
		str("INVALID NUMBER OF ARGUMENTS\n");
}
