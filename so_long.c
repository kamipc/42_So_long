/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpinho-c <cpinho-c@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-05-18 13:55:48 by cpinho-c          #+#    #+#             */
/*   Updated: 2025-05-18 13:55:48 by cpinho-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	finish_game(t_game *game)
{
	ft_printf(1,"%s", GAME_WON);
	free_all(game, 0);
}

int	close_game(t_game *game)
{
	free_all(game, 0);
	return (0);
}

int	main(int ac, char **av)
{
	t_game	*game;

	if (ac != 2)
	{
		ft_printf("%s", ERROR_INV_ARGS);
		exit(1);
	}
	validade_map_file(av[1]);
	game = init_game();
	read_map(av[1], game);
	check_valid_map(game);
	init_mlx(game);
	ft_printf(1,"move counter:%i\n", game->move_count);
	mlx_hook(game->win, 2, 1L << 0, hook_handler, game);
	mlx_hook(game->win, 17, 0, close_game, game);
	mlx_loop(game->mlx);
	free_all(game, 0);
	return (0);
}
