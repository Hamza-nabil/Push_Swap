/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnabil <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/07 11:06:32 by hnabil            #+#    #+#             */
/*   Updated: 2021/06/08 12:47:24 by hnabil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	sort_tree(t_all *a)
{
	if (a->stack->next != a->last)
	{
		if (a->stack->data < a->stack->next->data
			&& a->last->data < a->stack->next->data)
			execute_instruction(a, NULL, "rra", 1);
		else if (a->stack->data > a->last->data
			&& a->stack->data > a->last->prev->data)
			execute_instruction(a, NULL, "ra", 1);
	}
	if (a->stack->data > a->stack->next->data)
		execute_instruction(a, NULL, "sa", 1);
}

static void	clear_b(t_all *a, t_all *b, int med)
{
	while (b->stack)
	{
		if (b->stack->data > med)
		{
			while (a->last->data > b->stack->data)
				execute_instruction(a, b, "rra", 1);
			execute_instruction(a, b, "pa", 1);
			while (a->stack->data > med)
				execute_instruction(a, b, "ra", 1);
		}
		else
		{
			while (a->stack->data < b->stack->data)
				execute_instruction(a, b, "ra", 1);
			execute_instruction(a, b, "pa", 1);
			while (a->last->data < med)
				execute_instruction(a, b, "rra", 1);
		}
	}
}

static void	sort_five(t_all *a, t_all *b, int len)
{
	int	i;
	int	med;

	i = len - 3;
	med = (len + 1) / 2;
	if (a->stack->data == med)
		execute_instruction(a, b, "ra", 1);
	while (--i >= 0)
		execute_instruction(a, b, "pb", 1);
	sort_tree(a);
	clear_b(a, b, med);
}

void	ft_sort(t_all *a, t_all *b, int len)
{
	if (!is_sorted(a->stack, b->stack))
	{
		if (len <= 3)
			sort_tree(a);
		else if (len <= 5)
			sort_five(a, b, len);
		else
			sort_a(a, b, 1, len);
	}
}
