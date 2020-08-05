/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csnowbal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/30 12:51:37 by csnowbal          #+#    #+#             */
/*   Updated: 2020/05/03 18:00:59 by csnowbal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Fills the first 'n' bytes memory ares 's' with character 'c'.
*/

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char	*ptr;
	unsigned char	sym;

	ptr = (unsigned char *)s;
	sym = (unsigned char)c;
	while (n--)
		*(ptr++) = sym;
	return (s);
}
