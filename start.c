/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbliss <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/04 20:31:45 by dbliss            #+#    #+#             */
/*   Updated: 2020/08/04 20:31:50 by dbliss           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
