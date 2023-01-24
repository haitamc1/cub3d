/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arouzen <arouzen@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 12:44:09 by arouzen           #+#    #+#             */
/*   Updated: 2023/01/24 16:12:40 by arouzen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

int	cub_fd(char *file_name)
{
	int	fd;

	fd = open (file_name, O_RDONLY);
	if (fd < 0)
		exit_msg("COULD NOT OPEN FILE\n");
	return (fd);
}

void	check_resource(char *direction, char *path, t_texture *check)
{
	if (!ft_strcmp(direction, "EA") && !check->ea_file)
		check->ea_file = ft_strtrim(path, "\n");
	else if (!ft_strcmp(direction, "WE") && !check->we_file)
		check->we_file = ft_strtrim(path, "\n");
	else if (!ft_strcmp(direction, "NO") && !check->no_file)
		check->no_file = ft_strtrim(path, "\n");
	else if (!ft_strcmp(direction, "SO") && !check->so_file)
		check->so_file = ft_strtrim(path, "\n");
	else if (!ft_strcmp(direction, "F") && check->floor_clr == -1)
		check->floor_clr = get_clr(path);
	else if (!ft_strcmp(direction, "C") && check->ceiling_clr == -1)
		check->ceiling_clr = get_clr(path);
	else
		exit_msg("MAP ERROR\n");
}

void	load_textures(t_ply *p)
{
	p->txt.no_txtr = get_txtr(p, p->txt.no_file);
	p->txt.so_txtr = get_txtr(p, p->txt.so_file);
	p->txt.ea_txtr = get_txtr(p, p->txt.ea_file);
	p->txt.we_txtr = get_txtr(p, p->txt.we_file);
}

char	*get_txtr(t_ply *p, char *file)
{
	int		len;
	int		width;
	int		height;
	char	*addr;
	void	*img;

	img = mlx_xpm_file_to_image(p->mlx, file, &width, &height);
	if (img == NULL)
		exit_msg("Importing texture error\n");
	if (width != TILE_SIZE || height != TILE_SIZE)
		exit_msg("Texture lenght and height should match TILE_SIZE\n ");
	addr = mlx_get_data_addr(img, &p->txt.bpp, &p->txt.len, &p->endian);
	if (addr == NULL)
		exit_msg("Importing texture error\n ");
	return (addr);
}