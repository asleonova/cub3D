/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alkanaev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/08 12:33:00 by alkanaev          #+#    #+#             */
/*   Updated: 2019/11/18 13:04:32 by alkanaev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t len)
{
	char *ssrc;
	char *sdest;

	ssrc = (char*)src;
	sdest = (char*)dest;
	if (sdest == NULL && ssrc == NULL)
		return (NULL);
	if (ssrc < sdest)
	{
		ssrc = ssrc + (len - 1);
		sdest = sdest + (len - 1);
		while (len > 0)
		{
			*sdest-- = *ssrc--;
			len--;
		}
	}
	else
		while (len > 0)
		{
			*sdest++ = *ssrc++;
			len--;
		}
	return (dest);
}
