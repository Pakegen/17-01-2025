/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qacjl <qacjl@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 14:41:16 by qacjl             #+#    #+#             */
/*   Updated: 2025/01/16 14:53:30 by qacjl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_stack(t_list **stack_a)
{
	t_list	*stack_b;
	int		rot_count;

	stack_b = NULL;
	if (list_size(*stack_a) == 2)
		swap_a(stack_a, 0);
	else if (list_size(*stack_a) == 3)
		sort_three(stack_a);
	else
	{
		stack_b = move_to_stack_b(stack_a);
		stack_a = move_back_to_stack_a(stack_a, &stack_b);
		rot_count = find_index(*stack_a, find_min(*stack_a));
		while ((*stack_a)->num != find_min(*stack_a))
		{
			if (rot_count < list_size(*stack_a) / 2)
				rotate_a(stack_a, 0);
			else
				reverse_rotate_a(stack_a, 0);
		}
	}
}

void	sort_three(t_list **stack)
{
	int	first;
	int	second;
	int	third;

	if (!stack || list_size(*stack) != 3)
		return ;
	first = (*stack)->num;
	second = (*stack)->next->num;
	third = (*stack)->next->next->num;
	if (first > second && second < third && first < third)
		swap_a(stack, 0);
	else if (first > second && second > third)
	{
		swap_a(stack, 0);
		reverse_rotate_a(stack, 0);
	}
	else if (first > second && second < third)
		rotate_a(stack, 0);
	else if (first < second && second > third && first < third)
	{
		swap_a(stack, 0);
		rotate_a(stack, 0);
	}
	else if (first < second && second > third)
		reverse_rotate_a(stack, 0);
}

t_list	*move_to_stack_b(t_list **stack_a)
{
	t_list	*stack_b;

	stack_b = NULL;
	while (list_size(*stack_a) > 3)
		push_b(stack_a, &stack_b, 0);
	return (stack_b);
}

t_list	**move_back_to_stack_a(t_list **stack_a, t_list **stack_b)
{
	while (*stack_b)
		push_a(stack_a, stack_b, 0);
	return (stack_a);
}

int	find_index(t_list *stack, int value)
{
	int	index;

	index = 0;
	while (stack)
	{
		if (stack->num == value)
			return (index);
		stack = stack->next;
		index++;
	}
	return (-1);
}
