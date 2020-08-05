/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csnowbal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/30 12:50:49 by csnowbal          #+#    #+#             */
/*   Updated: 2020/05/06 16:27:21 by csnowbal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Byte by byte compares strings 's1' and 's2'.
** Comparison stops if different characters are encountered.
** Or if 'n' characters were checked or both compared strings ended, return 0.
** s1 = s2 -> 0
** s1 > s2 -> +
** s1 < s2 -> -
*/

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned char	*ptr_1;
	unsigned char	*ptr_2;
	size_t			i;

	ptr_1 = (unsigned char *)s1;
	ptr_2 = (unsigned char *)s2;
	i = 0;
	while (n--)
	{
		if (ptr_1[i] != ptr_2[i])
			return (ptr_1[i] - ptr_2[i]);
		i++;
	}
	return (0);
}
