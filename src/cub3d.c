/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arouzen <arouzen@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 18:43:24 by hchahid           #+#    #+#             */
/*   Updated: 2023/01/07 18:20:44 by arouzen          ###   ########.fr       */
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

	fd = open (file_name, O_RDONLY);
	if (fd < 0)
		exit_msg("COULD NOT OPEN FILE\n");
	return (fd);
}

void	load_textures(bool *direction, char **file, char *description)
{
	*file = description;
	//*file = get_texture_file(description);
}

// void	load_colors(bool *space, int *clr, char *description)
// {
// 	*space = true;
// 	*clr = get_clr(description);
// }

void	check_space(char *direction, char *path, t_texture *check)
{
	if (!ft_strcmp(direction, "EA") && check->ea_file)
		check->ea_file = path;
	else if (!ft_strcmp(direction, "WE") && check->we_file)
		check->we_file = path;
	else if (!ft_strcmp(direction, "NO") && check->no_file)
		check->no_file = path;
	else if (!ft_strcmp(direction, "SO") && check->so_file)
		check->so_file = path;
	else if (!ft_strcmp(direction, "F") && check->floor_clr == -1)
		check->floor_clr = get_clr(path);
	else if (!ft_strcmp(direction, "C") && check->ceiling_clr == -1)
		check->ceiling_clr = get_clr(path);
	else
		exit_msg("MAP ERROR\n");
}

void	check_file_extension(char *file, char *extension)
{
	char	*str;
	// len = ft_strlen(file);
	// if (len < 5)
	// 	return (exit_msg("INVALID FILE\n"));
	str = ft_strnstr(file, extension, ft_strlen(file));
	if (str == NULL || ft_strlen(str) != ft_strlen(extension))
		exit_msg("INVALID FILE EXTENTION\n");
}
