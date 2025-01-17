/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: quenalla <quenalla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 14:39:24 by qacjl             #+#    #+#             */
/*   Updated: 2025/01/17 15:03:39 by quenalla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*parse_args(char **argv)
{
	t_list	*stack_a;
	char	**temp;
	int		index;
	int		number;

	stack_a = NULL;
	temp = split_string(argv[1], ' ');
	index = 0;
	while (temp[index])
	{
		number = parse_number_split(temp[index], temp, &stack_a);
		add_to_list(&stack_a, create_node(number));
		index++;
	}
	free_split(temp);
	return (stack_a);
}

t_list	*check_args(int argc, char **argv)
{
	t_list	*stack_a;
	int		index;
	int		number;

	stack_a = NULL;
	index = 1;
	if (argc == 1)
		exit(0);
	if (argc < 2)
		print_error();
	if (argc == 2)
		stack_a = parse_args(argv);
	else
	{
		while (index < argc)
		{
			number = parse_number(argv[index], &stack_a);
			add_to_list(&stack_a, create_node(number));
			index++;
		}
	}
	return (stack_a);
}

int	parse_number_split(const char *str, char **split, t_list **stack)
{
	int		sign;
	long	result;

	sign = 1;
	result = 0;
	while (*str == ' ' || (*str >= '\t' && *str <= '\r'))
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	while (*str)
	{
		if (*str < '0' || *str > '9')
			free_all(split, stack);
		result = result * 10 + (*str - '0');
		if ((sign * result) > 2147483647 || (sign * result) < -2147483648)
			free_all(split, stack);
		str++;
	}
	return ((int)(sign * result));
}

int	parse_number(const char *str, t_list **stack)
{
	int		sign;
	long	result;

	sign = 1;
	result = 0;
	while (*str == ' ' || (*str >= '\t' && *str <= '\r'))
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	while (*str)
	{
		if (*str < '0' || *str > '9')
			free_list(stack);
		result = result * 10 + (*str - '0');
		if ((sign * result) > 2147483647 || (sign * result) < -2147483648)
			free_list(stack);
		str++;
	}
	return ((int)(sign * result));
}
