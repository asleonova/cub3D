/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbliss <dbliss@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/04 20:31:45 by dbliss            #+#    #+#             */
/*   Updated: 2020/08/05 14:22:23 by dbliss           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*# include "libft_master/libft.h"
# include "get_next_line/get_next_line.h"
# include <fcntl.h>
*/
#include "cub3d.h"
#include <stdlib.h>
/**
void		ft_scan(t_all *sky, char *cub)
{
	char	*line;
	int		gnl_return;
	int		fd;

	line = NULL;
	gnl_return = 1;
	fd = open(cub, O_RDONLY);
	if (fd == -1)
		ft_error(sky, ERROR_FD);
	while (gnl_return == 1)
	{
		gnl_return = get_next_line(fd, &line);
		ft_scan_line(sky, line);
		free(line);
	}
	close(fd);
	if (gnl_return == -1)
		ft_error(sky, ERROR_GNL);
	ft_position(sky);
	sky->spr = NULL;
	ft_check_sprite(sky);
	ft_check_param(sky);
}
**/
void	make_map(t_list **head, int size)
{
	char **map = calloc(size + 1, sizeof(char*));
	int i = -1;
	t_list *tmp = *head;

	while (tmp)
	{
		map[++i] = tmp->content;
		tmp = tmp->next;
	}
	i = -1;
	while (map[++i])
	{
		ft_putendl_fd(map[i], 1);
	}
}

int main (void)
{
	int fd;
	char *line;
	t_list *head;

	line = NULL;
	head = NULL;
	fd = open("map.cub", O_RDONLY);
	while (get_next_line(fd, &line))
	{
		ft_lstadd_back(&head, ft_lstnew(line));
	}
	ft_lstadd_back(&head, ft_lstnew(line));
	make_map(&head, ft_lstsize(head));

	return (0);
}