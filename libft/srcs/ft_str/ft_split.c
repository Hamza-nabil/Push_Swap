#include "libft.h"

static void	*ft_malfree(char **tab, size_t size, int x)
{
	void	*mem;

	mem = malloc(size);
	if (!mem)
	{
		while (x >= 0)
		{
			free(tab[x]);
			x--;
		}
		free(tab);
		return (0);
	}
	return (mem);
}

static int	word_count(char const *str, char ch)
{
	int	x;

	x = 0;
	while (*str != '\0')
	{
		while (*str == ch)
			str++;
		if (*str != ch && *str)
		{
			x++;
			while (*str != ch && *str)
				str++;
		}
	}
	return (++x);
}

static int	len(char const *str, char ch)
{
	int	x;

	x = 0;
	while (*str != ch && *str)
	{
		str++;
		x++;
	}
	return (++x);
}

char	**ft_split(char const *s, char c)
{
	int		x;
	int		y;
	char	**tab;

	x = 0;
	if (!s)
		return (0);
	tab = malloc(sizeof(char *) * word_count(s, c));
	while (*s)
	{
		while (*s == c)
			s++;
		if (*s != c && *s)
		{
			y = 0;
			tab[x] = ft_malfree(tab, len(s, c), x);
			while (*s != c && *s)
				tab[x][y++] = *s++;
			tab[x][y] = '\0';
			x++;
		}
	}
	tab[x] = NULL;
	return (tab);
}
