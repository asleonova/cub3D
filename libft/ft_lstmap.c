/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alkanaev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/25 12:45:25 by alkanaev          #+#    #+#             */
/*   Updated: 2019/11/25 16:27:40 by alkanaev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *list, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new;
	t_list	*dest;
	t_list	*tmp;

	(void)del;
	if (!list || !f)
		return (NULL);
	if (!(new = ft_calloc(sizeof(t_list), 1)))
		return (NULL);
	new->content = f(list->content);
	dest = new;
	while (list->next)
	{
		list = list->next;
		if (!(tmp = ft_calloc(sizeof(t_list), 1)))
			return (NULL);
		tmp->content = f(list->content);
		dest->next = tmp;
		dest = dest->next;
	}
	return (new);
}
