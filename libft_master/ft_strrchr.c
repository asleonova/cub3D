/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alkanaev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/08 12:47:14 by alkanaev          #+#    #+#             */
/*   Updated: 2019/11/18 13:47:01 by alkanaev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int sym)
{
	int		i;
	char	*s2;

	i = 0;
	while (str[i])
		i++;
	s2 = (char*)str;
	while (i != 0 && s2[i] != sym)
		i--;
	if (s2[i] == sym)
		return (&s2[i]);
	if (s2[i] == '\0' && sym == '\0')
		return (&s2[i]);
	return (NULL);
}
