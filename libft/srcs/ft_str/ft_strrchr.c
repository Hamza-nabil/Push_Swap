#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*last;

	last = (0);
	while (*s)
	{
		if (*s == (char)c)
			last = (char *)s;
		++s;
	}
	if (last)
		return (last);
	if ((char)c == '\0')
		return ((char *)s);
	return (0);
}
