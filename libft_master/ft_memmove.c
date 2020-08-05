/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csnowbal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/30 12:51:39 by csnowbal          #+#    #+#             */
/*   Updated: 2020/05/03 17:57:50 by csnowbal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Copies 'n' bytes from memory area 'src' to memory area 'dest'.
** At the same time, memory areas may overlap.
*/

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char	*ptr_1;
	unsigned char	*ptr_2;

	ptr_1 = (unsigned char *)dest;
	ptr_2 = (unsigned char *)src;
	if (ptr_1 < ptr_2)
		while (n--)
			*ptr_1++ = *ptr_2++;
	else
		while (n--)
			ptr_1[n] = ptr_2[n];
	return (dest);
}
