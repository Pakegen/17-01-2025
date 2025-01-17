/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qacjl <qacjl@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 14:41:34 by qacjl             #+#    #+#             */
/*   Updated: 2025/01/16 14:41:38 by qacjl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_list	*stack_a;

	stack_a = check_args(argc, argv);
	if (!stack_a || check_duplicates(stack_a))
	{
		free_list(&stack_a);
		print_error();
	}
	if (!is_sorted(stack_a))
		sort_stack(&stack_a);
	free_list(&stack_a);
	return (0);
}
