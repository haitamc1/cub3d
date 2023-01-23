#include "../include/cub3d.h"

void	draw_map(t_ply *p)
{
	t_ray	ray[NUM_RAYS];

	init_rays(p, ray);
	// int	x;
	// int	y;
	// int	map_x;
	// int	map_y;

	// y = 0;
	// map_x = MAP_ROWS * TILE_SIZE;
	// map_y = MAP_COLS * TILE_SIZE;
	// while (y < map_y)
	// {
	// 	x = 0;
	// 	while (x < map_x)
	// 	{
	// 		if (grid[y / TILE_SIZE][x / TILE_SIZE] == 1)
	// 			draw_rect(p, x, y, TILE_SIZE, 0xFA4FFF);
	// 		x += TILE_SIZE;
	// 	}
	// 	y += TILE_SIZE;
	// }
	// render_ray_all(p);
	//draw_ray(p);
	//draw_playert(p);
	draw_walls(p, ray);
	mlx_put_image_to_window(p->mlx, p->win, p->img, 0, 0);
}

void	draw_rect(t_ply *p, int x, int y, int len, int color)
{
	int	i;
	int	j;

	j = 0;
	while (j < len)
	{
		i = 0;
		while (i < len)
		{
			my_mlx_pixel_put(p, x + i, y + j, color);
			i++;
		}
		j++;
	}
}

void	draw_ray(t_ply *p)
{
	t_point	a;
	t_ray	ray;

	ray.origin = set_point(p->x + p->player_size / 2, p->y + p->player_size / 2);
	set_wall_hit_point(p->map, &ray, p->rotation_angle);
	if (is_facing_right(p->rotation_angle))
		printf("facing right\n");
	else
		printf("facing left\n");
	if (is_facing_up(p->rotation_angle))
		printf("facing up\n");
	else
		printf("facing down\n");
	printf("=============== hit point fount at y[%.2f]x[%.2f]\n", ray.hit_wall.y, ray.hit_wall.x);
	render_ray(p, ray);
}

double	normalize_angle(double angle)
{
	double	new_angle;

	new_angle = fmod(angle, 2 * PI);
	if (new_angle < 0)
		return ((2 * PI) + new_angle );
	return (new_angle);
}

void	draw_wall_strip(t_ply *p, t_ray ray, int x)
{
	double	y_top;
	double	y_bottom;
	double	wall_height;
	double	distance_from_top;
	double	plane_distance;
	double	distance;
	void	*wall_texture;
	double	j;

	distance = ray.distance * cos(ray.angle - p->rotation_angle);
	plane_distance = (WIDTH / 2) / tan(FOV / 2);
	wall_height = TILE_SIZE / distance * plane_distance;
	y_top = (WIDTH / 2) - (wall_height / 2);
	if (y_top < 0)
		y_top = 0;
	y_bottom = (WIDTH / 2) + (wall_height / 2);
	if (y_bottom >= HEIGHT)
		y_bottom = HEIGHT - 1;
	//printf("y_top[%.0f] -- y_bottom[%.0f] && wall height is %.0f\n", y_top, y_bottom, wall_height);
	draw_ceiling(p, x, y_top);
	j = y_top;
	while (j < y_bottom)
	{
		distance_from_top = j + wall_height / 2 - WIDTH / 2;
		//printf("y[%.1f]and x[%.d]\n", j, x);
		//printf("texture y[%d]and x[%d]\n", (int)((j - y_top) * TILE_SIZE / wall_height), ray.texture);
		if (ray.hit_type == HORZ)
			//my_mlx_pixel_put(p, x, j, 0xc3b091);
			my_mlx_pixel_put(p, x, j, \
			get_mlx_pixel_color(p, p->txt.no_txtr, ray.texture, distance_from_top * TILE_SIZE / wall_height));
		else
			//my_mlx_pixel_put(p, x, j, 0xefe7ce);
			my_mlx_pixel_put(p, x, j, \
			get_mlx_pixel_color(p, p->txt.so_txtr, ray.texture, distance_from_top * TILE_SIZE / wall_height));
		///printf("drawing pixel %.0f\n", j);
		j++;
	}
	draw_floor(p, x, y_bottom);
}

void	draw_walls(t_ply *p, t_ray *ray)
{
	int	i;

	i = 0;
	while (i < NUM_RAYS)
	{
		draw_wall_strip(p, ray[i], i);
		//printf("drawing strip %d\n", i);
		i++;
	}
}

void	my_mlx_pixel_put(t_ply *p, int x, int y, int color)
{
	char	*dst;

	dst = p->addr + (y * p->line_length + x * (p->bits_per_pixel / 8));
	*(unsigned int *) dst = color;
}

int	get_mlx_pixel_color(t_ply *p, char *txt, int x, int y)
{
	char	*dst;

	dst = txt + (y * p->txt.len + x * (p->txt.bpp / 8));
	return (*(unsigned int *) dst);
}

void	draw_ceiling(t_ply *p, int x, int y_end)
{
	int	j;

	j = 0;
	while (j < y_end)
	{
		my_mlx_pixel_put(p, x, j, 0x335379);
		j++;
	}
}

void	draw_floor(t_ply *p, int x, int y_start)
{
	int	j;

	j = y_start;
	while (j < HEIGHT)
	{
		my_mlx_pixel_put(p, x, j, 0xcdcace);
		j++;
	}
}