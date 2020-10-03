/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbliss <dbliss@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/05 13:26:35 by dbliss            #+#    #+#             */
/*   Updated: 2020/10/03 23:34:23 by dbliss           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

#include <stdlib.h>
#include <fcntl.h>
#include <mlx.h>
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
#define S_LENGTH 1200// length of the screen
#define S_WIDTH 800 // width of the screen
#define SCREEN_CENTER 400 // (1/2 width)

typedef struct  s_player {
	float x;
	float y;
    float dir;
    float angle; // angle between subsequent rays
    float fov_start;
    float dist_to_screen;
    float proj_slice_h[S_LENGTH]; // потом сделать динамически
    float ceiling[S_LENGTH];

}               t_player;

typedef   struct s_cross {
    float hx;
    float hy;
    float vx;
    float vy;
    float h_dy; // смещение по y
    float h_dx; // смещение по x
    float v_dy; // cмещение по y
    float v_dx; // смещение по x
    float h_distance;
    float v_distance;
    float closest_cross;
    float right_distance;
    float wall_x;
    float wall_y;
    float offset[S_LENGTH];
}                t_cross;

typedef struct  s_map {
    
	int x;
	int y;
}               t_map;

typedef struct s_data
{
    void *img;
    char *addr;
    int bits_per_pixel;
    int line_length;
    int endian;
    void *mlx;
    void *mlx_win;

}       t_data;

typedef struct s_texture_data
{
   void *img;
   char  *relative_path;
   int   img_width;
   int   img_height;
   int   line_length;
   int   bits_per_pixel;
   int   endian;
   char  *addr;
   float x_image_to_texture_ratio; // это пока не использую
}             t_texture_data;

typedef struct  s_all
{
    t_data  data;
    t_player player;
    t_map   map;
    t_cross cross;
    t_texture_data texture;
}               t_all;

#endif
