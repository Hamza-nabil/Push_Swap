/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnabil <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/08 12:46:48 by hnabil            #+#    #+#             */
/*   Updated: 2021/06/08 12:46:50 by hnabil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	**get_arg(int argc, char **argv)
{
	char	*tmp;
	char	*array;
	int		i;

	i = -1;
	array = ft_strdup("");
	while (++i < argc)
	{
		tmp = array;
		array = ft_strjoin(array, argv[i]);
		free(tmp);
		tmp = array;
		array = ft_strjoin(array, " ");
		free(tmp);
	}
	return (ft_split(array, ' '));
}

int	get_num(char *arg, int *nb)
{
	long int	res;
	int			sign;

	sign = 1;
	res = 0;
	if (*arg == '-')
		sign = -1;
	if ((*arg == '-' || *arg == '+') && ft_isdigit(*(arg + 1)))
		++arg;
	while (*arg && ft_isdigit(*arg))
	{
		res = res * 10 + (*arg++ - 48);
		if (res > 2147483648 || (sign > 0 && res == 2147483648))
			return (1);
	}
	if (*arg)
		return (1);
	*nb = ((int)(res * sign));
	return (0);
}

static int	index_of(int *arr, int l, int r, int x)
{
	int	mid;

	if (r >= l)
	{
		mid = l + (r - l) / 2;
		if (arr[mid] == x)
			return (mid);
		if (arr[mid] > x)
			return (index_of(arr, l, mid - 1, x));
		return (index_of(arr, mid + 1, r, x));
	}
	return (-1);
}

int	fill_a(t_all *a, int *array, int *sorted, int ac)
{
	int	index;
	int	i;

	heap_sort(sorted, ac - 1);
	i = ac - 1;
	while (--i >= 0)
	{
		index = index_of(sorted, 0, ac - 1, array[i]);
		if ((index < (ac - 1) && array[i] == sorted[index + 1])
			|| (index > 0 && array[i] == sorted[index - 1]))
		{
			free_stack(a);
			return (0);
		}
		ft_stackadd(a, ft_stacknew(index + 1));
	}
	return (1);
}

int	read_arg(int ac, char **av, t_all *a)
{
	int	*array;
	int	*sorted;
	int	i;
	int	nb;

	array = malloc(sizeof(int) * (ac - 1));
	sorted = malloc(sizeof(int) * (ac - 1));
	i = 0;
	while (++i < ac && !get_num(av[i], &nb))
	{
		array[i - 1] = nb;
		sorted[i - 1] = array[i - 1];
	}
	if (i < ac)
		i = 0;
	else
		i = fill_a(a, array, sorted, ac);
	free(sorted);
	free(array);
	return (i);
}
