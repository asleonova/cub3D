#include "cub3d.h"
#include <mlx.h>

#define SCALE 20
// typedef struct  s_data {
//     void        *img;
//     char        *addr;
//     int         bits_per_pixel;
//     int         line_length;
//     int         endian;
// }               t_data;

void            my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
    char    *dst;

    dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
    *(unsigned int*)dst = color;
}

void draw_cub(t_data *data, int x, int y)
{
    int i = 0;
    int j = 0;
    while (i <= 32)
    {
        j = 0;
        while (j <= 32)
        {
            my_mlx_pixel_put(data, x + i, y + j, 0x000000FF);
            j++;
        }
        i++;
    }
}

void draw_map(t_data *data)
{
    int i = 0;
    while(i < 5)
    {
        draw_cub(data, data->cub_x, data->cub_y);
        data->cub_x += 32;
        i++;
    }
   // draw_player(data);
}

int             main(void)
{ 
    void    *mlx;
    void    *mlx_win;
    t_data  img;
	int x;
	int y = 0;
	int map_x = 8;
	int map_y = 8;
	//int map_s = 64;
	int map[] =
	{
		1, 1, 1, 1, 1, 1, 1, 1,
		1, 0, 1, 0, 0, 0, 0, 1,
		1, 0, 1, 0, 0, 0, 0, 1,
		1, 0, 1, 0, 0, 0, 0, 1,
		1, 0, 0, 0, 0, 0, 0, 1,
		1, 0, 0, 0, 0, 1, 0, 1,
		1, 0, 0, 0, 0, 0, 0, 1,
		1, 1, 1, 1, 1, 1, 1, 1,
	};


    mlx = mlx_init();
    mlx_win = mlx_new_window(mlx, 500, 500, "Hello world!");
	img.img = mlx_new_image(mlx, 500, 500);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
                                  &img.endian);
	// while (y++ < 200)
	// {
	// 	x = 100;
	// 	while(x++ < 200)
	// 		my_mlx_pixel_put(&img, x, y, 0x00FF0000);
	// 		mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
	// }

	while (y/SCALE < map_y)
	{
		x = 0;
		while (x/SCALE < map_x)
		{
			// if (map[y * map_x + x] == 1)
			if (map[y/SCALE * map_x + x/SCALE] == 1)
			{
				my_mlx_pixel_put(&img, x + 1, y, 0x000000FF);
				//draw_cub(&img, x, y);
				//draw_map(&img);
				mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
			}
			else
			{
				my_mlx_pixel_put(&img, x + 1, y, 0x00FF0000);
				mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
			}
			
			x++;
		}
		y++;
	}
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