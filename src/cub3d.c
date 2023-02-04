/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchahid <hchahid@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 18:43:24 by hchahid           #+#    #+#             */
/*   Updated: 2023/02/03 22:13:07 by hchahid          ###   ########.fr       */
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

	if ((x >= 0 &&  x < WIDTH) && (y >= 0 &&  y < HEIGHT))
	{
		dst = p->addr + (y * p->line_length + x * (p->bits_per_pixel / 8));
		*(unsigned int *) dst = color;
	}
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
	if ((int )(new_x / TILE_SIZE) > 15 || (int )(new_x / TILE_SIZE) < 0)
		return (printf("out of x range %d\n", (int )(new_x / TILE_SIZE)), 1);
	else if ((int )(new_y / TILE_SIZE) > 15 || (int )(new_y / TILE_SIZE) < 0)
		return (printf("out of y range %d\n", (int )(new_y / TILE_SIZE)), 1);
	if (grid[(int )(new_y / TILE_SIZE)][(int )(new_x / TILE_SIZE)] == 1)
		return (1);
	return (0);
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

t_coordinates	dda_algo(t_ply *p, double angle)
{
	t_intersection	data;
	t_coordinates	vrt;
	t_coordinates	hoz;
	double			x;
	double			y;

	horizontal_intersection(p, &data, angle);
	vertical_intersection(p, &data, angle);
	x = data.horizontal_x;
	y = data.horizontal_y;
	while (x >= 0 && x <=  MAP_ROWS * TILE_SIZE && y >= 0 && y <=  MAP_COLS * TILE_SIZE)
	{
		if (looking_up(angle) && is_there_wall(x, y - 1))
			break ;
		else if (is_there_wall(x, y))
			break ;
		x += data.x_step_hoz;
		y += data.y_step_hoz;
	}
	hoz.x = x;
	hoz.y = y;
	x = data.vertical_x;
	y = data.vertical_y;
	while (x >= 0 && x <= MAP_ROWS * TILE_SIZE && y >= 0 && y <=  MAP_COLS * TILE_SIZE)
	{
		if (!facing_right(angle) && is_there_wall(x - 1, y))
			break ;
		else if (is_there_wall(x, y))
			break ;
		x += data.x_step_vrt;
		y += data.y_step_vrt;
	}
	vrt.x = x;
	vrt.y = y;
	x = ray_lenght(vrt.x , vrt.y , p->x, p->y);
	y = ray_lenght(hoz.x , hoz.y , p->x, p->y);
	if (x > y)
		return (hoz);
	return (vrt);
}

t_coordinates	distance_to_wall(t_ply *p, double angle)
{
	t_intersection	data;
	t_coordinates	vrt;
	t_coordinates	hoz;
	double			x;
	double			y;

	horizontal_intersection(p, &data, angle);
	vertical_intersection(p, &data, angle);
	x = data.horizontal_x;
	y = data.horizontal_y;
	while (x >= 0 && x <=  MAP_ROWS * TILE_SIZE && y >= 0 && y <=  MAP_COLS * TILE_SIZE)
	{
		if (looking_up(angle) && is_there_wall(x, y - 1))
			break ;
		else if (is_there_wall(x, y))
			break ;
		x += data.x_step_hoz;
		y += data.y_step_hoz;
	}
	hoz.x = x;
	hoz.y = y;
	hoz.ray_lenght = ray_lenght(hoz.x , hoz.y , p->x, p->y);
	x = data.vertical_x;
	y = data.vertical_y;
	while (x >= 0 && x <= MAP_ROWS * TILE_SIZE && y >= 0 && y <=  MAP_COLS * TILE_SIZE)
	{
		if (!facing_right(angle) && is_there_wall(x - 1, y))
			break ;
		else if (is_there_wall(x, y))
			break ;
		x += data.x_step_vrt;
		y += data.y_step_vrt;
	}
	vrt.x = x;
	vrt.y = y;
	vrt.ray_lenght = ray_lenght(vrt.x , vrt.y , p->x, p->y);
	hoz.vertical_hit = false;
	if (vrt.ray_lenght > hoz.ray_lenght)
		return (hoz);
	vrt.vertical_hit = true;
	return (vrt);

}

