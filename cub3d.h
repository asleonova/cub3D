/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbliss <dbliss@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/05 13:26:35 by dbliss            #+#    #+#             */
/*   Updated: 2020/10/05 21:43:38 by dbliss           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

#include <stdlib.h>
#include <fcntl.h>
#include "./mlx/mlx.h"
#include <stdio.h>
#include <math.h>
#include "libft/libft.h" 


#define W 13
#define A 0
#define S 1
#define D 2
#define ESC 53
#define SCALE 64
#define LEFT 123
#define RIGHT 124
#define MAX 640
#define S_WIDTH 1200 // length of the screen
#define S_HEIGHT 800 // width of the screen
#define SCREEN_CENTER 400 // (1/2 width)

typedef struct  s_player {
float x;
float y;
float dir;
float angle; // angle between subsequent rays
float fov_start;
float dist_to_screen;
float slice_height[S_WIDTH]; // потом сделать динамически
float ceiling[S_WIDTH];

}               t_player;

typedef struct  s_sprite {
    float x;
    float y;
    float dir; // угол между линией от игрока к спрайту и осью x.
    float delta; // относительный угол между направлением взгляда игрока и спрайтом 
    float dist; // расстояние между игроком и спрайтом
    float size; // размер спрайта
    int     img_height;
    float     h_offset; // координаты верхнего левого угла спрайта на экране
    float     v_offset;  // координаты верхнего левого угла спрайта на экране
    float     height;
    float     width;

}               t_sprite;
typedef enum    e_hit_side
{
    north = 0,
    east = 1,
    south = 2,
    west = 3
}               t_hit_side;

typedef   struct    s_cross {
    float   hx;
    float   hy;
    float   vx;
    float   vy;
    float   h_dy; // смещение по y
    float   h_dx; // смещение по x
    float   v_dy; // cмещение по y
    float   v_dx; // смещение по x
    float   h_distance;
    float   v_distance;
    float   closest_cross;
    float   right_distance;
    float   wall_x;
    float   wall_y;
    float   offset[S_WIDTH];
    int     hit; // 1 - hit horizontally, 0 - hit vertically
    t_hit_side      hit_side;
}                   t_cross;

typedef struct  s_map {
    
	int x;
	int y;
}               t_map;

typedef struct s_data
{
    void    *img;
    char    *addr;
    int     bits_per_pixel;
    int     line_length;
    int     endian;
    void    *mlx;
    void    *mlx_win;

}       t_data;

typedef struct  s_texture_data 
{
   void     *img;
   char     *relative_path;
   int      img_width;
   int      img_height;
   int      line_length;
   int      bits_per_pixel;
   int      endian;
   char     *addr;
}               t_texture_data;

typedef struct  s_all
{
    int     **make_map;
    t_data  data;
    t_player player;
    t_map   map;
    t_cross cross;
    t_texture_data texture[4];
    t_sprite    **sprite;
}               t_all;

void    init_all(t_all *all);
void    my_mlx_pixel_put(t_data *data, int x, int y, int color);
void    draw_wall(t_all *all, int width);
void    draw_player(t_all *all); 
void    draw_map(t_all *all);
void    draw_ray(t_all *all);
void    draw_ceiling(t_all *all, int width);
void    draw_floor(t_all *all, int width);

void 	horizontal_cross(t_all *all);
void	vertical_cross(t_all *all);
void    horizontal_hit(t_all *all);
void    vertical_hit(t_all *all);
void    shortest_distance(t_all *all, int i);
void    fix_angle(float *angle);
void    calculate_wall(t_all *all, int i);
void    find_wall(t_all *all);

void draw_sprite(t_all *all, int i);
int     control_player(int keycode, t_all *all);
int     render_next_frame(t_all *all);
void	draw_ray(t_all *all);
// void	find_two(t_all *all);
t_sprite **init_sprites(t_all *all);

#endif
