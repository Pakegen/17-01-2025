/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_d.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qacjl <qacjl@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 12:54:24 by quenalla          #+#    #+#             */
/*   Updated: 2025/01/16 22:47:51 by qacjl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_strcount(int n)
{
	int	len;

	len = 0;
	if (n < 0)
	{
		len++;
		n = -n;
	}
	while (n != 0)
	{
		len++;
		n = n / 10;
	}
	return (len);
}

int	ft_print_d(int n)
{
	long long int	nb;
	long long int	compteur;
	int				len;

	nb = n;
	len = ft_strcount(nb);
	compteur = 1;
	if (nb == 0)
		return (ft_printchar('0'));
	if (nb < 0)
	{
		ft_printchar('-');
		nb = -nb;
	}
	while (compteur <= nb)
		compteur = compteur * 10;
	while (compteur != 1)
	{
		compteur = compteur / 10;
		ft_printchar(nb / compteur + '0');
		nb = nb % compteur;
	}
	return (len);
}
