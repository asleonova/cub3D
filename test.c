void ft_draw_plr(t_all *all, t_place pos)
{
 ft_pixel_put(all, all->plr->plrX, all->plr->plrY, 0x0000FF00);
 all->plr->plrStart = all->plr->dir - (M_PI_4);
 all->plr->plarEnd = all->plr->dir + (M_PI_4);
 float x = 0;
 while (all->plr->plrStart <= all->plr->plarEnd)
 {
  pos.x = all->plr->plrX;
  pos.y = all->plr->plrY;
  while (all->map[(int)(pos.y / SCALE)][(int)(pos.x / SCALE)] != '1')
  {
   pos.x = pos.x + cosf(all->plr->plrStart);
   pos.y = pos.y + sinf(all->plr->plrStart); 
   ft_pixel_put(all, pos.x, pos.y, 0x00FF0000);
  }
  x++;
  all->plr->plrStart += M_PI_2 / 1000;
 }
}

void ft_init_plr(t_all *all)
{
 t_place place;
 ft_bzero(&place, sizeof(t_place));
 while (all->map[(int)place.y])
 {
  place.x = 0;
  while (all->map[(int)place.y][(int)place.x])
  {
   if (ft_strchr("NEWS", all->map[(int)place.y][(int)place.x]))
   {
    all->plr->plrX = place.x * SCALE;
    all->plr->plrY = place.y * SCALE;
    all->plr->dir = 3 * M_PI_2;
   }
   place.x++;
  }
  place.y++;
 }
}