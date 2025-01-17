/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: quenalla <quenalla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 12:26:58 by qacjl             #+#    #+#             */
/*   Updated: 2025/01/17 11:36:16 by quenalla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_collectables(t_game *game)
{
	int	y;
	int	x;

	y = 0;
	game->collectable = 0;
	while (y < game->map.height)
	{
		x = 0;
		while (x < game->map.width)
		{
			if (game->map.data[y][x] == 'C')
				game->collectable++;
			x++;
		}
		y++;
	}
	ft_printf("Total collectables: %d\n", game->collectable);
}

int	close_game(t_game *game)
{
	int	i;

	i = 0;
	if (game->map.data)
	{
		while (i < game->map.height)
		{
			free(game->map.data[i]);
			i++;
		}
		free(game->map.data);
	}
	if (game->mlx)
	{
		if (game->floor_img)
			mlx_destroy_image(game->mlx, game->floor_img);
		if (game->wall_img)
			mlx_destroy_image(game->mlx, game->wall_img);
		if (game->player_down)
			mlx_destroy_image(game->mlx, game->player_down);
		if (game->player_up)
			mlx_destroy_image(game->mlx, game->player_up);
		if (game->player_left)
			mlx_destroy_image(game->mlx, game->player_left);
		if (game->player_right)
			mlx_destroy_image(game->mlx, game->player_right);
		if (game->collect_img)
			mlx_destroy_image(game->mlx, game->collect_img);
		if (game->exit_img)
			mlx_destroy_image(game->mlx, game->exit_img);
	}
	if (game->mlx && game->window)
	{
		mlx_destroy_window(game->mlx, game->window);
		mlx_destroy_display(game->mlx);
	}
	free(game->mlx);
	exit(0);
	return (0);
}

int	main(int ac, char **av)
{
	t_game	game;

	if (ac != 2)
		return (write(2, "ERROR, ARGUMENT INCORRECT\n", 26), 1);
	if (!validate_filename(av[1]))
		return (write(2, "ERROR, INCORRECT FILE\n", 22), 1);
	if (!read_map(av[1], &game.map))
		return (write(2, "ERROR, CANNOT READ MAP\n", 13), 1);
	if (!validate_map(&game.map))
		return (write(2, "ERROR, INVALID MAP\n", 19), 1);
	find_player_position(&game.map, &game.player_x, &game.player_y);
	init_collectables(&game);
	game.mlx = mlx_init();
	if (!game.mlx)
		return (write(2, "ERROR, MLX INIT FAILED\n", 23), 1);
	if (game.map.width * TILE_SIZE > MAX_MAP_WIDTH
		|| game.map.height * TILE_SIZE > MAX_MAP_HEIGHT)
		return (write(2, "ERROR, Window size exceeds screen\n", 34), 
			free_map(&game.map), 1);
	game.window = mlx_new_window(game.mlx, game.map.width * TILE_SIZE,
			game.map.height * TILE_SIZE, WINDOW_TITLE);
	if (!game.window)
		close_game(&game);
	game.steps = 0;
	load_sprites(&game);
	render_map(&game);
	mlx_key_hook(game.window, handle_input, &game);
	mlx_hook(game.window, 17, 0, close_game, &game);
	mlx_loop(game.mlx);
	return (0);
}
