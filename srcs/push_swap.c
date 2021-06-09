/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnabil <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/07 11:08:55 by hnabil            #+#    #+#             */
/*   Updated: 2021/06/07 11:14:43 by hnabil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_all	a;
	t_all	b;
	int		i;

	i = -1;
	argv = get_arg(argc, argv);
	while (argv[++i])
		;
	argc = i;
	if (argc > 1)
	{
		if (!read_arg(argc, argv, &a))
			ft_exit(&argv, 0);
		ft_sort(&a, &b, argc - 1);
	}
	free_stack(&a);
	free_array(argv);
	free(argv);
	return (0);
}
