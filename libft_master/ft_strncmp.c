/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alkanaev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/08 12:45:47 by alkanaev          #+#    #+#             */
/*   Updated: 2019/11/18 13:48:13 by alkanaev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *str1, const char *str2, size_t len)
{
	size_t			i;
	unsigned char	*sstr1;
	unsigned char	*sstr2;

	i = 0;
	sstr1 = (unsigned char*)str1;
	sstr2 = (unsigned char*)str2;
	while ((sstr1[i] || sstr2[i]) && i < len)
	{
		if (sstr1[i] != sstr2[i])
			return (sstr1[i] - sstr2[i]);
		i++;
	}
	return (0);
}
