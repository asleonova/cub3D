/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alkanaev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/08 12:30:58 by alkanaev          #+#    #+#             */
/*   Updated: 2019/11/18 13:27:24 by alkanaev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dest, const void *src, int sym, size_t len)
{
	size_t			i;
	unsigned char	*sdest;
	unsigned char	*ssrc;

	i = 0;
	sdest = (unsigned char *)dest;
	ssrc = (unsigned char *)src;
	if (sdest == NULL && ssrc == NULL)
		return (NULL);
	while (i < len)
	{
		sdest[i] = ssrc[i];
		if (sdest[i] == (unsigned char)sym)
			return ((void*)(sdest + i + 1));
		i++;
	}
	return (NULL);
}
