/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_u.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qacjl <qacjl@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 15:10:03 by quenalla          #+#    #+#             */
/*   Updated: 2025/01/16 22:48:09 by qacjl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_print_u(unsigned int n)
{
	char	nbr;
	int		contador;

	contador = 0;
	if (n == 0)
		return (ft_printchar('0'));
	if (n > 9)
		contador += ft_print_u(n / 10);
	nbr = (n % 10) + '0';
	contador += ft_printchar(nbr);
	return (contador);
}
