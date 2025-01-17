/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_basic.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qacjl <qacjl@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 14:40:35 by qacjl             #+#    #+#             */
/*   Updated: 2025/01/16 14:40:39 by qacjl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_a(t_list **stack_a, int silent)
{
	t_list	*tmp;

	if (!*stack_a || !(*stack_a)->next)
		return ;
	tmp = *stack_a;
	*stack_a = (*stack_a)->next;
	tmp->next = (*stack_a)->next;
	(*stack_a)->next = tmp;
	if (!silent)
		write(1, "sa\n", 3);
}

void	swap_b(t_list **stack_b, int silent)
{
	t_list	*tmp;

	if (!*stack_b || !(*stack_b)->next)
		return ;
	tmp = *stack_b;
	*stack_b = (*stack_b)->next;
	tmp->next = (*stack_b)->next;
	(*stack_b)->next = tmp;
	if (!silent)
		write(1, "sb\n", 3);
}

void	swap_both(t_list **stack_a, t_list **stack_b, int silent)
{
	swap_a(stack_a, 1);
	swap_b(stack_b, 1);
	if (!silent)
		write(1, "ss\n", 3);
}

void	push_a(t_list **stack_a, t_list **stack_b, int silent)
{
	t_list	*tmp;

	if (!*stack_b)
		return ;
	tmp = *stack_a;
	*stack_a = *stack_b;
	*stack_b = (*stack_b)->next;
	(*stack_a)->next = tmp;
	if (!silent)
		write(1, "pa\n", 3);
}

void	push_b(t_list **stack_a, t_list **stack_b, int silent)
{
	t_list	*tmp;

	if (!*stack_a)
		return ;
	tmp = *stack_b;
	*stack_b = *stack_a;
	*stack_a = (*stack_a)->next;
	(*stack_b)->next = tmp;
	if (!silent)
		write(1, "pb\n", 3);
}
