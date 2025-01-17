/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qacjl <qacjl@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 14:40:15 by qacjl             #+#    #+#             */
/*   Updated: 2025/01/16 14:50:42 by qacjl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*create_node(long number)
{
	t_list	*new_node;

	new_node = malloc(sizeof(t_list));
	if (!new_node)
		print_error();
	new_node->num = number;
	new_node->next = NULL;
	return (new_node);
}

void	add_to_list(t_list **stack, t_list *new_node)
{
	t_list	*last_node;

	if (!stack || !new_node)
		return ;
	if (!*stack)
		*stack = new_node;
	else
	{
		last_node = ft_lstlast(*stack);
		last_node->next = new_node;
	}
}

int	find_min(t_list *stack)
{
	int	min;

	min = stack->num;
	while (stack)
	{
		if (stack->num < min)
			min = stack->num;
		stack = stack->next;
	}
	return (min);
}

int	find_max(t_list *stack)
{
	int	max;

	max = stack->num;
	while (stack)
	{
		if (stack->num > max)
			max = stack->num;
		stack = stack->next;
	}
	return (max);
}

int	list_size(t_list *stack)
{
	int	size;

	size = 0;
	while (stack)
	{
		size++;
		stack = stack->next;
	}
	return (size);
}
