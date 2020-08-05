/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csnowbal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/30 12:51:58 by csnowbal          #+#    #+#             */
/*   Updated: 2020/05/02 16:03:14 by csnowbal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Iterates the list ’lst’ and applies the function
** ’f’ to the content of each element. Creates a new
** list resulting of the successive applications of
** the function ’f’. The ’del’ function is used to
** delete the content of an element if needed.
*/

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new;
	t_list	*cur_new;
	t_list	*cur_old;

	if (!lst || !(new = ft_lstnew(f(lst->content))))
		return (NULL);
	cur_new = new;
	cur_old = lst->next;
	while (cur_old)
	{
		if (!(cur_new->next = ft_lstnew(f(cur_old->content))))
		{
			ft_lstclear(&new, del);
			return (NULL);
		}
		cur_new = cur_new->next;
		cur_old = cur_old->next;
	}
	return (new);
}
