/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alkanaev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/08 12:46:29 by alkanaev          #+#    #+#             */
/*   Updated: 2019/11/18 14:20:14 by alkanaev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *where, const char *obj, size_t len)
{
	size_t	len_obj;

	if (*obj == '\0')
		return ((char *)where);
	len_obj = ft_strlen((char *)obj);
	while (*where != '\0' && len >= len_obj)
	{
		if (*where == *obj && ft_memcmp(where, obj, len_obj) == 0)
			return ((char *)where);
		len--;
		where++;
	}
	return (NULL);
}