// void DDA(int X0, int Y0, int X1, int Y1, t_ply *p)
// {
//     // calculate dx & dy
//     int dx = X1 - X0;
//     int dy = Y1 - Y0;
 
//     // calculate steps required for generating pixels
//     int steps = abs(dx) > abs(dy) ? abs(dx) : abs(dy);
 
//     // calculate increment in x & y for each steps
//     float Xinc = dx / (float)steps;
//     float Yinc = dy / (float)steps;
 
//     // Put pixel for each step
//     float X = X0;
//     float Y = Y0;
//     for (int i = 0; i <= steps; i++) {
// 		 my_mlx_pixel_put(p, round(X), round(Y), 0x0000ff00); // put pixel at (X,Y)
//         X += Xinc; // increment in x at each step
//         Y += Yinc; // increment in y at each step
//         // delay(100); // for visualization of line-
//                     // generation step by step
//     }
// }

void	player_direction(t_ply *p)
{
	double	angle;
	double	x;
	double	y;
	double	j;
	int		i;
	t_coordinates hit_point;
	
	i = 0;

	j = -(PI / 6);
	while (j < PI / 6)
	{
		i = 0;
		angle = p->rotation_angle + j;
		angle = normilaze_angle(angle);
		hit_point = dda_algo(p, angle);
		x = p->x;
		y = p->y;
		// DDA(x,y, hit_point.x,hit_point.y, p);
		j += 0.001;
	}
}

// step represents (PI / 3) / WIDTH which is my field of view devided by my window width

int	my_view(t_ply *p)
{
	double	angle;
	double	step;
	double	j;
	int		i;
	
	i = 0;
	// j = -(1.0472 / 2);
	j = -(PI / 6);
	step = 0.001745;
	while (j < (PI / 6) && i < WIDTH)
	{
		angle = p->rotation_angle + j;
		angle = normilaze_angle(angle);
		draw_wall(p, angle, i++);
		j += step;
	}
	mlx_put_image_to_window(p->mlx, p->win, p->img, 0, 0);
	// if (is_there_wall(p->x, p->y))
	// 	printf("\n\n------fl7it-------\n\n");
	// else
	// 	printf("u good\n");
	// free(strip_height);
	return (0);
}

// void	draw_map(t_ply *p)
// {
// 	int	i;
// 	int	j;
// 	int	x;
// 	int	y;

// 	i = 0;
// 	j = 0;
// 	x = 0;
// 	y = 0;
// 	while (i < (MAP_ROWS * p->tile_size) && x < 15)
// 	{
// 		j = 0;
// 		y = 0;
// 		while (j < (MAP_COLS * p->tile_size) && y < 15)
// 		{
// 			if (grid[y][x] == 1)
// 				rectangle(p, i, j, WALL_CLR);
// 			j += p->tile_size;
// 			y++;
// 		}
// 		i += p->tile_size;
// 		x++;
// 	}
// 	// draw_player(p);
// 	player_direction(p);

// 	mlx_put_image_to_window(p->mlx, p->win, p->img, 0, 0);
// }

int	main(int ac, char **av)
{
	t_ply	p;

	(void)av;
	if (ac == 2)
	{
		// check_file_extension(av[1], ".cub");
		init_values(&p);
		// draw_map(&p);
		my_view(&p);
		mlx_hook(p.win, 17, 0, &cross, &p);
		mlx_hook(p.win, 2, 1L << 0, &key, &p);
		mlx_loop(p.mlx);
	}
	else
		str("INVALID NUMBER OF ARGUMENTS\n");
}
