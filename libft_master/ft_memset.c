/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alkanaev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/08 12:36:03 by alkanaev          #+#    #+#             */
/*   Updated: 2019/11/13 14:54:28 by alkanaev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *smt, int sym, size_t len)
{
	size_t	i;

	i = 0;
	while (i < len)
	{
		((char *)smt)[i] = (const char)sym;
		i++;
	}
	return (smt);
}
