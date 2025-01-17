/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qacjl <qacjl@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 08:12:50 by quenalla          #+#    #+#             */
/*   Updated: 2025/01/16 22:49:30 by qacjl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	c;
	char	*str;
	size_t	k;

	i = 0;
	str = (char *)big;
	k = ft_strlen(little);
	if (k == 0 || big == little)
		return (str);
	while (str[i] != '\0' && i < len)
	{
		c = 0;
		while (str[i + c] && little[c]
			&& str[i + c] == little[c] && (i + c) < len)
			c++;
		if (c == k)
			return (str + i);
		i++;
	}
	return (NULL);
}
