/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: quenalla <quenalla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 09:51:05 by quenalla          #+#    #+#             */
/*   Updated: 2025/01/17 12:42:07 by quenalla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	*safe_load_image(void *mlx, const char *path, int *width, int *height)
{
	void	*image;

	image = mlx_xpm_file_to_image(mlx, (char *)path, width, height);
	if (!image)
	{
		write(2, "ERROR: Failed to load image: ", 29);
		write(2, path, strlen(path));
		write(2, "\n", 1);
		return (NULL);
	}
	if (*width > TILE_SIZE || *height > TILE_SIZE)
	{
		write(2, "ERROR: Image dimensions too large: ", 36);
		write(2, path, strlen(path));
		write(2, "\n", 1);
		mlx_destroy_image(mlx, image);
		return (NULL);
	}
	return (image);
}

void	load_sprites(t_game *game)
{
	int sprite_width = 0;
	int sprite_height = 0;
	
	game->floor_img = safe_load_image(game->mlx, "texture/BACKGROUND.xpm", &sprite_width, &sprite_height);
	if (!game->floor_img)
		close_game(game);
	game->wall_img = safe_load_image(game->mlx, "texture/WALL.xpm", &sprite_width, &sprite_height);
	if (!game->wall_img)
		close_game(game);
	game->player_down = safe_load_image(game->mlx, "texture/slime_down.xpm", &sprite_width, &sprite_height);
	if (!game->player_down)
		close_game(game);
	game->player_up = safe_load_image(game->mlx, "texture/slime_up.xpm", &sprite_width, &sprite_height);
	if (!game->player_up)
		close_game(game);
	game->player_left = safe_load_image(game->mlx, "texture/slime_left.xpm", &sprite_width, &sprite_height);
	if (!game->player_left)
		close_game(game);
	game->player_right = safe_load_image(game->mlx, "texture/slime_right.xpm", &sprite_width, &sprite_height);
	if (!game->player_right)
		close_game(game);
	game->collect_img = safe_load_image(game->mlx, "texture/piece.xpm", &sprite_width, &sprite_height);
	if (!game->collect_img)
		close_game(game);
	game->exit_img = safe_load_image(game->mlx, "texture/exit.xpm", &sprite_width, &sprite_height);
	if (!game->exit_img)
		close_game(game);
	game->current_player_img = game->player_right;
}
