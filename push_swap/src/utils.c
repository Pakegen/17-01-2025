/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qacjl <qacjl@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 14:46:48 by qacjl             #+#    #+#             */
/*   Updated: 2025/01/16 14:56:41 by qacjl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	count_words(const char *str, char delimiter)
{
	int	count;

	count = 0;
	while (*str)
	{
		while (*str == delimiter)
			str++;
		if (*str)
			count++;
		while (*str && *str != delimiter)
			str++;
	}
	return (count);
}

char	*ft_strndup(const char *src, size_t n)
{
	char	*dup;
	size_t	len;
	size_t	i;

	len = 0;
	while (src[len] && len < n)
		len++;
	dup = malloc(len + 1);
	if (!dup)
		return (NULL);
	i = 0;
	while (i < len)
	{
		dup[i] = src[i];
		i++;
	}
	dup[i] = '\0';
	return (dup);
}

char	**split_string(const char *str, char delimiter)
{
	char	**result;
	int		word_count;
	int		i;
	int		len;

	if (!str)
		return (NULL);
	word_count = count_words(str, delimiter);
	result = malloc((word_count + 1) * sizeof(char *));
	if (!result)
		return (NULL);
	i = 0;
	while (*str)
	{
		while (*str == delimiter)
			str++;
		len = 0;
		while (str[len] && str[len] != delimiter)
			len++;
		if (len > 0)
			result[i++] = ft_strndup(str, len);
		str += len;
	}
	result[i] = NULL;
	return (result);
}
