/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: quenalla <quenalla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 18:36:28 by qacjl             #+#    #+#             */
/*   Updated: 2025/01/17 11:40:27 by quenalla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	validate_horizontal_borders(t_map *map)
{
	int	x;

	x = 0;
	if (!map->data[0] || !map->data[map->height - 1])
	{
		free_map(map);
		return (write(2, "ERROR, INVALID HORIZONTAL BORDER\n", 33), 0);
	}
	while (x < map->width)
	{
		if (map->data[0][x] != '1' || map->data[map->height - 1][x] != '1')
		{
			return (write(2, "ERROR, HORIZONTAL BORDERS NOT CLOSED\n", 37), 0);
		}
		x++;
	}
	return (1);
}

static int	validate_vertical_borders(t_map *map)
{
	int	y;

	y = 0;
	while (y < map->height)
	{
		if (!map->data[y])
		{
			free_map(map);
			return (write(2, "ERROR, INVALID VERTICAL BORDERS\n", 32), 0);
		}
		if (map->data[y][0] != '1' || map->data[y][map->width - 1] != '1')
		{
			free_map(map);
			return (write(2, "ERROR, VERTICAL BORDERS ARE NOT CLOSED\n", 39), 0);
		}
		y++;
	}
	return (1);
}

int	validate_borders(t_map *map)
{
	if (!map || !map->data || map->width <= 0 || map->height <= 0)
		return (write(2, "ERROR, INVALID MAP DIMENSION\n", 29), 0);
	if (!validate_horizontal_borders(map))
		return (0);
	if (!validate_vertical_borders(map))
		return (0);
	return (1);
}

int	validate_map_dimensions(t_map *map)
{
	if (map->width > MAX_TILE_WIDTH || map->height > MAX_TILE_HEIGHT)
	{
		free_map(map);
		return (write(2, "ERROR, MAP DIMENSIONS TOO LARGE\n", 33), 0);
	}
	if (map->width * TILE_SIZE > MAX_MAP_WIDTH
		|| map->height * TILE_SIZE > MAX_MAP_HEIGHT)
	{
		free_map(map);
		return (write(2, "ERROR, MAP EXCEEDS SCREEN RESOLUTION\n", 38), 0);
	}
	return (1);
}