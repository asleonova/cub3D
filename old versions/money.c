#include "cub3d.h"
void my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
    char *dst;
    dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
    *(unsigned int*)dst = color;
}
void draw_cub(t_data *data, int x, int y)
{
    int i = 0;
    int j = 0;
    while (i <= 32)
    {
        j = 0;
        while (j <= 32)
        {
            if (j == 32)
            {   
                my_mlx_pixel_put(data, x + i, y + j, 0x000000FF);
                j++;
            }
        }
        i++;
    }
}
void draw(t_data *data)
{
    mlx_put_image_to_window(data->mlx, data->win, data->img, 0, 0); // create img
}
void draw_player(t_data *data)
{
    if(data->coordinates_x >= 32 && data->coordinates_y >= 32 )
        draw_cub(data, data->coordinates_x, data->coordinates_y);
    draw(data);
}
void draw_map(t_data *data)
{
    int i = 0;
    while(i < 5)
    {
        draw_cub(data, data->cub_x, data->cub_y);
        data->cub_x += 32;
        i++;
    }
    draw_player(data);
}
int control_player(int keycode, t_data *data)
{
    if(keycode == 53)
        mlx_destroy_window(data->mlx, data->win);
    else if(keycode == 0)
        data->coordinates_x -= 32;
    else if(keycode == 1)
        data->coordinates_y += 32;
    else if(keycode == 2)
        data->coordinates_x += 32;
    else if(keycode == 13 && data->coordinates_x >= 32)
        data->coordinates_y -= 32;
    else if(keycode == 126 || keycode == 124)
        data->vector += 5;
    else if(keycode == 125 || keycode == 123)
        data->vector -=5;
    printf("%d-%d-%d-%f\n", keycode, data->coordinates_x, data->coordinates_y, data->vector);
    draw_player(data);
    return (1);
}
int             main(int argc, char **argv)
{
    t_data      data;
    // ошибки подачи
    //parser(argv[1], &data);
    data.map = "1, 1, 1, 1, 1";
    data.resolution_x = 600;
    data.resolution_y = 400;
    data.cub_x = 0;
    data.cub_y = 0;
    data.coordinates_x = 32;
    data.coordinates_y = 32;
    data.vector = 0;
    data.mlx = mlx_init();
    data.win = mlx_new_window(data.mlx, data.resolution_x, data.resolution_y, "cub3d");
    data.img = mlx_new_image(data.mlx, data.resolution_x, data.resolution_y);
    data.addr = mlx_get_data_addr(data.img, &data.bits_per_pixel, &data.line_length, &data.endian);
    draw_map(&data);
    mlx_key_hook(data.win, control_player, &data);
    mlx_put_image_to_window(data.mlx, data.win, data.img, 0, 0); // create img
    mlx_loop(data.mlx);
}
// gcc -L. -l mlx cub3d.c && ./a.out