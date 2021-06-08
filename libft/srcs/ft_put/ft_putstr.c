#include "libft.h"

void	ft_putstr(char *s)
{
	if (s)
		while (*s)
			write(1, s++, 1);
}
