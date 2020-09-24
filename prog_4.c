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
	//all->player.start = all->player.pa - M_PI_4;
	//all->player.end = all->player.pa + M_PI_4;
	//while (all->player.start < all->player.end)
	//{
		while (map_int[(int)all->player.y/SCALE * map_x + (int)all->player.x/SCALE] == 0)
		{
			all->player.x += cos(all->player.dir);
			all->player.y += sin(all->player.dir);
			my_mlx_pixel_put(&all->data, all->player.x, all->player.y, 0x00FF0000);
		}		
	}
	//all->player.start += M_PI_2 / 640;
	/*my_mlx_pixel_put(&all->data, all->player.x, all->player.y, 0x00FF0000);
	float c = 0;
	for (; c<20; c+=.05) {
    float x = all->player.x + c*cos(all->player.pa);
    float y = all->player.y + c*sin(all->player.pa);
    if (map_int[(int)x + (int)y*map_x] == 1)
		break;
		*/
//}

	//printf("%f\n", all->player.x);
	//printf("%f\n", all->player.y);
//}

void	draw_map(t_all *all)
{
	all->data.img = mlx_new_image(all->data.mlx, 1200, 800);
	all->data.addr = mlx_get_data_addr(all->data.img, &all->data.bits_per_pixel, &all->data.line_length,
                                  &all->data.endian);
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

void	draw_screen(t_all *all)
{
	draw_map(all);
	draw_player(all);
	mlx_put_image_to_window(all->data.mlx, all->data.mlx_win, all->data.img, 0, 0);
	mlx_destroy_image(all->data.mlx, all->data.img);
}

int     render_next_frame(t_all *all)
{
	// тут происходит поиск игрока
	draw_map(all);
	draw_player(all);
	mlx_put_image_to_window(all->data.mlx, all->data.mlx_win, all->data.img, 0, 0);
	//mlx_destroy_image(all->data.mlx, all->data.img);
	return (1);
}

int fix_angle(int a)
{
	if(a > 359)
	{
		a -= 360;
	} 
	if(a < 0)
	{ 
		a += 360;
	} 
	return (a);
}

float degToRad(int a) 
{ 
	return (a*M_PI/180.0);
}
/*int control_player(int keycode, t_all *all)
{
     if(keycode == ESC)
         mlx_destroy_window(all->data.mlx, all->data.mlx_win);
    else if(keycode == A)
	{
		all->player.pa += 5;
		all->player.pa = fix_angle(all->player.pa);
		all->player.dx = cos(degToRad(all->player.pa));
		all->player.dy =-sin(degToRad(all->player.pa));
	}
	else if(keycode == D)
	{
		all->player.pa -= 5;
		all->player.pa = fix_angle(all->player.pa);
		all->player.dx = cos(degToRad(all->player.pa));
		all->player.dy =-sin(degToRad(all->player.pa));
	}
	else if(keycode == W)
	{
		all->player.x += all->player.dx * 5;
		all->player.y += all->player.dy * 5;
	}
    else if(keycode == S)
	{
		all->player.x -= all->player.dx * 5;
		all->player.y -= all->player.dy * 5;
	}
	printf("%d\n", keycode);
	draw_screen(all);
    // else if(keycode == 126 || keycode == 124)
    //     data->vector += 5;
    // else if(keycode == 125 || keycode == 123)
    //     data->vector -=5;
	return (0);
}
*/


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
	all.player.x = 300;
	all.player.y = 300;
	all.player.pa = 90;
	all.player.dir = 3 * M_PI_2;
	all.player.dx=cos(degToRad(all.player.pa)); 
	all.player.dy=-sin(degToRad(all.player.pa)); 

	draw_screen(&all);
	mlx_hook(all.data.mlx_win, 2, 1L<<0, &control_player, &all);
	//mlx_key_hook(all.data.mlx_win, control_player, &all); это работает медленнее, чем mlx_hook
	//mlx_loop_hook(all.data.mlx, render_next_frame, &all);
	mlx_loop(all.data.mlx);
}