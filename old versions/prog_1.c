#include "cub3d.h"
#include <mlx.h>

void            my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
    char    *dst;

    dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
    *(unsigned int*)dst = color;
}

int             main(void)
{ 
	int x;
	t_data  img;
	int y;
	int map_x = 8;
	int map_y = 8;
	int map[] =
	{
		1, 1, 1, 0, 1, 1, 1, 1,
		1, 0, 1, 0, 0, 0, 0, 1,
		1, 0, 1, 0, 0, 0, 0, 1,
		1, 0, 1, 0, 0, 0, 0, 1,
		1, 0, 0, 0, 0, 0, 0, 1,
		1, 0, 0, 0, 0, 1, 0, 1,
		1, 0, 0, 0, 0, 0, 0, 1,
		1, 1, 1, 1, 1, 1, 1, 1,
	};
    void    *mlx;
    void    *mlx_win;

    mlx = mlx_init();
    mlx_win = mlx_new_window(mlx, 500, 600, "Hello world!");
	img.img = mlx_new_image(mlx, 500, 600);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
                                  &img.endian);
	y = 0;
	while (y < map_y)
	{
		x = 0;
		while (x < map_x)
		{
			 if (map[y * map_x + x] == 1)
			{
				my_mlx_pixel_put(&img, x, y, 0x000000FF);
			}
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
	mlx_loop(mlx);
}