/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csnowbal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/30 12:51:50 by csnowbal          #+#    #+#             */
/*   Updated: 2020/05/01 19:55:26 by csnowbal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Copies the contents from memory area 'src' to memory area 'dest'.
** The copy operation ends when 'n' bytes are copied or
** after copying the first occurrence of the character 'c'.
** The function returns a pointer to the end of the dest region
** if the 'c' character was found, or NULL if 'c' is not in 'src'.
*/

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	unsigned char		sym;
	unsigned char		*ptr_1;
	const unsigned char	*ptr_2;

	sym = (unsigned char)c;
	ptr_1 = (unsigned char *)dest;
	ptr_2 = (unsigned char *)src;
	while (n--)
	{
		*ptr_1++ = *ptr_2++;
		if (*(ptr_1 - 1) == sym)
			return (ptr_1);
	}
	return (NULL);
}
