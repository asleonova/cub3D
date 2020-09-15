/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alkanaev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/08 12:49:17 by alkanaev          #+#    #+#             */
/*   Updated: 2019/11/18 14:23:53 by alkanaev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	nach;
	int		i;
	char	*sub;

	if (s == NULL)
		return (NULL);
	if (ft_strlen((char*)s) < (size_t)start)
		return (ft_strdup(""));
	if (!(sub = (char*)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	nach = 0;
	i = 0;
	while (nach < len)
	{
		sub[i++] = s[start++];
		nach++;
	}
	sub[i] = '\0';
	return (sub);
}
