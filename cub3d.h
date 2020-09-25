/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbliss <dbliss@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/05 13:26:35 by dbliss            #+#    #+#             */
/*   Updated: 2020/09/25 18:04:08 by dbliss           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

#include <stdlib.h>
#include <fcntl.h>

#define W 13
#define A 0
#define S 1
#define D 2
#define ESC 53
#define SCALE 64

// typedef struct	s_flags
// {
// 	char		**head;
//     char		*content;
//     char        *next;
// }				t_flags;

typedef struct  s_player {

    float start;
    float end;
	float x;
	float y;
    float dx; // delta x (конечная разность) or maybe it's a direction????
    float dy; // delta y
    float pa; // player's angle
    float dir;
}               t_player;

typedef   struct s_cross {
    float hx;
    float hy;
    float vx;
    float vy;
    float h_dy; // delta по y
    float h_dx;
    float v_dy;
    float v_dx;
}                t_cross;

typedef struct  s_map {
    
	int x;
	int y;
}               t_map;

typedef struct s_data
{
    //int resolution_x; // разрешение экрана
    //int resolution_y; // разрешение экрана
    //int coordinates_x; // текущие координаты по X
    //int coordinates_y; // текущие координаты по Y
    //double vector;
    //int cub_x;
    //int cub_y;
    void *img;
    char *addr;
    int bits_per_pixel;
    int line_length;
    int endian;
    void *mlx;
    void *mlx_win;

}       t_data;

typedef struct  s_all
{
    t_data  data;
    t_player player;
    t_map   map;
    t_cross cross;
}               t_all;


/*
Пока закомментирую, так как код с этой структурой удалила - надо переработать.
typedef struct	s_param
{
	int		    resolution;
    char		*no;
	char		*so;
	char		*ea;
	char		*we;
	char		*sprite;
	int		    ceiling;
	int		    floor;
	int 		map;
}				t_param;
*/

//char    **make_map(t_flags **head, int size);

#endif