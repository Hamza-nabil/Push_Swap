#include "libft.h"

int	is_set(char c, char const *set)
{
	while (*set)
	{
		if (*set == c)
			return (1);
		set++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*p;
	int		i;
	int		j;

	if (!s1 || !set)
		return (0);
	i = 0;
	j = ft_strlen(s1) - 1;
	while (is_set(s1[i], set))
		i++;
	while (is_set(s1[j], set) && j)
		j--;
	if (i > j)
		return (ft_strdup(""));
	p = ft_substr(s1, i, j - i + 1);
	return (p);
}
