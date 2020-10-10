#include "../cub3d.h"

void init_sprites(t_all *all)
{
    all->sprite.x = 200;
    all->sprite.y = 220;
    all->sprite.dir = atan2(all->sprite.y - all->player.y, all->sprite.x - all->player.x);
    all->sprite.sp_dir = all->sprite.dir - all->player.angle;
    fix_angle(&all->sprite.sp_dir);
    all->sprite.dist = sqrt(pow(all->player.x - all->sprite.x, 2) + pow(all->player.y - all->sprite.y, 2)); // по теореме пифагора
    all->sprite.size = min(200, (all->sprite.img_height / all->sprite.dist)); // 200 - устанавливаем макс размер для спрайта, height - это из картинки берем, поэтому надо будет поменять!
}