#include "libft.h"

void	*ft_memalloc(size_t size)
{
	void	*mem;

	mem = malloc(size);
	ft_bzero(mem, size);
	return (mem);
}
