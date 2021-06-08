#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	unsigned char	*p;

	p = ft_memalloc(count * size);
	return (p);
}
