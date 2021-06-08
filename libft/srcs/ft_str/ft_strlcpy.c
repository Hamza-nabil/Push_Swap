#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	lsrc;

	if (!src)
		return (0);
	lsrc = ft_strlen(src);
	i = 0;
	if (!dst && size == 0)
		return (lsrc);
	if (size == 0)
		return (lsrc);
	while (src[i] && i + 1 < size)
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (ft_strlen(src));
}
