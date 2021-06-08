#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*d;
	unsigned char	*s;

	if (!src && !dst)
		return (NULL);
	d = dst;
	s = (unsigned char *)src;
	i = -1;
	while (++i < n)
		*(d + i) = *(s + i);
	return (dst);
}
