/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csnowbal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/30 12:52:35 by csnowbal          #+#    #+#             */
/*   Updated: 2020/05/03 09:53:33 by csnowbal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Overwrites string bytes to zero bytes of length 'n'.
*/

void	ft_bzero(void *str, size_t len)
{
	unsigned char	*ptr;

	if (!str)
		return ;
	ptr = (unsigned char *)str;
	while (len--)
		*ptr++ = '\0';
}
