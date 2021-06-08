#include "libft.h"

void	ft_putendl(char *s)
{
	if (!s)
		return ;
	ft_putstr(s);
	ft_putchar('\n');
}
