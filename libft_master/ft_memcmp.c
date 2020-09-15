/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alkanaev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/08 12:32:30 by alkanaev          #+#    #+#             */
/*   Updated: 2019/11/18 13:35:23 by alkanaev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *smt1, const void *smt2, size_t len)
{
	size_t			i;
	unsigned char	*ssmt1;
	unsigned char	*ssmt2;
	unsigned int	diff;

	i = 0;
	ssmt1 = (unsigned char*)smt1;
	ssmt2 = (unsigned char*)smt2;
	if (len == 0)
		return (0);
	while (i < len - 1 && ssmt1[i] == ssmt2[i])
		i++;
	diff = ssmt1[i] - ssmt2[i];
	return (diff);
}
