/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchahid <hchahid@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 18:43:24 by hchahid           #+#    #+#             */
/*   Updated: 2023/01/08 18:38:48 by hchahid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int	MAP_ROWS = 15;
int	MAP_COLS = 15;

int		grid[15][15] = {
            {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
            {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1},
            {1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 1},
            {1, 1, 1, 1, 0, 2, 0, 0, 0, 0, 1, 0, 1, 0, 1},
            {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 1},
            {1, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 0, 1},
            {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
            {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
            {1, 1, 1, 1, 1, 1, 0, 0, 0, 1, 1, 1, 1, 0, 1},
            {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
            {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
            {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 1},
            {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 1},
            {1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 1},
            {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1}
				};

void	my_mlx_pixel_put(t_ply *p, int x, int y, int color)
{
	char	*dst;

	dst = p->addr + (y * p->line_length + x * (p->bits_per_pixel / 8));
	*(unsigned int *) dst = color;
}

void	init(t_ply *p)
{
	p->tile_size = TILE_SIZE;
	p->rotation_speed = 3 * (PI / 180); 
	p->player_size = 10;
	p->mlx = mlx_init();
	p->win = mlx_new_window(p->mlx, MAP_ROWS * TILE_SIZE, MAP_COLS * TILE_SIZE, "CUB3D");
	p->img = mlx_new_image(p->mlx, MAP_ROWS * TILE_SIZE, MAP_COLS * TILE_SIZE);
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
	*file = get_texture_file(description);
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

void	rectangle(t_ply *p, int i, int j, int color)
{
	int	j_holder;
	int	i_holder;

	j_holder = j;
	i_holder = i;
	while (i < i_holder + p->tile_size)
	{
		j = j_holder;
		while (j < j_holder + p->tile_size)
		{
			my_mlx_pixel_put(p, i, j, color);
			j++;
		}
		i++;
	}
}

// y = ax + b;

void	line_of_direction(t_ply *p)
{
	double	y;
	double	x;
	// double	a;
	// double	b;
	int		i;
	
	// b = p->y;
	// a = -b / p->x;
	p->x += 5;
	p->y += 5;
	x = p->x;
	y = p->y;
	i = 0;
	while (i < 30)
	{
		my_mlx_pixel_put(p, y, x, 0x0000ff00);
		y++;
		i++;
	}
}

void	draw_player(t_ply *p)
{
	int	i;
	int	j;
	int	j_holder;
	int	i_holder;
	int	color;


	color = 0xf5fffa;
	i = 0;
	j = 0;
	while (i < MAP_COLS)
	{
		j = 0;
		while (j < MAP_ROWS)
		{
			if (grid[i][j] == 2)
			{
				i_holder = i * TILE_SIZE + 15;
				j_holder = j * TILE_SIZE + 15;
				break ;
			}
			j++;
		}
		if (grid[i][j] == 2)
			break ;
		i++;
	}
	j = j_holder;
	i = i_holder;
	while (i < i_holder + p->player_size)
	{
		j = j_holder;
		while (j < j_holder + p->player_size)
		{
			my_mlx_pixel_put(p, j, i, 0x0000ff00);
			j++;
		}
		i++;
	}
	p->x = i_holder;
	p->y = j_holder;
	p->rotation_angle = 0;
	line_of_direction(p);
}


int	new_player_position(t_ply *p, double step_lenght)
{
	p->x = step_lenght * cos(p->rotation_angle);
	p->y = step_lenght * sin(p->rotation_angle);
}

void	draw_map(t_ply *p)
{
	int	i;
	int	j;
	int	x;
	int	y;

	i = 0;
	j = 0;
	x = 0;
	y = 0;
	while (i < (MAP_ROWS * p->tile_size) && x < 15)
	{
		j = 0;
		y = 0;
		while (j < (MAP_COLS * p->tile_size) && y < 15)
		{
			if (grid[y][x] == 1)
				rectangle(p, i, j, WALL_CLR);
			j += p->tile_size;
			y++;
		}
		i += p->tile_size;
		x++;
	}
	draw_player(p);
	mlx_put_image_to_window(p->mlx, p->win, p->img, 0, 0);
}

int	main(int ac, char **av)
{
	t_ply	p;

	if (ac == 2)
	{
		check_file_extention(av[1]);
		init(&p);
		draw_map(&p);
		mlx_hook(p.win, 17, 0, &cross, &p);
		mlx_hook(p.win, 2, 1L << 0, &key, &p);
		mlx_loop(p.mlx);
	}
	else
		str("INVALID NUMBER OF ARGUMENTS\n");
}
