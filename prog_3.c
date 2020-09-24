#include "cub3d.h"
#include <mlx.h>
#include "../libft/libft.h" 
#include <stdio.h>
# include <math.h>


	int map_x = 8;
	int map_y = 8;
	int map_int[] =
	{
		1, 1, 1, 0, 1, 1, 1, 1,
		1, 0, 1, 0, 0, 0, 0, 1,
		1, 0, 1, 0, 0, 0, 0, 1,
		1, 0, 1, 0, 0, 0, 0, 1,
		1, 0, 0, 0, 0, 0, 0, 1,
		1, 0, 0, 0, 2, 1, 0, 1,
		1, 0, 0, 0, 0, 0, 0, 1,
		1, 1, 1, 1, 1, 1, 1, 1,
	};

void            my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
    char    *dst;

    dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
    *(unsigned int*)dst = color;
}

void	draw_player(t_all *all)
{
	// all->player.x = 319;
	// all->player.y = 383;
	// my_mlx_pixel_put(&all->data, all->player.x, all->player.y, 0x00FF0000);
	// printf("%d\n", all->player.x);
	// printf("%d\n", all->player.y);
	
	// all->map.y = 0;
	// while (all->map.y/SCALE < map_y)
	// {
	// 	all->map.x = 0;
	// 	while (all->map.x/SCALE < map_x)
	// 	{
	// 		if (map_int[all->map.y/SCALE* map_x + all->map.x/SCALE] != 1 && map_int[all->map.y/SCALE * map_x + all->map.x/SCALE] != 0)
	// 		{
	// 			all->player.x = all->map.x - 32;
	// 			all->player.y = all->map.y - 32;
			//my_mlx_pixel_put(&all->data, all->player.x, all->player.y, 0x00FF0000);
	// 		}
			
	// 		all->map.x++;
	// 	}
	// 	all->map.y++;
	// }
	/*while (map_int[(int)all->player.y/SCALE * map_x + (int)all->player.x/SCALE] == 0)
		{
			all->player.x += cos(all->player.dir);
			all->player.y += sin(all->player.dir);
			my_mlx_pixel_put(&all->data, all->player.x, all->player.y, 0x00FF0000);
		}	
	printf("%f\n", all->player.x);
	printf("%f\n", all->player.y);
	*/
	my_mlx_pixel_put(&all->data, all->player.x, all->player.y, 0x00FF0000);
}

int control_player(int keycode, t_all *all)
{
     if(keycode == ESC)
         mlx_destroy_window(all->data.mlx, all->data.mlx_win);
    else if(keycode == A)
        all->player.x -= 5;
    else if(keycode == S)
        all->player.y += 5;
    else if(keycode == D)
        all->player.x += 5;
    else if(keycode == W)
       all->player.y -= 5;
	printf("%d\n", keycode);
    // else if(keycode == 126 || keycode == 124)
    //     data->vector += 5;
    // else if(keycode == 125 || keycode == 123)
    //     data->vector -=5;
	return (1);
}

void	draw_map(t_all *all)
{
	all->map.y = 0;
	while (all->map.y/SCALE < map_y)
	{
		all->map.x = 0;
		while (all->map.x/SCALE < map_x)
		{
			if (map_int[all->map.y/SCALE * map_x + all->map.x/SCALE] == 1)
			{
				my_mlx_pixel_put(&all->data, all->map.x, all->map.y, 0x000000FF);
			}
			else if (map_int[all->map.y/SCALE * map_x + all->map.x/SCALE] == 0)
				my_mlx_pixel_put(&all->data, all->map.x, all->map.y, 0x00000000);
			all->map.x++;

		}
		all->map.y++;
	}
}

int     render_next_frame(t_all *all)
{
	// тут происходит поиск игрока
	draw_map(all);
	draw_player(all);
	mlx_put_image_to_window(all->data.mlx, all->data.mlx_win, all->data.img, 0, 0);
	return (1);
}

int             main(void)
{ 
	
	t_all	all;
    all.data.mlx = mlx_init();
    all.data.mlx_win = mlx_new_window(all.data.mlx, 1200, 800, "Hello world!");
	all.data.img = mlx_new_image(all.data.mlx, 1200, 800);
	all.data.addr = mlx_get_data_addr(all.data.img, &all.data.bits_per_pixel, &all.data.line_length,
                                  &all.data.endian);
	// draw_map(&all);
	//draw_player(&all);
	//mlx_key_hook(all.data.mlx_win, control_player, &all);
	all.player.x = 319;
	all.player.y = 383;
	mlx_hook(all.data.mlx_win, 2, 1L<<0, control_player, &all);
	mlx_loop_hook(all.data.mlx, render_next_frame, &all);
	mlx_loop(all.data.mlx);
}