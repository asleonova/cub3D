#include "cub3d.h"
#include <mlx.h>

#define SCALE 20

	int x;
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
		1, 0, 0, 2, 0, 1, 0, 1,
		1, 0, 0, 0, 0, 0, 0, 1,
		1, 1, 1, 1, 1, 1, 1, 1,
	};



typedef struct	s_map {

}				t_map;

void            my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
    char    *dst;

    dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
    *(unsigned int*)dst = color;
}

void	draw_player(t_all *all)
{
	
	y = 0;
	while (y/SCALE < map_y)
	{
		x = 0;
		while (x/SCALE < map_x)
		{
			if (map[y/SCALE * map_x + x/SCALE] == 2)
			{
				my_mlx_pixel_put(all->data->img, x, y, 0x008000);
				all->player->x = x;
				all->player->y = y;
			}
			
			x++;
		}
		y++;
	}
}

int control_player(int keycode, t_data *img)
{
     if(keycode == ESC)
         mlx_destroy_window(img->mlx, img->mlx_win);
    else if(keycode == 0)
        x -= 20;
    else if(keycode == 1)
        y += 20;
    else if(keycode == 2)
        x += 20;
    else if(keycode == W)
       y -= 5;
    // else if(keycode == 126 || keycode == 124)
    //     data->vector += 5;
    // else if(keycode == 125 || keycode == 123)
    //     data->vector -=5;
	return (1);
}

void	draw_map(t_all *all)
{
	y = 0;
	while (y/SCALE < map_y)
	{
		x = 0;
		while (x/SCALE < map_x)
		{
			if (map[y/SCALE * map_x + x/SCALE] == 1)
			{
				my_mlx_pixel_put(all->data->img, x, y, 0x000000FF);
			}
			x++;
		}
		y++;
	}
}

int     render_next_frame(t_all *all)
{
	draw_map(all);
	draw_player(all);
	return (1);
}

int             main(void)
{ 
	t_all *all;

	all = NULL;

    all->data->mlx = mlx_init();
    all->data->mlx_win = mlx_new_window(all->data->mlx, 500, 600, "Hello world!");
	all->data->img = mlx_new_image(all->data->mlx, 500, 600);
	all->data->addr = mlx_get_data_addr(all->data->img, &all->data->bits_per_pixel, &all->data->line_length,
                                  &all->data->endian);
	

	// draw_player(&img);
	mlx_key_hook(all->data->mlx_win, control_player, &all);
	mlx_loop_hook(all->data->mlx, render_next_frame, &all);
	mlx_put_image_to_window(all->data->mlx, all->data->mlx_win, all->data->img, 0, 0);
	mlx_loop(all->data->mlx);
}