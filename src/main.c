#include "../cub3d.h"

int             main(void)
{ 
	t_all	all;

    all.data.mlx = mlx_init();
    all.data.mlx_win = mlx_new_window(all.data.mlx, S_WIDTH, S_HEIGHT, "CUB_3D!");

	all.data.img = mlx_new_image(all.data.mlx, S_WIDTH, S_HEIGHT);
	all.data.addr = mlx_get_data_addr(all.data.img, &all.data.bits_per_pixel, &all.data.line_length,
                                  &all.data.endian);

	init_all(&all);
	mlx_hook(all.data.mlx_win, 2, 1L<<0, &control_player, &all);
	mlx_loop_hook(all.data.mlx, render_next_frame, &all);
	mlx_loop(all.data.mlx);
}