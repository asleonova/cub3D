/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csnowbal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/30 12:47:44 by csnowbal          #+#    #+#             */
/*   Updated: 2020/05/04 18:29:01 by csnowbal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Safer strcpy version.
** Takes the 'dest' size as a parameter and will not write more
** than that many bytes, to prevent buffer overflow.
*/

size_t	ft_strlcpy(char *dest, char *src, size_t size)
{
	const char	*osrc;
	size_t		n;

	osrc = src;
	n = size;
	if (n)
	{
		while (--n)
		{
			if (*src)
				*dest++ = *src++;
		}
	}
	if (n == 0)
	{
		if (size)
			*dest = '\0';
		while (*src++)
			;
	}
	return (src - osrc - 1);
}
