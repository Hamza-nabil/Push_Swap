#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*ret;
	int		x;

	if (!s)
		return (0);
	ret = malloc(len + 1);
	x = len;
	if (ft_strlen(s) < start)
		return (ft_strdup(""));
	while (start-- > 0)
		s++;
	while (len-- > 0)
		*ret++ = *s++;
	*ret = '\0';
	return (ret - x);
}
