#include "../include/cub3d.h"

void	print_test();
void	print_map(char **map);

int	main(int ac, char **av)
{
	t_ply	p;

	if (ac == 2)
	{
		init_values(&p);
		init_textures(&p.txt);
		check_map(&p, get_map(av[1]));
		load_textures(&p);
		//print_map(p.map);
		printf("player y[%d]x[%d]\n", (int)(p.y / TILE_SIZE), (int) (p.x / TILE_SIZE));
		printf("angle [%.2f]\n", p.rotation_angle);
		printf("map len is [%d]\n", ft_parr_len(p.map));
		// draw_line(&p, set_point(100, 100), set_point(300, 300));
		// draw_line(&p, set_point(300, 100), set_point(100, 300));
		draw_map(&p);
		mlx_put_image_to_window(p.mlx, p.win, p.img, 0, 0);
		mlx_hook(p.win, 17, 0, &cross, &p);
		mlx_hook(p.win, 2, 0L, &key, &p);
		mlx_loop(p.mlx);
	}
	else
		str("INVALID NUMBER OF ARGUMENTS\n");
}

// void	print_test()
// {
// 	printf("file{%s}\n", data.ea_file);
// 	printf("file{%s}\n", data.so_file);
// 	printf("file{%s}\n", data.no_file);
// 	printf("file{%s}\n", data.we_file);
// 	printf("file{%d}\n", data.ceiling_clr);
// 	printf("file{%d}\n", data.floor_clr);
// }

void	print_map(char **map)
{
	int	x;
	int	y;

	y = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			printf("%c", map[y][x]);
			x++;
		}
		printf("\n");
		y++;
	}
}
