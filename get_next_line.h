#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <unistd.h>
# include <stdlib.h>

typedef struct	s_fl
{
	char		*buffer;
	int			pos;
	int			bytes_read;
	int			fd;
}				t_fl;
int				get_next_line(int fd, char **line);
int				find_line(t_fl *fl);
char			*ft_strnjoin(char *s1, char const *s2, size_t n);
int				init(t_fl *fl, int fd, char **line);
int				reinit(t_fl *fl);
void			ft_putstr_fd(char *s, int fd);

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 100
#endif
#endif