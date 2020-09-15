/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alkanaev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/08 12:38:44 by alkanaev          #+#    #+#             */
/*   Updated: 2019/11/18 13:46:08 by alkanaev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *str, int sym)
{
	char	*s2;

	s2 = (char*)str;
	while (*s2)
	{
		if (*s2 == sym)
		{
			return (s2);
		}
		s2++;
	}
	if (*s2 == '\0' && sym == '\0')
		return (s2);
	return (NULL);
}
