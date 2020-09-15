/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbliss <dbliss@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/05 13:26:35 by dbliss            #+#    #+#             */
/*   Updated: 2020/08/05 15:43:30 by dbliss           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

#include "libft_master/libft.h"
#include "get_next_line.h"
#include <stdlib.h>
#include <fcntl.h>

typedef struct	s_flags
{
	char		**head;
    char		*content;
    char        *next;
}				t_flags;

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