#include "libft.h"

int	ft_strisnum(char *s)
{
	if (!s)
		return (0);
	while (*s == ' ')
		s++;
	if (*s == '+' || *s == '-')
		s++;
	while (*s)
	{
		if (*s < '0' || *s > '9')
			return (0);
		s++;
	}
	return (1);
}
