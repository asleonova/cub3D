/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csnowbal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/30 12:51:30 by csnowbal          #+#    #+#             */
/*   Updated: 2020/05/01 16:36:29 by csnowbal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Outputs the char 'c' to the file descriptor 'fd'.
*/

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}
