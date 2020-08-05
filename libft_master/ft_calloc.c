/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csnowbal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/30 12:47:53 by csnowbal          #+#    #+#             */
/*   Updated: 2020/05/06 13:01:44 by csnowbal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Returns a pointer to the allocated memory.
** Allocates enough memory for an array of 'nmemb' objects each sized
** bytes 'size'.
** The allocated memory is filled with bytes of zero value.
*/

void	*ft_calloc(size_t nmemb, size_t size)
{
	unsigned char	*new;

	if (!(new = (unsigned char *)malloc(size * nmemb)))
		return (NULL);
	ft_bzero(new, size * nmemb);
	return ((void *)new);
}
