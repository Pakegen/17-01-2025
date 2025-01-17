/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qacjl <qacjl@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 17:56:47 by quenalla          #+#    #+#             */
/*   Updated: 2025/01/16 22:47:36 by qacjl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t		i;
	char		*d1;
	char		*s1;

	i = 0;
	d1 = (char *)dest;
	s1 = (char *)src;
	if (dest == NULL && src == NULL)
		return (dest);
	while (n > i)
	{
		d1[i] = s1[i];
		i++;
	}
	return (dest);
}
