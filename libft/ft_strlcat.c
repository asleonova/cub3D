/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alkanaev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/08 12:41:23 by alkanaev          #+#    #+#             */
/*   Updated: 2019/11/25 13:38:29 by alkanaev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t			len;
	unsigned int	i;
	unsigned int	j;

	i = 0;
	j = 0;
	len = 0;
	while (dest[i])
		i++;
	while (src[len])
		len++;
	if (size <= i)
		len += size;
	else
		len += i;
	while (src[j] && (i + 1) < size)
		dest[i++] = src[j++];
	dest[i] = '\0';
	return (len);
}
