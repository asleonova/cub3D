#include "../cub3d.h"

static void init_player(t_all *all)
{
	all->player.x = 187;
	all->player.y = 213;
	all->player.dir = 3 * M_PI_2;
	all->player.angle = (M_PI / 3) / S_WIDTH; // fov / width of projection plane
	all->player.dist_to_screen = (S_WIDTH / 2) / tan(M_PI / 6); // 1/2 screen / tan(30)

}
// мб как-то потом сделаать одной функцией, в которую передается нужная текстура ???
static void get_texture_data_north(t_all *all)
{
	all->texture[north].relative_path = "./north_wall.xpm";
	all->texture[north].img = mlx_xpm_file_to_image(all->data.mlx, all->texture[north].relative_path, &all->texture[north].img_width, &all->texture[north].img_height);
	all->texture[north].addr = mlx_get_data_addr(all->texture[north].img, &all->texture[north].bits_per_pixel, &all->texture[north].line_length, &all->texture[north].endian);
}

static void get_texture_data_south(t_all *all)
{
	all->texture[south].relative_path = "./south_wall.xpm";
	all->texture[south].img = mlx_xpm_file_to_image(all->data.mlx, all->texture[south].relative_path, &all->texture[south].img_width, &all->texture[south].img_height);
	all->texture[south].addr = mlx_get_data_addr(all->texture[south].img, &all->texture[south].bits_per_pixel, &all->texture[south].line_length, &all->texture[south].endian);
}

static void get_texture_data_east(t_all *all)
{
	all->texture[east].relative_path = "./east_wall.xpm";
	all->texture[east].img = mlx_xpm_file_to_image(all->data.mlx, all->texture[east].relative_path, &all->texture[east].img_width, &all->texture[east].img_height);
	all->texture[east].addr = mlx_get_data_addr(all->texture[east].img, &all->texture[east].bits_per_pixel, &all->texture[east].line_length, &all->texture[east].endian);
}

static void get_texture_data_west(t_all *all)
{
	all->texture[west].relative_path = "./west_wall.xpm";
	all->texture[west].img = mlx_xpm_file_to_image(all->data.mlx, all->texture[west].relative_path, &all->texture[west].img_width, &all->texture[west].img_height);
	all->texture[west].addr = mlx_get_data_addr(all->texture[west].img, &all->texture[west].bits_per_pixel, &all->texture[west].line_length, &all->texture[west].endian);
}

static void init_textures(t_all *all)
{
	get_texture_data_north(all);
	get_texture_data_south(all);
	get_texture_data_east(all);
	get_texture_data_west(all);
}

void init_all(t_all *all)
{
	init_player(all);
	init_textures(all);
	init_sprites(all);
	// find_two(all);
}