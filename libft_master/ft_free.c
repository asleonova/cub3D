/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csnowbal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/30 12:52:32 by csnowbal          #+#    #+#             */
/*   Updated: 2020/05/03 09:58:20 by csnowbal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Returns the memory used in the double pointer back to the heap.
*/

void	*ft_free(char **str, int size)
{
	int	i;

	i = 0;
	while (size > i)
		free(str[i++]);
	free(str);
	return (0);
}
