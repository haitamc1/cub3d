#include "../include/cub3d.h"

t_texture data;

int	main(int ac, char **av)
{
	t_ply	p;

	init_textures(&data);
	if (ac == 2)
	{
		check_file_extension(av[1], ".cub");
		init(&p);
		mlx_hook(p.win, 17, 0, &cross, &p);
		mlx_hook(p.win, 2, 1L << 0, &key, &p);
		mlx_loop(p.mlx);
	}
	else
		str("INVALID NUMBER OF ARGUMENTS\n");
}
