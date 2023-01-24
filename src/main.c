#include "../include/cub3d.h"

void	print_test();
void	print_map(char **map);

int	main(int ac, char **av)
{
	t_ply	p;

	if (ac == 2)
	{
		//check_file_extension(av[1], ".cub");
		init_values(&p);
		init_textures(&p.txt);
		check_map(&p, get_map(av[1]));
		load_textures(&p);
		print_map(p.map);
		draw_map(&p);
		// draw_line(&p, set_point(100, 100), set_point(300, 300));
		// draw_line(&p, set_point(300, 100), set_point(100, 300));
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
	while (y < MAP_COLS)
	{
		x = 0;
		while (x < MAP_ROWS)
		{
			printf("%c", map[y][x]);
			x++;
		}
		printf("\n");
		y++;
	}
}
