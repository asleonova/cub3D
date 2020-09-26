#include "cub3d.h"
#include <mlx.h>
#include "../libft/libft.h" 
#include <stdio.h>
#include <math.h>

	int map_int [10] [10] = {
    { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 },
    { 1, 0, 0, 0, 0, 0, 0, 0, 0, 1 },
    { 1, 0, 0, 0, 0, 0, 0, 0, 0, 1 },
	{ 1, 1, 0, 0, 0, 1, 0, 0, 0, 1 },
	{ 1, 0, 0, 0, 0, 1, 0, 0, 0, 1 },
	{ 1, 0, 0, 0, 0, 1, 0, 0, 0, 1 },
	{ 1, 0, 0, 0, 0, 0, 0, 1, 0, 1 },
	{ 1, 0, 0, 0, 0, 0, 0, 1, 0, 1 },
	{ 1, 0, 0, 0, 0, 0, 0, 0, 0, 1 },
	{ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 }
};
void            my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
    char    *dst;

    dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
    *(unsigned int*)dst = color;
}

void 	horizontal_cross(t_all *all)
{
	if (all->player.dir > 0 && all->player.dir < M_PI) // the ray looking up
	{
		all->cross.hy = (int)(all->player.y / SCALE) * SCALE - 1;
		all->cross.h_dy = -SCALE;
		all->cross.hx = all->player.x + (all->player.y - all->cross.hy) / tan(all->player.dir);
		all->cross.h_dx = SCALE/tan(all->player.dir);
	}
	if (all->player.dir < 0 && all->player.dir > -M_PI) // the ray looking down
	{
		all->cross.hy = (int)(all->player.y / SCALE) * SCALE + SCALE;
		all->cross.h_dy = SCALE;
		all->cross.hx = all->player.x + (all->player.y - all->cross.hy) / tan(all->player.dir);
		all->cross.h_dx = SCALE/tan(all->player.dir);
	}
	if (all->player.dir == 0 || all->player.dir == M_PI) // looking straight left or right (*it will never hit the horiz line)
	{
		all->cross.hy = all->player.y;
		all->cross.hx = all->player.x;
	}
	my_mlx_pixel_put(&all->data, all->cross.hx, all->cross.hy, 0x00FF00);
}

void	vertical_cross(t_all *all)
{
	if (all->player.dir > M_PI_2 && all->player.dir < 3 * M_PI_2) // the ray looking left
	{
		all->cross.vx = (int)(all->player.x / SCALE) * SCALE - 1;
		all->cross.v_dx = -SCALE;
		all->cross.vy = all->player.y + (all->player.x - all->cross.vx) * tan(all->player.dir);
		all->cross.v_dy = SCALE * tan(all->player.dir);
	}
	if (all->player.dir > -M_PI_2 && all->player.dir < M_PI_2) // the ray looking right
	{	
		all->cross.vx = (int)(all->player.x / SCALE) * SCALE + SCALE;
		all->cross.v_dx = SCALE;
		all->cross.vy = all->player.y + (all->player.x - all->cross.vx) * tan(all->player.dir);
		all->cross.v_dy = SCALE * tan(all->player.dir);
	}
	if (all->player.dir == 0 || all->player.dir == M_PI) // looking straight left or right (*it will never hit the horiz line)
	{
		all->cross.hy = all->player.y;
		all->cross.hx = all->player.x;
	}
	my_mlx_pixel_put(&all->data, all->cross.vx, all->cross.vy, 0xFFA500);
}

void	cast_ray(t_all *all)
{
	// проверка на пересечение со стенкой
	if (map_int[(int)all->cross.hx / SCALE][(int)all->cross.hy / SCALE] != 1) // no wall, add the delta
	{
		all->cross.hx += all->cross.h_dx;
	 	all->cross.hy += all->cross.h_dy;
		all->cross.vx += all->cross.v_dx;
	 	all->cross.vy += all->cross.v_dy;
	}
	else // if the wall - calculate the distance
	{
		float pow_hx = pow((all->player.x - all->cross.h_dx), 2);
		float pow_hy = pow((all->player.y - all->cross.h_dy), 2);
		all->cross.h_distance = sqrt(pow_hx + pow_hy);
		float pow_vx = pow((all->player.x - all->cross.v_dx), 2);
		float pow_vy = pow((all->player.y - all->cross.v_dy), 2);
		all->cross.v_distance = sqrt(pow_vx + pow_vy);
	}
}
// void	draw_ray(t_all *all)
// {
// 	all->player.start = all->player.dir - (M_PI_4);
// 	all->player.end = all->player.dir + (M_PI_4);
// 	while (all->player.start <= all->player.end)
// 	{
// 		while (map_int[all->map.y / SCALE][all->map.x / SCALE] != 1)
// 		{

// 			my_mlx_pixel_put()
// 		}
// 		all->player.start += M_PI_2 / 1000;
// 	}
// }
void	draw_player(t_all *all)
{
	
	my_mlx_pixel_put(&all->data, all->player.x, all->player.y, 0x00FF0000);
	// all->player.start = all->player.dir - (M_PI_4); // 45 to get the s
	// all->player.end = all->player.dir + (M_PI_4); //45
	// while (all->player.start < all->player.end)
	// {
	// 	all->map.x = all->player.x;
	// 	all->map.y = all->player.y;
	// 	while (map_int[(int)(all->map.y / SCALE)][(int)(all->map.x / SCALE)] != 1)
	// 	{
	// 		my_mlx_pixel_put(&all->data, all->map.x, all->map.y, 0x00FF0000);
	// 		all->map.x += cos(all->player.start);
	// 		all->map.y += sin(all->player.start);
	// 	}
	// 	all->player.start += M_PI_2 / 1000;

	//}
	//printf("%d\n", all->player.x);
	//printf("%d\n", all->player.y);
}


void	draw_map(t_all *all)
{
	all->data.img = mlx_new_image(all->data.mlx, 1200, 800);
	all->data.addr = mlx_get_data_addr(all->data.img, &all->data.bits_per_pixel, &all->data.line_length,
                                  &all->data.endian);
	all->map.y = 0;
	while (all->map.y/SCALE < 10 ) // нужна будет переменная под размер карты
	{
		all->map.x = 0;
		while (all->map.x/SCALE < 10) // нужна будет переменная под размер карты
		{
			if (map_int[all->map.y / SCALE][all->map.x / SCALE] == 1)
			{
				my_mlx_pixel_put(&all->data, all->map.x, all->map.y, 0x000000FF);
			}
			else if (map_int[all->map.y / SCALE][all->map.x / SCALE] == 0)
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
	horizontal_cross(all);
	vertical_cross(all);
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
	//printf("%d\n", keycode);
	draw_screen(all);
    // else if(keycode == 126 || keycode == 124)
    //     data->vector += 5;
    // else if(keycode == 125 || keycode == 123)
    //     data->vector -=5;
	return (0);
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
	all.player.x = 187;
	all.player.y = 213;
	all.player.dir = M_PI_4;
	draw_screen(&all);
	mlx_hook(all.data.mlx_win, 2, 1L<<0, &control_player, &all);
	//mlx_key_hook(all.data.mlx_win, control_player, &all); это работает медленнее, чем mlx_hook
	//mlx_loop_hook(all.data.mlx, render_next_frame, &all);
	mlx_loop(all.data.mlx);
}