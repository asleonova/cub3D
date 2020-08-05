/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbliss <dbliss@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/04 20:31:45 by dbliss            #+#    #+#             */
/*   Updated: 2020/08/05 15:49:27 by dbliss           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include <stdlib.h>

char	**make_map(t_list **head, int size)
{
	char **map;
	int i;
	t_list *tmp;

	if (!(map = ft_calloc(size + 1, sizeof(char*)))) // created two-dimensional array of the map size
		return (NULL); // error
	i = 0; 
	tmp = *head;

	while (tmp)
	{
		map[++i] = tmp->content; // put line into this array
		tmp = tmp->next;
	}
	i = 0;
	while (map[++i]) // when we have content in the array 
		ft_putendl_fd(map[i],1);  // print the line and put a \n after  it
	return (map); // return the map
}

int main (void)
{
	int fd;
	char *line;
	t_list *head;

	line = NULL;
	head = NULL;
	fd = open("map.cub", O_RDONLY);
	if (fd < 0)
		return(-1); // error
	while (get_next_line(fd, &line))
		ft_lstadd_back(&head, ft_lstnew(line));
	ft_lstadd_back(&head, ft_lstnew(line));
	make_map(&head, ft_lstsize(head));
	if (get_next_line(fd, &line) < 0)
		return (-1); // error
	return (0);
}