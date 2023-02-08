/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arouzen <arouzen@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 12:15:33 by arouzen           #+#    #+#             */
/*   Updated: 2023/02/08 12:50:30 by arouzen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

bool	filled_texture_check(t_texture *s)
{
	if (s->ea_file && s->we_file && s->no_file && s->so_file \
		&& s->floor_clr != -1 && s->ceiling_clr != -1)
		return (1);
	return (0);
}

char	*get_texture_file(char *s)
{
	char	*path;
	int		begin;
	int		i;

	i = 0;
	if (!s[i] && s[i] != '\n')
		exit_msg("NO PATH WAS FOUND TO LOAD DATA FROM\n");
	begin = i;
	while (s[i] && s[i] != '\n' && !is_space(s[i]))
		i++;
	i--;
	path = ft_substr(s, begin, begin - i);
	if (!path)
		exit_msg("ERROR ALLOCATING MEMORY\n");
	return (path);
}

void	get_texture(char *data, t_texture *check)
{
	char	**tmp;

	tmp = ft_split(data, ' ');
	if (ft_chardp_len(tmp) != 2)
		exit_msg("ERROR GETTING TEXTURE\n");
	check_resource(tmp[0], tmp[1], check);
	ft_freesplit(tmp);
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
