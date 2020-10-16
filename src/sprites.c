#include "../cub3d.h"

int map_int_2 [10] [10] = { // нужно обязательно найти потом макс. кол-во элементов массива
    { 1, 1, 2, 1, 1, 1, 1, 1, 1, 1 },
    { 1, 0, 0, 0, 0, 0, 0, 0, 0, 1 },
    { 1, 0, 0, 0, 0, 2, 0, 1, 0, 1 },
	{ 1, 0, 0, 0, 0, 0, 0, 0, 0, 1 },
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
    // int i = 0;
    all->map.y = 0;
	while (all->map.y < 10 ) // нужна будет переменная под размер карты
	{
		all->map.x = 0;
		while (all->map.x < 10) // нужна будет переменная под размер карты
		{
			if (map_int_2[all->map.y][all->map.x] == 2)
            {
                // all->sprite[i].x = all->map.x;
                // all->sprite[i].y = all->map.y;
                count++;
                // i++;
            }
			all->map.x++;
		}
		all->map.y++;
	}
    // count /= SCALE;
    return (count);
}

void get_sprite(t_all *all)
{
    int count = sprite_count(all);
    int i = 0;
    all->map.y = 0;
	while (all->map.y/SCALE < 10 ) // нужна будет переменная под размер карты
	{
		all->map.x = 0;
		while (all->map.x/SCALE < 10) // нужна будет переменная под размер карты
		{
			if (map_int_2[all->map.y / SCALE][all->map.x / SCALE] == 2 && i < count)
            {
                all->sprite[i].x = all->map.x;
                all->sprite[i].y = all->map.y;
                i++;
            }
			all->map.x++;
		}
		all->map.y++;
	}
}

t_sprite *init_sprites(t_all *all)
{
    int count = sprite_count(all);
  
    if (!(all->sprite = malloc(sizeof(t_sprite) * (count + 1))))
        return (NULL);
    // all->sprite[count] = NULL;
    return(all->sprite);
}

void	swap(int *sprite_order, double *sprite_distance)
{
	double		temp;

	temp = sprite_distance[0];
	sprite_distance[0] = sprite_distance[1];
	sprite_distance[1] = temp;
	temp = sprite_order[0];
	sprite_order[0] = sprite_order[1];
	sprite_order[1] = (int)temp;
}

void	sort_loop(int *sprite_order, double *sprite_distance, int n_sprite)
{
	char		continu;
	int			i;

	i = 0;
	continu = 1;
	while (continu)
	{
		continu = 0;
		i = 0;
		while (i < n_sprite - 1)
		{
			if (sprite_distance[i] < sprite_distance[i + 1])
			{
				continu = 1;
				swap(&sprite_order[i], &sprite_distance[i]);
			}
			i++;
		}
	}
}

void	sort_sprite(t_all *all, int *sprite_order,
					double *sprite_distance)
{
	t_sprite	*sprite;
	int			i;

	i = 0;
	sprite = all->sprite;
    get_sprite(all);
    int count = sprite_count(all);
	while (i < count)
	{
		sprite_order[i] = i;
		sprite_distance[i] = ((all->player.x - sprite[i].x)
				* (all->player.x - sprite[i].x)
				+ (all->player.y - sprite[i].y)
				* (all->player.y - sprite[i].y));
		i++;
	}
	sort_loop(sprite_order, sprite_distance, count);
	i++;
}
// void ft_swap(t_sprite *xp, t_sprite *yp) 
// { 
//     t_sprite temp = *xp; 
//     *xp = *yp; 
//     *yp = temp; 
// }

// t_sprite   **sort_sprites(t_all *all)
// {
//     int i;
//     int j;
//     int count = sprite_count(all);
//     i = 0;
//     while (i < count - 1)
// 	{
//         j = 0;
//         while (j < count - i - 1)
//         {
//             if (all->sprite[j]->dist < all->sprite[j + 1]->dist) 
// 			{
// 				ft_swap(all->sprite[j], all->sprite[j + 1]);
//             }
			
//             j++;
//         }
// 	    i++;
// 	}
//     return(all->sprite);
// }
void draw_sprite(t_all *all, int i, int j)
{
    float start = all->player.dir + M_PI / 6;
    all->sprite[j].dir = atan2(all->player.y - all->sprite[j].y, all->sprite[j].x - all->player.x);
    fix_angle(&all->sprite[j].dir);
    all->sprite[j].delta = compute_delta_angle(start, all->sprite[j].dir);
    all->sprite[j].dist = sqrt(pow(all->player.x - all->sprite[j].x, 2) + pow(all->player.y - all->sprite[j].y, 2)); // по теореме пифагора
    all->sprite[j].size = ceil(((SCALE / 4) / all->sprite[j].dist) * all->player.dist_to_screen);
    if (all->sprite[j].size > S_HEIGHT)
        all->sprite[j].size = 0;
    all->sprite[j].h_offset = all->sprite[j].delta / ((M_PI / 3) / S_WIDTH) - all->sprite[j].size / 2; 
    all->sprite[j].v_offset = SCREEN_CENTER - all->sprite[j].size / 2;
    

    if (i >= all->sprite[j].h_offset && i <= all->sprite[j].h_offset + all->sprite[j].size)
    {
        int y = 0;
        while (y < all->sprite[j].size)
        {
            my_mlx_pixel_put(&all->data, i, all->sprite[j].v_offset + y, 0x000000);
            y++;
        }
    }
}


void draw_all_sprites(t_all *all, int i)
{
    // sort_sprites(all);
    get_sprite(all);
    sort_sprite(all, all->sprite_order, all->sprite_distance);
    int j = 0;
    int count = sprite_count(all);
    while (j < count)
    {
        draw_sprite(all, i, j);
        j++;
    }

}