/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchahid <hchahid@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 18:43:24 by hchahid           #+#    #+#             */
/*   Updated: 2023/01/10 12:21:52 by hchahid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

t_texture data;

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

int	cub_fd(char *file_name)
{
	int	fd;

	fd = open (file_name, O_RDONLY);
	if (fd < 0)
		exit_msg("COULD NOT OPEN FILE\n");
	return (fd);
}


int	is_there_wall(double new_x, double new_y)
{
	if (grid[(int )(new_x / TILE_SIZE)][(int )(new_y / TILE_SIZE)] == 1)
		return (1);
	return (0);
}

// void	load_textures(bool *direction, char **file, char *description)
// {
// 	*file = description;
// 	//*file = get_texture_file(description);
// }

// void	load_colors(bool *space, int *clr, char *description)
// {
// 	*space = true;
// 	*clr = get_clr(description);
// }

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

// void	line_of_direction(t_ply *p)
// {
// 	double	y;
// 	double	x;
// 	// double	a;
// 	// double	b;
// 	int		i;
	
// 	// b = p->y;
// 	// a = -b / p->x;

// 	x = p->x;
// 	y = p->y;
// 	i = 0;
// 	while (i < 30)
// 	{
// 		my_mlx_pixel_put(p, y, x, 0x0000ff00);
// 		y++;
// 		i++;
// 	}
// }

void	draw_player(t_ply *p)
{
	int	i;
	int	j;
	int	j_holder;
	int	i_holder;
	int	color;


	color = 0xf5fffa;
	// i = 0;
	// j = 0;
	// while (i < MAP_COLS)
	// {
	// 	j = 0;
	// 	while (j < MAP_ROWS)
	// 	{
	// 		if (grid[i][j] == 2)
	// 		{
	// 			i_holder = i * TILE_SIZE + 15;
	// 			j_holder = j * TILE_SIZE + 15;
	// 			break ;
	// 		}
	// 		j++;
	// 	}
	// 	if (grid[i][j] == 2)
	// 		break ;
	// 	i++;
	// }
	j_holder = p->y;
	i_holder = p->x;
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
	// p->x = i_holder + 5;
	// p->y = j_holder + 5;
	player_direction(p);
}


void	player_direction(t_ply *p)
{
	int		ray_count;
	double	x;
	double	y;
	double	j;
	int		i;
	
	i = 0;
	j = 0;
	ray_count = 10;
	while (j < ray_count)
	{
		i = 0;
		while (!is_there_wall(i * cos(p->rotation_angle + deg_to_rad(j)) + p->x, i * sin(p->rotation_angle + deg_to_rad(j)) + p->y))
		{
			x = i * cos(p->rotation_angle + deg_to_rad(j)) + p->x;
			y = i * sin(p->rotation_angle + deg_to_rad(j)) + p->y;
			my_mlx_pixel_put(p, y, x, 0x0000ff00);
			i++;
		}
		
		j += 0.1;
	}
	i = 0;
	j = 0;
	while (j < ray_count)
	{
		i = 0;
		while (!is_there_wall(i * cos(p->rotation_angle - deg_to_rad(j)) + p->x, i * sin(p->rotation_angle - deg_to_rad(j)) + p->y))
		{
			x = i * cos(p->rotation_angle - deg_to_rad(j)) + p->x;
			y = i * sin(p->rotation_angle - deg_to_rad(j)) + p->y;
			my_mlx_pixel_put(p, y, x, 0x0000ff00);
			i++;
		}
		j += 0.1;
	}
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

	(void)av;
	if (ac == 2)
	{
		// check_file_extension(av[1], ".cub");
		init_values(&p);
		draw_map(&p);
		mlx_hook(p.win, 17, 0, &cross, &p);
		mlx_hook(p.win, 2, 1L << 0, &key, &p);
		mlx_loop(p.mlx);
	}
	else
		str("INVALID NUMBER OF ARGUMENTS\n");
}
