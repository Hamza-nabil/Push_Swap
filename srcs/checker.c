/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnabil <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/08 12:34:16 by hnabil            #+#    #+#             */
/*   Updated: 2021/06/08 12:46:04 by hnabil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_all	a;
	t_all	b;
	char	*inst;
	int		i;

	i = -1;
	argv = get_arg(argc, argv);
	while (argv[++i])
		;
	argc = i;
	i = 1;
	if (argc > 1)
	{
		i = read_arg(argc, argv, &a);
		while (i && get_next_line(0, &inst))
		{
			i = execute_instruction(&a, &b, inst, 0);
			free(inst);
		}
		if (i && !is_sorted(a.stack, b.stack))
			i = -1;
		ft_exit(&argv, i);
	}
	return (0);
}
