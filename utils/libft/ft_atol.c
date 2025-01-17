/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: quenalla <quenalla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 07:53:14 by qacjl             #+#    #+#             */
/*   Updated: 2025/01/17 09:01:33 by quenalla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#include <limits.h>

static const char	*skip_whitespace(const char *str)
{
	while (*str == ' ' || (*str >= '\t' && *str <= '\r'))
		str++;
	return (str);
}

static int	get_sign(const char **str)
{
	int	sign;

	sign = 1;
	if (**str == '-' || **str == '+')
	{
		if (**str == '-')
			sign = -1;
		(*str)++;
	}
	return (sign);
}

static long	convert_digits(const char *str, int sign)
{
	long	result;

	result = 0;
	while (*str >= '0' && *str <= '9')
	{
		result = result * 10 + (*str - '0');
		if (result > LONG_MAX)
		{
			if (sign == 1)
				return (LONG_MAX);
			else
				return (LONG_MIN);
		}
		str++;
	}
	return (result * sign);
}

long	ft_atol(const char *str)
{
	int		sign;

	str = skip_whitespace(str);
	sign = get_sign(&str);
	return (convert_digits(str, sign));
}
