#include "libft.h"

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