/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbliss <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/29 22:22:46 by dbliss            #+#    #+#             */
/*   Updated: 2020/10/29 22:22:48 by dbliss           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_len(int n)
{
	int		len;

	len = 1;
	if (n < 0)
		len++;
	while ((n != 0) && (n <= -10 || n >= 10))
	{
		n = n / 10;
		len++;
	}
	return (len);
}

static char	*ft_stocknbr(int n, char *str)
{
	int		i;
	int		power;
	int		save;

	i = -1;
	power = 1;
	save = n;
	if (n < 0)
	{
		i = 0;
		power = -1;
		str[i] = '-';
	}
	while (n <= -10 || n >= 10)
	{
		n = n / 10;
		power = power * 10;
	}
	while (power != 0)
	{
		str[++i] = save / power + '0';
		save = save - (save / power) * power;
		power = power / 10;
	}
	return (str);
}

char		*ft_itoa(int n)
{
	int		i;
	int		len;
	char	*out;

	i = 0;
	len = ft_len(n);
	if (!(out = malloc(sizeof(*out) * (len + 1))))
		return (0);
	out = ft_stocknbr(n, out);
	out[len] = '\0';
	return (out);
}
