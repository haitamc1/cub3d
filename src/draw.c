#include "../include/cub3d.h"

void	draw_map(t_ply *p)
{
	int	x;
	int	y;
	int	map_x;
	int	map_y;

	y = 0;
	map_x = MAP_ROWS * TILE_SIZE;
	map_y = MAP_COLS * TILE_SIZE;
	while (y < map_y)
	{
		x = 0;
		while (x < map_x)
		{
			if (grid[y / TILE_SIZE][x / TILE_SIZE] == 1)
				draw_rect(p, x, y, TILE_SIZE, 0xFA4FFF);
			x += TILE_SIZE;
		}
		y += TILE_SIZE;
	}
	//draw_playert(p);
	render_ray_all(p);
	//draw_ray(p);
	mlx_put_image_to_window(p->mlx, p->win, p->img, 0, 0);
}

void	draw_playert(t_ply *p)
{
	draw_rect(p, p->x, p->y, p->player_size, 0x964f6b);
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
	ray.hit_wall = get_wall_hit_point(ray.origin, p->rotation_angle);
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
