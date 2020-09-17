/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbliss <dbliss@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/05 13:26:35 by dbliss            #+#    #+#             */
/*   Updated: 2020/09/17 20:16:32 by dbliss           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

#include <stdlib.h>
#include <fcntl.h>

typedef struct	s_flags
{
	char		**head;
    char		*content;
    char        *next;
}				t_flags;

typedef struct s_data
{
    char *map; // карта
    int resolution_x; // разрешение экрана
    int resolution_y; // разрешение экрана
    int coordinates_x; // текущие координаты по X
    int coordinates_y; // текущие координаты по Y
    double vector;
    int cub_x;
    int cub_y;
    void *img;
    char *addr;
    int bits_per_pixel;
    int line_length;
    int endian;
    void *mlx;
    void *win;
    void *mlx_win;

}       t_data;


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

char    **make_map(t_flags **head, int size);

#endif