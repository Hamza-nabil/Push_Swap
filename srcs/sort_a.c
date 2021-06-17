/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_a.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnabil <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/07 17:38:23 by hnabil            #+#    #+#             */
/*   Updated: 2021/06/07 17:52:49 by hnabil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	sort_b(t_all *a, t_all *b, int start, int end)
{
	int	med;
	int	r;
	int	len;

	r = 0;
	med = (start + end) / 2;
	len = end - start + 1;
	if (start >= end || !(b->stack))
		return ;
	if (!b->stack->next && execute_instruction(a, b, "pa", 1))
		return ;
	while (b->stack && b->stack->data <= end && b->stack->data >= start)
	{
		if (b->stack->data >= med)
			execute_instruction(a, b, "pa", 1);
		else if (r++)
			execute_instruction(a, b, "rb", 1);
		if (!(len--))
			break ;
	}
	if (start != 1)
		while (--r > 0 && execute_instruction(a, b, "rrb", 1))
			;
	sort_a(a, b, med, end);
	sort_b(a, b, start, med);
}

static int	ft_sort_a(t_all *a, t_all *b, int start, int end)
{
	int	len;
	int	r;
	int	med;

	med = (start + end) / 2;
	len = end - start + 1;
	r = 0;
	while (a->stack && a->stack->data <= end && a->stack->data >= start)
	{
		if (a->stack->data <= med)
			execute_instruction(a, b, "pb", 1);
		else if (r++)
			execute_instruction(a, b, "ra", 1);
		if (!(len--))
			break ;
	}
	return (r);
}

void	sort_a(t_all *a, t_all *b, int start, int end)
{
	int				med;
	static t_stack	*s;
	int				r;

	med = (start + end) / 2;
	if (start >= end)
		return ;
	if (start > (end - 2))
	{
		if (a->stack && a->stack->next && a->stack->data > a->stack->next->data)
			execute_instruction(a, b, "sa", 1);
		return ;
	}
	r = ft_sort_a(a, b, start, end);
	if (s != NULL)
		while (--r)
			execute_instruction(a, b, "rra", 1);
	sort_a(a, b, med + 1, end);
	if (!(b->stack))
		return ;
	s = a->stack;
	sort_b(a, b, start, med);
}
