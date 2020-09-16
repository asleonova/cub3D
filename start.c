#include "cub3d.h"
#include <mlx.h>

int     main(void)
{
    void    *mlx;
    void    *mlx_win;

    mlx = mlx_init();
    mlx_win = mlx_new_window(mlx, 1920, 1080, "Hello world!");
    mlx_loop(mlx);
}  
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

/*void	ft_bzero(void *smt, size_t len)
{
	size_t	i;

	i = 0;
	while (i < len)
	{
		((char *)smt)[i] = 0;
		i++;
	}
}

void	*ft_calloc(size_t num, size_t size)
{
	size_t			i;
	unsigned char	*res;

	i = 0;
	if (!(res = (unsigned char *)malloc(size * num)))
		return (NULL);
	ft_bzero(res, size * num);
	if (num == 0 || size == 0)
		return ((void*)res);
	return(res);
}

int	ft_lstsize(t_list *lst)
{
	int		cnt;
	t_list	*tmp;

	cnt = 0;
	tmp = lst;
	while (tmp)
	{
		cnt++;
		tmp = tmp->next;
	}
	return (cnt);
}

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*tmp;

	if (!lst || !new)
		return ;
	if (!*lst)
	{
		*lst = new;
		return ;
	}
	tmp = *lst;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = new;
}

t_list	*ft_lstnew(void *content)
{
	t_list	*new;

	if (!(new = malloc(sizeof(t_list))))
		return (NULL);
	new->content = content;
	new->next = NULL;
	return (new);
}

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

void	ft_putstr_fd(char *s, int fd)
{
	if (s)
		write(fd, s, ft_strlen(s));
}

void	ft_putendl_fd(char *s, int fd)
{
	ft_putstr_fd(s, fd);
	ft_putchar_fd('\n', fd);
}

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
*/