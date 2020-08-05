/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csnowbal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/30 12:51:18 by csnowbal          #+#    #+#             */
/*   Updated: 2020/05/02 11:20:51 by csnowbal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Allocates and returns an array of “fresh” strings
** (strings ending with ’\0’ and array ending with NULL)
** obtained by spliting the string 's' with separator 'c'.
** If the allocation fails the function returns NULL and clears memory.
*/

char	**ft_split(char const *s, char c)
{
	size_t	i;
	size_t	j;
	size_t	k;
	char	**str;

	i = 0;
	k = 0;
	if (!s || !(str = (char **)malloc(sizeof(char *) * (ft_countw(s, c) + 1))))
		return (NULL);
	while (i < ft_countw(s, c))
	{
		if (!(str[i] = (char *)malloc(sizeof(char) * (ft_lenw(&s[k], c) + 1))))
		{
			ft_free(str, k);
			return (NULL);
		}
		j = 0;
		while (s[k] == c)
			k++;
		while (s[k] != c && s[k])
			str[i][j++] = s[k++];
		str[i++][j] = '\0';
	}
	str[i] = NULL;
	return (str);
}
