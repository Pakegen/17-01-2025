/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qacjl <qacjl@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 10:52:48 by quenalla          #+#    #+#             */
/*   Updated: 2025/01/16 22:48:32 by qacjl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	long int	nb;
	long int	compteur;

	nb = n;
	compteur = 1;
	if (nb == -2147483648)
		ft_putstr_fd("-2147483648", fd);
	if (nb == 0)
	{
		return (ft_putchar_fd('0', fd));
	}
	if (nb < 0 && nb != -2147483648)
	{
		ft_putchar_fd('-', fd);
		nb = -nb;
	}
	while (compteur <= nb)
		compteur = compteur * 10;
	while (compteur > 1)
	{
		compteur = compteur / 10;
		ft_putchar_fd(nb / compteur + '0', fd);
		nb = nb % compteur;
	}
}
