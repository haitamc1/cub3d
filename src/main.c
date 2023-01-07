#include "../include/cub3d.h"

t_texture data;
void	print_test();

int	main(int ac, char **av)
{
	t_ply	p;

	init_textures(&data);
	printf("len is %d\n", ft_chardp_len(av));
	if (ac == 2)
	{
		check_file_extension(av[1], ".cub");
		check_map(get_map(av[1]));
		init(&p);
		print_test();
		mlx_hook(p.win, 17, 0, &cross, &p);
		mlx_hook(p.win, 2, 1L << 0, &key, &p);
		mlx_loop(p.mlx);
	}
	else
		str("INVALID NUMBER OF ARGUMENTS\n");
}

void	print_test()
{
	printf("file{%s}\n", data.ea_file);
	printf("file{%s}\n", data.so_file);
	printf("file{%s}\n", data.no_file);
	printf("file{%s}\n", data.we_file);
	printf("file{%d}\n", data.ceiling_clr);
	printf("file{%d}\n", data.floor_clr);
}
