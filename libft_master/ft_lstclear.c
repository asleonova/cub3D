/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csnowbal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/30 12:52:09 by csnowbal          #+#    #+#             */
/*   Updated: 2020/05/01 16:31:57 by csnowbal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Deletes and frees the given element and every
** successor of that element, using the function ’del’ and free.
** Finally, the pointer to the list must be set to NULL.
*/

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*cur;
	t_list	*seq;

	if (lst && *lst && del)
	{
		cur = *lst;
		while (cur)
		{
			seq = cur->next;
			ft_lstdelone(cur, del);
			cur = seq;
		}
		*lst = NULL;
	}
}
