/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: quenalla <quenalla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 09:55:49 by quenalla          #+#    #+#             */
/*   Updated: 2025/01/15 09:56:56 by quenalla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_map(t_map *map)
{
	int	i;

	i = 0;
	if (!map->data)
		return ;
	while (i < map->height)
	{
		free(map->data[i]);
		i++;
	}
	free(map->data);
	map->data = NULL;
}