/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csnowbal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/30 12:51:01 by csnowbal          #+#    #+#             */
/*   Updated: 2020/05/03 19:50:02 by csnowbal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Safer strcat version.
** Concatenation 'dest' and 'src' strings
** until the end of the string is found or size characters are added.
** 0 at the end of concatenated lines.
*/

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	const char	*odst;
	const char	*osrc;
	size_t		n;
	size_t		dlen;

	odst = dest;
	osrc = src;
	n = size;
	while (n-- && *dest)
		dest++;
	dlen = dest - odst;
	n = size - dlen;
	if (n-- == 0)
		return (dlen + ft_strlen(src));
	while (*src)
	{
		if (n)
		{
			*dest++ = *src;
			n--;
		}
		src++;
	}
	*dest = '\0';
	return (dlen + (src - osrc));
}
