/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnabil <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/07 17:07:37 by hnabil            #+#    #+#             */
/*   Updated: 2021/06/08 12:47:08 by hnabil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/includes/libft.h"
# include <unistd.h>
# include <stdio.h>

typedef struct s_stack
{
	int				data;
	struct s_stack	*next;
	struct s_stack	*prev;
}					t_stack;

typedef struct s_all
{
	t_stack			*stack;
	t_stack			*last;
}					t_all;

int		execute_instruction(t_all *a, t_all *b, char *ins, int show);
void	sort_b(t_all *a, t_all *b, int start, int end);
void	sort_a(t_all *a, t_all *b, int start, int end);
int		read_arg(int ac, char **av, t_all *a);
void	heap_sort(int *arr, int n);
int		is_sorted(t_stack *a, t_stack *b);
int		get_next_line(int fd, char **line);
void	ft_sort(t_all *a, t_all *b, int len);
char	**get_arg(int argc, char **argv);
void	sort_a(t_all *a, t_all *b, int start, int end);
void	free_stack(t_all *a);
void	ft_stackadd(t_all *all, t_stack *new);
t_stack	*ft_stacknew(int data);
void	sort_b(t_all *a, t_all *b, int start, int end);
void	ft_exit(char ***argv, int s);
void	free_array(char **tab);

#endif
