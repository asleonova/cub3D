/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alkanaev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/08 12:27:27 by alkanaev          #+#    #+#             */
/*   Updated: 2019/11/18 13:17:22 by alkanaev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t len)
{
	unsigned int	i;
	unsigned char	*sdest;
	unsigned char	*ssrc;

	sdest = (unsigned char*)dest;
	ssrc = (unsigned char*)src;
	i = 0;
	if (sdest == NULL && ssrc == NULL)
		return (NULL);
	while (i < len)
	{
		sdest[i] = ssrc[i];
		i++;
	}
	return (dest);
}
