#include "cub3d.h"

/*
В общем это каркас как основая идея того, что я хотела

int				param_validation(t_param *param, char *content)
{
if (*content == 0)
		return (0);
	else if (content[0] == 'R' && content[1] == ' ')
		return ();
	else if (content[0] == 'N' && content[1] == 'O' && content[1] == ' ')
		return ();
	else if (content[0] == 'S' && content[1] == 'O' && content[1] == ' ')
		return ();
	else if (content[0] == 'W' && content[1] == 'E' && content[1] == ' ')
		return ();
	else if (content[0] == 'E' && content[1] == 'A' && content[1] == ' ')
		return ();
	else if (content[0] == 'F' && content[1] == ' ')
		return ();
	else if (content[0] == 'C' && content[1] == ' ')
		return ();
	else if (content[0] == 'S' && content[1] == ' ')
		return ();
	else if (content[0] == '1'  && (content[1] == '1' || content[1] == '0')
		return ();
	else
		return ("error-func");
}
*/

char	**make_map(t_flags **head, int size)
{
	char **map;
	int i;
	t_flags *tmp;

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
	t_flags *head;

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