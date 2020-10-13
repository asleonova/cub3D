#include "../cub3d.h"

int map_int [10] [10] = { // нужно обязательно найти потом макс. кол-во элементов массива
    { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 },
    { 1, 0, 0, 0, 0, 0, 0, 0, 0, 1 },
    { 1, 0, 0, 0, 0, 2, 0, 1, 0, 1 },
	{ 1, 0, 2, 0, 0, 0, 0, 0, 0, 1 },
	{ 1, 0, 0, 0, 0, 0, 0, 0, 2, 1 },
	{ 1, 0, 0, 0, 0, 0, 0, 0, 0, 1 },
	{ 1, 0, 0, 0, 2, 0, 0, 0, 0, 1 },
	{ 1, 0, 0, 0, 0, 0, 0, 0, 0, 1 },
	{ 1, 0, 0, 0, 0, 0, 0, 0, 0, 1 },
	{ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 }
};

float   compute_delta_angle(float fov_start, float sprite_dir)
{
    float delta;
    delta =fov_start - sprite_dir;
    if (delta <= -M_PI)
        delta = 2 * M_PI + delta;
    else if (delta >= M_PI)
        delta = delta - 2 * M_PI;
    return (delta);
}

int sprite_count(t_all *all)
{
    int count = 0;
    all->map.y = 0;
	while (all->map.y/SCALE < 10 ) // нужна будет переменная под размер карты
	{
		all->map.x = 0;
		while (all->map.x/SCALE < 10) // нужна будет переменная под размер карты
		{
			if (map_int[all->map.y / SCALE][all->map.x / SCALE] == 2)
                count++;
			all->map.x++;
		}
		all->map.y++;
	}
    return (count);
}
t_sprite **init_sprites(t_all *all)
{
    int count = sprite_count(all);
  
    if (!(all->sprite = malloc(sizeof(t_sprite) * (count + 1))))
        return (NULL);
    all->sprite[count] = NULL;
    return(all->sprite);
}

void ft_swap(int *xp, int *yp) 
{ 
    int temp = *xp; 
    *xp = *yp; 
    *yp = temp; 
}

void    sort_sprites(t_all *all, t_sprite **sprites)
{
    int i;
    int j;
    int count = sprite_count(all);
    i = 0;
    while (i < count - 1)
	{
        j = 0;
        while (j < count - i - 1)
        {
            if (all->sprite[j]->dist < all->sprite[j + 1]->dist) 
			{
				ft_swap(&all->sprite[j], &all->sprite[j + 1]);
			
            j++;
        }
	    i++;
	}
}
void draw_sprite(t_all *all, int i)
{
    all->sprite.x = 220;
    all->sprite.y = 300;
    float start = all->player.dir + M_PI / 6;
    all->sprite.dir = atan2(all->player.y - all->sprite.y, all->sprite.x - all->player.x);
    fix_angle(&all->sprite.dir);
    all->sprite.delta = compute_delta_angle(start, all->sprite.dir);
    all->sprite.dist = sqrt(pow(all->player.x - all->sprite.x, 2) + pow(all->player.y - all->sprite.y, 2)); // по теореме пифагора
    all->sprite.size = ceil(((SCALE / 4) / all->sprite.dist) * all->player.dist_to_screen);
    if (all->sprite.size > S_HEIGHT)
        all->sprite.size = 0;
    all->sprite.h_offset = all->sprite.delta / ((M_PI / 3) / S_WIDTH) - all->sprite.size / 2; 
    all->sprite.v_offset = SCREEN_CENTER - all->sprite.size / 2;
    

    if (i >= all->sprite.h_offset && i <= all->sprite.h_offset + all->sprite.size)
    {
        int y = 0;
        while (y < all->sprite.size)
        {
            my_mlx_pixel_put(&all->data, i, all->sprite.v_offset + y, 0x000000);
            y++;
        }
    }
}