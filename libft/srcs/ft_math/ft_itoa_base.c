#include <stdlib.h>

static int	ft_abs(int a)
{
	if (a >= 0)
		return (a);
	return (-a);
}

void	aux(int n, int b, char *ans, int *p)
{
	if (n <= -b || b <= n)
		aux(n / b, b, ans, p);
	ans[(*p)++] = "0123456789ABCDEF"[ft_abs(n % b)];
}

char	*ft_itoa_base(int value, int base)
{
	char	*ans;
	int		p;

	if (base < 2 || 16 < base)
		return (NULL);
	ans = (char *)malloc(sizeof(char) * 35);
	p = 0;
	if (base == 10 && value < 0)
		ans[p++] = '-';
	aux(value, base, ans, &p);
	ans[p] = '\0';
	return (ans);
}
