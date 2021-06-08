/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instruction.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnabil <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/08 12:46:34 by hnabil            #+#    #+#             */
/*   Updated: 2021/06/08 12:46:39 by hnabil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*************************SWAP***************************************/
int	swap(t_all *a)
{
	int	tmp;

	if (a && a->stack && a->stack->next)
	{
		tmp = a->stack->next->data;
		a->stack->next->data = a->stack->data;
		a->stack->data = tmp;
	}
	return (1);
}

/*************************PUSH***************************************/
int	push(t_all *a, t_all *b)
{
	t_stack	*tmp;

	if (a && b && b->stack)
	{
		tmp = b->stack;
		b->stack = tmp->next;
		tmp->next = a->stack;
		if (a->stack)
			a->stack->prev = tmp;
		a->stack = tmp;
		if (a->last == NULL)
			a->last = a->stack;
		if (b->stack == NULL)
			b->last = NULL;
		else
			b->stack->prev = NULL;
	}
	return (1);
}

/*************************Rotat***************************************/

int	rotate(t_all *a)
{
	t_stack	*tmp;

	if (a && a->stack && a->stack->next)
	{
		tmp = a->stack;
		a->stack = tmp->next;
		tmp->next = NULL;
		a->stack->prev = NULL;
		a->last->next = tmp;
		tmp->prev = a->last;
		a->last = tmp;
	}
	return (1);
}

/*************************Reverse Rotat***************************************/

int	reverse_rotate(t_all *a)
{
	t_stack	*tmp;

	if (a && a->stack && a->stack->next)
	{
		tmp = a->last;
		a->last = tmp->prev;
		tmp->prev = NULL;
		a->last->next = NULL;
		a->stack->prev = tmp;
		tmp->next = a->stack;
		a->stack = tmp;
	}
	return (1);
}

int	execute_instruction(t_all *a, t_all *b, char *ins, int show)
{
	int	i;

	i = 0;
	if (!ft_strncmp(ins, "sa", 10) || !ft_strncmp(ins, "ss", 10))
		i = swap(a);
	if (!ft_strncmp(ins, "sb", 10) || !ft_strncmp(ins, "ss", 10))
		i = swap(b);
	if (!ft_strncmp(ins, "pa", 10))
		i = push(a, b);
	if (!ft_strncmp(ins, "pb", 10))
		i = push(b, a);
	if (!ft_strncmp(ins, "ra", 10) || !ft_strncmp(ins, "rr", 10))
		i = rotate(a);
	if (!ft_strncmp(ins, "rb", 10) || !ft_strncmp(ins, "rr", 10))
		i = rotate(b);
	if (!ft_strncmp(ins, "rra", 10) || !ft_strncmp(ins, "rrr", 10))
		i = reverse_rotate(a);
	if (!ft_strncmp(ins, "rrb", 10) || !ft_strncmp(ins, "rrr", 10))
		i = reverse_rotate(b);
	if (show && i)
	{
		ft_putstr_fd(ins, 1);
		write(1, "\n", 1);
	}	
	return (i);
}
