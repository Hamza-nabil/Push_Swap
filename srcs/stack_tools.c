#include "push_swap.h"

void	free_stack(t_all *a)
{
	t_stack	*tmp;

	if (a)
	{
		tmp = a->stack;
		while (tmp)
		{
			free(tmp);
			tmp = tmp->next;
		}
	}
}

t_stack	*ft_stacknew(int data)
{
	t_stack	*new;

	new = malloc(sizeof(t_stack));
	if (!new)
		return (NULL);
	new->data = data;
	new->next = NULL;
	new->prev = NULL;
	return (new);
}

void	ft_stackadd(t_all *all, t_stack *new)
{
	if (all && new)
	{
		if (all->stack)
			all->stack->prev = new;
		else
			all->last = new;
		new->next = all->stack;
		all->stack = new;
	}
}

int	is_sorted(t_stack *a, t_stack *b)
{
	int	i;

	i = 0;
	if (b)
		return (0);
	while (a && ++i)
	{
		if (a->data != i)
			return (0);
		a = a->next;
	}
	return (1);
}
