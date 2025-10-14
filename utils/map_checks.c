/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checks.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpinho-c <cpinho-c@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-05-18 20:44:01 by cpinho-c          #+#    #+#             */
/*   Updated: 2025-05-18 20:44:01 by cpinho-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

bool	wall_check(char **map)
{
	int	i;
	int	j;
	int	last_line;

	i = -1;
	last_line = 0;
	while (map[++i])
		last_line++;
	i = -1;
	while (map[++i])
	{
		if (i == 0 || i == (last_line - 1))
		{
			j = 0;
			while (map[i][j])
			{
				if (map[i][j] != '1')
					return (false);
				j++;
			}
		}
		if (map[i][0] != '1' || map[i][ft_strlen(map[i]) - 1] != '1')
			return (false);
	}
	return (true);
}

bool	player_check(t_game *game)
{
	int	i;
	int	j;
	int	player;

	i = 0;
	player = 0;
	init_player(game);
	while (game->map->map[i])
	{
		j = 0;
		while (game->map->map[i][j])
		{
			if (game->map->map[i][j] == 'P')
			{
				player++;
				game->player->x = i;
				game->player->y = j;
			}
			j++;
		}
		i++;
	}
	if (player != 1)
		return (false);
	return (true);
}

bool	exit_check(char **map)
{
	int	i;
	int	j;
	int	exits;

	i = 0;
	exits = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'E')
				exits++;
			j++;
		}
		i++;
	}
	if (exits != 1)
		return (false);
	return (true);
}

bool	items_check(t_game *game)
{
	int	i;
	int	j;
	int	items;

	i = 0;
	items = 0;
	while (game->map->map[i])
	{
		j = 0;
		while (game->map->map[i][j])
		{
			if (game->map->map[i][j] == 'C')
				items++;
			j++;
		}
		i++;
	}
	if (items < 1)
		return (false);
	game->total_items = items;
	return (true);
}

bool	map_is_ret_check(char **map)
{
	int	i;

	i = 0;
	while (map[i] && map[i + 1])
	{
		if (ft_strlen(map[i]) != ft_strlen(map[i + 1]))
			return (false);
		i++;
	}
	return (true);
}
