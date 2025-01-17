/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_rotations.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qacjl <qacjl@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 14:40:57 by qacjl             #+#    #+#             */
/*   Updated: 2025/01/16 14:41:03 by qacjl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate_a(t_list **stack_a, int silent)
{
	t_list	*tmp;
	t_list	*last;

	if (!*stack_a || !(*stack_a)->next)
		return ;
	tmp = *stack_a;
	*stack_a = (*stack_a)->next;
	tmp->next = NULL;
	last = ft_lstlast(*stack_a);
	last->next = tmp;
	if (!silent)
		write(1, "ra\n", 3);
}

void	reverse_rotate_a(t_list **stack_a, int silent)
{
	t_list	*tmp;
	t_list	*before_last;

	if (!*stack_a || !(*stack_a)->next)
		return ;
	before_last = *stack_a;
	while (before_last->next->next)
		before_last = before_last->next;
	tmp = before_last->next;
	before_last->next = NULL;
	tmp->next = *stack_a;
	*stack_a = tmp;
	if (!silent)
		write(1, "rra\n", 4);
}
