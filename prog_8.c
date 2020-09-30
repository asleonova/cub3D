#include "cub3d.h"

	int map_int [10] [10] = { // нужно обязательно найти потом макс. кол-во элементов массива
    { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 },
    { 1, 0, 0, 0, 0, 0, 0, 0, 0, 1 },
    { 1, 0, 0, 0, 0, 0, 0, 0, 0, 1 },
	{ 1, 0, 0, 0, 0, 0, 0, 0, 0, 1 },
	{ 1, 0, 0, 0, 0, 0, 0, 0, 0, 1 },
	{ 1, 0, 0, 0, 0, 0, 0, 0, 0, 1 },
	{ 1, 0, 0, 0, 0, 0, 0, 0, 0, 1 },
	{ 1, 0, 0, 0, 0, 0, 0, 0, 0, 1 },
	{ 1, 0, 0, 0, 0, 0, 0, 0, 0, 1 },
	{ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 }
};
void            my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
    char    *dst;

    dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
    *(unsigned int*)dst = color;
}

void 	horizontal_cross(t_all *all) // find the coordinates of the first horizontal cub cross + the delta
{
	if (all->player.fov_start > 0 && all->player.fov_start < M_PI) // the ray looking up
	{
		all->cross.hy = (int)(all->player.y / SCALE) * SCALE - 1;
		all->cross.h_dy = -SCALE;
		all->cross.hx = all->player.x + (all->player.y - all->cross.hy) / tan(all->player.fov_start);
		all->cross.h_dx = SCALE/tan(all->player.fov_start);
	}
	else // the ray looking down
	{
		all->cross.hy = (int)(all->player.y / SCALE) * SCALE + SCALE;
		all->cross.h_dy = SCALE;
		all->cross.hx = all->player.x + (all->player.y - all->cross.hy) / tan(all->player.fov_start);
		all->cross.h_dx = -SCALE/tan(all->player.fov_start);
	}
}

void	vertical_cross(t_all *all) // find the coordinates of the first vertical cub cross + the delta
{
	if (all->player.fov_start > M_PI_2 && all->player.fov_start < 3 * M_PI_2) // the ray looking left
	{
		all->cross.vx = (int)(all->player.x / SCALE) * SCALE - 1;
		all->cross.v_dx = -SCALE;
		all->cross.vy =all->player.y + (all->player.x - all->cross.vx) * tan(all->player.fov_start);
		all->cross.v_dy = SCALE * tan(all->player.fov_start);
	}
	else // the ray looking right
	{	
		all->cross.vx = (int)(all->player.x / SCALE) * SCALE + SCALE;
		all->cross.v_dx = SCALE;
		all->cross.vy = all->player.y + (all->player.x - all->cross.vx) * tan(all->player.fov_start);
		all->cross.v_dy = -SCALE * tan(all->player.fov_start);
	}
}

// где-ьл посчталось, что высота стены == 0, надо исправить!!!! 
int is_out_of_map(float x, float y) // checks if the coordinate is outside of the map
{
	if ((x > 0 && x < MAX) && (y > 0 && y < MAX))
		return (0);
	else 
		return (1);
}

int is_wall(float x, float y) // checks if the coordinate hits the wall
{
	if (map_int[(int)y / SCALE][(int)x / SCALE] != 1)
		return (0);
	else
		return (1);	
}

void horizontal_hit(t_all *all) // find the horizontal coordinates when it hits the wall
{
	while (!is_out_of_map(all->cross.hx, all->cross.hy) && !is_wall(all->cross.hx, all->cross.hy))
	{
		all->cross.hx += all->cross.h_dx;
	 	all->cross.hy += all->cross.h_dy;
	}
	// calculate the distance 
	float pow_hx = pow((all->player.x - all->cross.hx), 2);
	float pow_hy = pow((all->player.y - all->cross.hy), 2);
	all->cross.h_distance = sqrt(pow_hx + pow_hy);
}

void vertical_hit(t_all *all) // find the vertical coordinates when it hits the wall
{
	while (!is_out_of_map(all->cross.vx, all->cross.vy) && !is_wall(all->cross.vx, all->cross.vy))
	{
		all->cross.vx += all->cross.v_dx;
	 	all->cross.vy += all->cross.v_dy;
	}
	// calculate the distance 
	float pow_vx = pow((all->player.x - all->cross.vx), 2);
	float pow_vy = pow((all->player.y - all->cross.vy), 2);
	all->cross.v_distance = sqrt(pow_vx + pow_vy);
}

void	draw_ray(t_all *all)
{
	int dx = all->cross.wall_x - all->player.x;
    int dy = all->cross.wall_y - all->player.y;
    int     steps;
    float x_increment;
    float y_increment;
    float x = all->player.x;
    float y = all->player.y;
    if (abs(dx) > abs(dy)) // abs - absolute value (library function)
        steps = abs(dx);
    else
        steps = abs(dy);
    x_increment = dx / (float)steps;
    y_increment = dy / (float)steps;
    int i = 0;
    while (i < steps)
    {
        x +=x_increment;
        y += y_increment;
        my_mlx_pixel_put(&all->data, round(x), round(y), 0xFFA500);
        i++;
	}
}

