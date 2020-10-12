#include "../cub3d.h"

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

void draw_sprite(t_all *all, int i)
{
    all->sprite.x = 220;
    all->sprite.y = 300;
    float start = all->player.dir + M_PI / 6;
    all->sprite.dir = atan2(all->player.y - all->sprite.y, all->sprite.x - all->player.x);
    fix_angle(&all->sprite.dir);
    all->sprite.delta = compute_delta_angle(start, all->sprite.dir);
    all->sprite.dist = sqrt(pow(all->player.x - all->sprite.x, 2) + pow(all->player.y - all->sprite.y, 2)); // по теореме пифагора
    all->sprite.size = ceil(((SCALE / 2) / all->sprite.dist) * all->player.dist_to_screen);
    if (all->sprite.size > S_HEIGHT)
        all->sprite.size = 0;
    all->sprite.h_offset = all->sprite.delta / ((M_PI / 3) / S_WIDTH) - all->sprite.size / 2; 
    all->sprite.v_offset = SCREEN_CENTER - all->sprite.size / 2;
    



    // all->sprite.height = ceil((SCALE / all->sprite.dist) * all->player.dist_to_screen);
    // all->sprite.width = SCALE / all->sprite.dist * all->sprite.height;
    
    // all->sprite.h_offset = sin(all->sprite.sp_dir) * all->sprite.dist - all->sprite.size / 2;
    // // all->sprite.h_offset = all->sprite.sp_dir * (S_WIDTH / 2) / (M_PI / 3) + (S_WIDTH / 2) / 2 - all->sprite.size / 2;
    // all->sprite.v_offset = SCREEN_CENTER - all->sprite.size / 2;
    // all->sprite.h_offset = all->sprite.sp_dir * (S_WIDTH / 2) / (M_PI / 3) + (S_WIDTH / 2) / 2 - all->sprite.size / 2;
    // all->sprite.v_offset = SCREEN_CENTER - all->sprite.size / 2;


//     for (size_t i=0; i< all->sprite.size; i++) {
//         if (all->sprite.h_offset+i<0 || all->sprite.h_offset+i>=S_WIDTH/2) continue;
//         for (size_t j=0; j<all->sprite.size; j++) {
//             if (all->sprite.v_offset+j<0 || all->sprite.v_offset+j>=S_HEIGHT) continue;
//             my_mlx_pixel_put(&all->data, S_WIDTH/2 + all->sprite.h_offset+i, all->sprite.v_offset+j, 0x000000);
//         }
//     }
// }
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

// Найти точку начала рисования:
// если мы знаем ценитральную точку рисования, то 
// y = y центр - высота половину y спрайта
// x = x центр - высота половину y спрайта

// y центр = экран / 2
// x центр = нашли по синусу расстояние, далее, центр экрана - это расстояние, мб умножить на screen_width / srite_size
