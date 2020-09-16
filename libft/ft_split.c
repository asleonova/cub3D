/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alkanaev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/08 12:38:11 by alkanaev          #+#    #+#             */
/*   Updated: 2019/11/18 14:02:38 by alkanaev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	find_sep(char ch, char sep)
{
	if (sep == ch)
		return (1);
	return (0);
}

static int	count_non_sep(char *str, char sep)
{
	int	i;
	int	counter;

	i = 0;
	counter = 0;
	while (str[i])
	{
		if (!(find_sep(str[i], sep)) && ((find_sep(str[i + 1], sep))
					|| str[i + 1] == '\0'))
			counter++;
		i++;
	}
	return (counter);
}

static int	len_non_sep(char *str, char sep)
{
	int	i;

	i = 0;
	while (!(find_sep(str[i], sep)) && str[i])
		i++;
	return (i);
}

static char	*modified_strdup(char const *str, char sep)
{
	int		i;
	int		len;
	char	*array;

	len = len_non_sep((char*)str, sep);
	if (!(array = (malloc(sizeof(char) * (len + 1)))))
		return (NULL);
	i = 0;
	while (i < len)
	{
		array[i] = str[i];
		i++;
	}
	array[i] = '\0';
	return (array);
}

char		**ft_split(char const *s, char c)
{
	int		i;
	int		j;
	int		non_sep_cnt;
	char	**result;

	i = 0;
	j = 0;
	if (s == NULL)
		return (NULL);
	non_sep_cnt = count_non_sep((char*)s, c);
	if (!(result = malloc(sizeof(char*) * non_sep_cnt + 1)))
		return (NULL);
	while (j < non_sep_cnt)
	{
		while (s[i] && (find_sep(s[i], c)))
			i++;
		result[j] = modified_strdup(&s[i], c);
		while (s[i] && (!(find_sep(s[i], c))))
			i++;
		j++;
	}
	result[j] = NULL;
	return (result);
}
