/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_ff_check.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpinho-c <cpinho-c@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-05-29 15:53:44 by cpinho-c          #+#    #+#             */
/*   Updated: 2025-05-29 15:53:44 by cpinho-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../so_long.h"

void	flood_fill(t_game *game, int x, int y)
{
	if (x < 0 || x >= game->map->max_row || y < 0 || y >= game->map->max_col)
		return ;
	if (game->map->cpy_map[x][y] == '1' || game->map->cpy_map[x][y] == 'F')
		return ;
	else
		game->map->cpy_map[x][y] = 'F';
	flood_fill(game, x - 1, y);
	flood_fill(game, x + 1, y);
	flood_fill(game, x, y - 1);
	flood_fill(game, x, y + 1);
}

bool	map_impossible(t_game *game)
{
	int	i;

	flood_fill(game, game->player->x, game->player->y);
	i = 0;
	while (game->map->cpy_map[i])
	{
		if ((ft_strchr(game->map->cpy_map[i], 'C'))
			|| (ft_strchr(game->map->cpy_map[i], 'P'))
			|| (ft_strchr(game->map->cpy_map[i], 'E')))
			return (false);
		i++;
	}
	return (true);
}

void	fix_map(t_game *game)
{
	int		i;
	char	*temp;
	int		s_len;

	i = 0;
	while (game->map->map[i])
	{
		s_len = ft_strlen(game->map->map[i]);
		if (game->map->map[i][s_len - 1] == '\n')
		{
			temp = game->map->map[i];
			game->map->map[i] = ft_substr(temp, 0, s_len - 1);
			free(temp);
		}
		game->map->cpy_map[i] = ft_strdup(game->map->map[i]);
		i++;
	}
	game->map->cpy_map[i] = NULL;
	game->map->max_row = i;
	game->map->max_col = s_len;
}
