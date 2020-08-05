/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csnowbal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/30 12:51:42 by csnowbal          #+#    #+#             */
/*   Updated: 2020/05/01 16:35:42 by csnowbal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Copies 'n' bytes from memory area 'src' to memory area 'dest'.
** If 'dest' and 'src' overlap, behavior is undefined.
*/

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char		*ptr_1;
	const unsigned char	*ptr_2;

	ptr_1 = (unsigned char *)dest;
	ptr_2 = (unsigned char *)src;
	while (n--)
		*ptr_1++ = *ptr_2++;
	return (dest);
}
