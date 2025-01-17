/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_utils_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qacjl <qacjl@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 14:50:04 by qacjl             #+#    #+#             */
/*   Updated: 2025/01/16 14:59:19 by qacjl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*ft_lstlast(t_list *stack)
{
	t_list	*current;

	current = stack;
	if (!current)
		return (NULL);
	while (current->next)
		current = current->next;
	return (current);
}

int	check_duplicates(t_list *stack)
{
	t_list	*current;
	t_list	*compare;

	current = stack;
	while (current)
	{
		compare = current->next;
		while (compare)
		{
			if (current->num == compare->num)
				return (1);
			compare = compare->next;
		}
		current = current->next;
	}
	return (0);
}

int	is_sorted(t_list *stack)
{
	while (stack && stack->next)
	{
		if (stack->num > stack->next->num)
			return (0);
		stack = stack->next;
	}
	return (1);
}
