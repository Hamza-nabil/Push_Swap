/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnabil <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/08 12:48:06 by hnabil            #+#    #+#             */
/*   Updated: 2021/06/08 14:49:20 by hnabil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_array(char **tab)
{
	int	i;

	i = -1;
	while (tab[++i])
		free(tab[i]);
}

void	ft_exit(char ***argv, int s)
{
	free_array(*argv);
	free(*argv);
	if (s == 0)
		write(1, "Error\n", 6);
	else if (s == 1)
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	exit(0);
}

/* swap two values*/
static void	swap(int *a, int *b)
{
	int		tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

static void	heapify(int *arr, int n, int i)
{
	int		largest;
	int		l;
	int		r;

	largest = i;
	l = 2 * i + 1;
	r = 2 * i + 2;
	if (l < n && arr[l] > arr[largest])
		largest = l;
	if (r < n && arr[r] > arr[largest])
		largest = r;
	if (largest != i)
	{
		swap(&arr[i], &arr[largest]);
		heapify(arr, n, largest);
	}
}

void	heap_sort(int *arr, int n)
{
	int	i;

	i = n / 2;
	while (--i >= 0)
		heapify(arr, n, i);
	i = n;
	while (--i)
	{
		swap(&arr[0], &arr[i]);
		heapify(arr, i, 0);
	}
}
