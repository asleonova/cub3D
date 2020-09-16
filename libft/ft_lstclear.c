/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alkanaev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/25 12:42:37 by alkanaev          #+#    #+#             */
/*   Updated: 2019/11/25 16:25:47 by alkanaev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*tmp;
	t_list	*tmp2;

	if (!lst || !*lst || !del)
		return ;
	tmp = *lst;
	tmp2 = tmp;
	while (tmp)
	{
		tmp2 = tmp->next;
		(*del)((void *)tmp->content);
		free(tmp);
		tmp = tmp2;
	}
	*lst = NULL;
}
