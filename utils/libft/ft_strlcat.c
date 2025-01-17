/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qacjl <qacjl@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 11:35:39 by quenalla          #+#    #+#             */
/*   Updated: 2025/01/16 22:49:06 by qacjl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	unsigned int	destlen;
	unsigned int	srclen;
	unsigned int	k;

	destlen = 0;
	srclen = 0;
	k = 0;
	while (dest[destlen] != '\0')
		destlen++;
	while (src[srclen])
		srclen++;
	if (destlen >= size)
		return (srclen + size);
	else
		srclen = srclen + destlen;
	while (src[k] != '\0' && (k + destlen + 1) < size)
	{
		dest[destlen + k] = src[k];
		k++;
	}
	dest[destlen + k] = '\0';
	return (srclen);
}