void shortest_distance(t_all *all) // choose the closeset wall hit coordinate (whether it's horizontal or vertical)
{
		if (all->cross.h_distance < all->cross.v_distance)
		{
			all->cross.closest_cross = all->cross.h_distance; // remember this coordinate
			all->cross.wall_x = all->cross.hx;
			all->cross.wall_y = all->cross.hy;
		}
		else
		{
			all->cross.closest_cross = all->cross.v_distance;
			all->cross.wall_x = all->cross.vx;
			all->cross.wall_y = all->cross.vy;
		}
		all->cross.right_distance = all->cross.closest_cross * cos(all->player.dir - all->player.fov_start); // for fisheye effect
		draw_ray(all);
}

void fix_angle(float *angle)
{
	if (*angle < 0)
			*angle += 2 * M_PI;
	if (*angle > 2 * M_PI)
		*angle -= 2 * M_PI;
}

void calculate_wall(t_all *all, int i)
{
	all->player.proj_slice_h[i] = (SCALE / all->cross.right_distance) * all->player.dist_to_screen;
	all->player.ceiling[i] = ceil(SCREEN_CENTER - all->player.proj_slice_h[i] / 2);

}

void	cast_ray(t_all *all)
{
	all->player.fov_start = all->player.dir - M_PI / 6;
	int i = 0;
	while (i < S_LENGTH)
	{
		fix_angle(&all->player.fov_start); // for each ray
		horizontal_cross(all); // for each ray
		vertical_cross(all); // for each ray
		horizontal_hit(all); // for each ray
		vertical_hit(all); // for each ray
		shortest_distance(all); // for each ray
		calculate_wall(all, i);
		all->player.fov_start += all->player.angle; // change the ray position
		i++;
	}
}


void draw_ceiling(t_all *all, int width)
{
	int height = 0;
	while (height < all->player.ceiling[width])
	{
		my_mlx_pixel_put(&all->data, width, height++, 0xFFB6C1);
	}
}

void draw_wall(t_all *all, int width)
{
	int height = all->player.ceiling[width] + 1; // координата y для отрисовки стены (73 + 1)
	while (height < all->player.proj_slice_h[width])
	{
		my_mlx_pixel_put(&all->data, width, height++, 0x00FF0000);
	}
}

void draw_floor(t_all *all, int width)
{
	int height = all->player.proj_slice_h[width] + 1; // координата начала для отрисовки пола
	while (height < S_WIDTH)
	{
		my_mlx_pixel_put(&all->data, width, height++, 0x800080);
	}
}
void	draw_screen(t_all *all)
{
	int width = 0;
	while (width < S_LENGTH)
	{
		draw_ceiling(all, width);
		draw_wall(all, width);
		draw_floor(all, width);
		width++;
	}
}

void	draw_player(t_all *all)
{
	my_mlx_pixel_put(&all->data, all->player.x, all->player.y, 0x00FF0000);
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

int     render_next_frame(t_all *all)
{
	//draw_map(all);
	//draw_player(all);
	cast_ray(all);
	draw_screen(all);
	mlx_put_image_to_window(all->data.mlx, all->data.mlx_win, all->data.img, 0, 0);
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
	else if(keycode == LEFT)
	{
		all->player.dir += 0.03;
		fix_angle(&all->player.dir);
	}
    else if(keycode == RIGHT)
	{
		all->player.dir -= 0.03;
		fix_angle(&all->player.dir);
	}
	return (0);
}


void init_player(t_all *all)
{
	all->player.x = 187;
	all->player.y = 213;
	all->player.dir = M_PI_2;
	all->player.angle = (M_PI / 3) / S_LENGTH; // fov / width of projection plane
	all->player.dist_to_screen = (S_LENGTH / 2) / tan(M_PI / 6); // 1/2 screen / tan(30)

}

int             main(void)
{ 
	
	t_all	all;
    all.data.mlx = mlx_init();
    all.data.mlx_win = mlx_new_window(all.data.mlx, S_LENGTH, S_WIDTH, "CUB_3D!");
	all.data.img = mlx_new_image(all.data.mlx, S_LENGTH, S_WIDTH);
	all.data.addr = mlx_get_data_addr(all.data.img, &all.data.bits_per_pixel, &all.data.line_length,
                                  &all.data.endian);
	init_player(&all);
	mlx_hook(all.data.mlx_win, 2, 1L<<0, &control_player, &all);
	mlx_loop_hook(all.data.mlx, render_next_frame, &all);
	mlx_loop(all.data.mlx);
}