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
	draw_playert(p);
	draw_rays(p);
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

void	draw_line(t_ply *p, t_point a, t_point b)
{
	double		x;
	double		y;
	double		x_end;
	t_lineq	ln;

	printf("A: x[%.0f] | y[%.0f]\n", a.x, a.y);
	printf("B: x[%.0f] | y[%.0f]\n", b.x, b.y);
	ln = cal_alpha(a,b);
	x = fmin(a.x, b.x);
	x_end = fmax(a.x, b.x);
	printf("alpha[%f] | beta[%f]\n", ln.alpha, ln.beta);
	while (x < x_end)
	{
		y = ln.alpha * x + ln.beta;
		// if (y < 0)
		//  y = -y;
		// if (x < 0)
		//  x = -x;
		printf("x[%.2f] | y[%.2f]\n", x, y);
		if (y < 0 || x < 0 || y >= TILE_SIZE * MAP_COLS || x >= TILE_SIZE * MAP_ROWS)
			break ;
		my_mlx_pixel_put(p, x, y, 0xff0011);
		x += RAY_LEN /(x_end - x) ;
	}
}

t_lineq	cal_alpha(t_point a, t_point b)
{
	t_lineq	t;

	if (b.x == a.x)
		t.alpha = 0;
	else t.alpha = (b.y - a.y) / (b.x - a.x);
	t.beta = (b.y) - (t.alpha * b.x);
	return (t);
}

void	draw_ray(t_ply *p)
{
	t_point	a;
	t_point	b;

	a = set_point(p->x + p->player_size / 2, p->y + p->player_size / 2);
	b = set_point(p->x + p->player_size / 2 + cos(p->rotation_angle) * RAY_LEN, \
	p->y + p->player_size / 2 + sin(p->rotation_angle) * RAY_LEN);

	draw_line(p, a, b);
}

void	draw_rays(t_ply *p)
{
	int			ray_num;
	float		angle_increment;
	t_point		a;
	t_point		b;
	float		ray_angle;

	angle_increment = FOV / NUM_RAYS;
	ray_num = 0;
	ray_angle = p->rotation_angle - (FOV / 2);
	a = set_point(p->x + p->player_size / 2, p->y + p->player_size / 2);
	//printf("ray increment [%f]", angle_increment);
	while (ray_num < NUM_RAYS)
	{
		b = set_point(p->x + p->player_size / 2 + cos(ray_angle) * RAY_LEN, \
		p->y + p->player_size / 2 + sin(ray_angle) * RAY_LEN);
		ray_angle += angle_increment;
		ray_num++;
		draw_line(p, a, b);
	}
}

t_point	set_point(int x, int y)
{
	t_point	p;
	p.x = x;
	p.y = y;
	return (p);
}