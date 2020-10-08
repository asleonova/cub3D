#include "../cub3d.h"

void	cast_ray(t_all *all)
{
	all->player.fov_start = all->player.dir + M_PI / 6;
	int i = 0;
	while (i < S_WIDTH)
	{
		fix_angle(&all->player.fov_start); // for each ray
		horizontal_cross(all); // for each ray
		vertical_cross(all); // for each ray
		horizontal_hit(all); // for each ray
		vertical_hit(all); // for each ray
		shortest_distance(all, i); // for each ray
        //draw_ray(all);
		find_wall(all, i);
		calculate_wall(all, i);
		all->player.fov_start -= all->player.angle; // change the ray position
		i++;
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

// int				**init_int_map(int ***map)
// {
// 	int i;
// 	int j;

// 	i = 0;
// 	j = 0;
// 	(*map)[i] = malloc(sizeof(int) * 11);
// 	while (i != 10)
// 	{
// 		while (j != 10)
// 		{
// 			(*map)[i][j] = malloc(sizeof(int) * 11);
// 			j++;
// 		}
// 		j = 0;
// 		i++;
// 	}
// 	(*map) = {// нужно обязательно найти потом макс. кол-во элементов массива
//     { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 },
//     { 1, 0, 0, 0, 0, 0, 0, 0, 0, 1 },
//     { 1, 0, 0, 0, 0, 0, 0, 1, 0, 1 },
// 	{ 1, 0, 0, 0, 0, 0, 0, 0, 0, 1 },
// 	{ 1, 0, 0, 0, 0, 0, 0, 0, 0, 1 },
// 	{ 1, 0, 0, 0, 0, 0, 0, 0, 0, 1 },
// 	{ 1, 0, 0, 0, 0, 0, 0, 0, 0, 1 },
// 	{ 1, 0, 0, 0, 0, 0, 0, 0, 0, 1 },
// 	{ 1, 0, 0, 0, 0, 0, 0, 0, 0, 1 },
// 	{ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 }
// 	};
// }

// мб как-то потом сделаать одной функцией, в которую передается нужная текстура ???
void get_texture_data_north(t_all *all)
{
	all->texture[north].relative_path = "./north_wall.xpm";
	all->texture[north].img = mlx_xpm_file_to_image(all->data.mlx, all->texture[north].relative_path, &all->texture[north].img_width, &all->texture[north].img_height);
	all->texture[north].addr = mlx_get_data_addr(all->texture[north].img, &all->texture[north].bits_per_pixel, &all->texture[north].line_length, &all->texture[north].endian);
}

void get_texture_data_south(t_all *all)
{
	all->texture[south].relative_path = "./south_wall.xpm";
	all->texture[south].img = mlx_xpm_file_to_image(all->data.mlx, all->texture[south].relative_path, &all->texture[south].img_width, &all->texture[south].img_height);
	all->texture[north].addr = mlx_get_data_addr(all->texture[south].img, &all->texture[south].bits_per_pixel, &all->texture[south].line_length, &all->texture[south].endian);
}

void get_texture_data_east(t_all *all)
{
	all->texture[east].relative_path = "./east_wall.xpm";
	all->texture[east].img = mlx_xpm_file_to_image(all->data.mlx, all->texture[east].relative_path, &all->texture[east].img_width, &all->texture[east].img_height);
	all->texture[east].addr = mlx_get_data_addr(all->texture[east].img, &all->texture[east].bits_per_pixel, &all->texture[east].line_length, &all->texture[east].endian);
}

void get_texture_data_west(t_all *all)
{
	all->texture[west].relative_path = "./west_wall.xpm";
	all->texture[west].img = mlx_xpm_file_to_image(all->data.mlx, all->texture[west].relative_path, &all->texture[west].img_width, &all->texture[west].img_height);
	all->texture[west].addr = mlx_get_data_addr(all->texture[west].img, &all->texture[west].bits_per_pixel, &all->texture[west].line_length, &all->texture[west].endian);
}

void init_textures(t_all *all)
{
	get_texture_data_north(all);
	get_texture_data_south(all);
	get_texture_data_east(all);
	get_texture_data_west(all);
}

int             main(void)
{ 
	t_all	all;

	// all.make_map = init_int_map(&all.make_map);
    all.data.mlx = mlx_init();
    all.data.mlx_win = mlx_new_window(all.data.mlx, S_WIDTH, S_HEIGHT, "CUB_3D!");

	all.data.img = mlx_new_image(all.data.mlx, S_WIDTH, S_HEIGHT);
	all.data.addr = mlx_get_data_addr(all.data.img, &all.data.bits_per_pixel, &all.data.line_length,
                                  &all.data.endian);

	init_textures(&all);
	init_player(&all);
	mlx_hook(all.data.mlx_win, 2, 1L<<0, &control_player, &all);
	mlx_loop_hook(all.data.mlx, render_next_frame, &all);
	mlx_loop(all.data.mlx);
}