/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpinho-c <cpinho-c@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-05-18 16:59:26 by cpinho-c          #+#    #+#             */
/*   Updated: 2025-05-18 16:59:26 by cpinho-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

bool	invalid_char(char	**m)
{
	int	i;
	int	j;

	i = 0;
	while (m[i])
	{
		j = 0;
		while (m[i][j])
		{
			if (m[i][j] != '1' && m[i][j] != 'C' && m[i][j] != 'P'
				&& m[i][j] != 'E' && m[i][j] != '0')
				return (false);
			j++;
		}
		i++;
	}
	return (true);
}

void	check_valid_map(t_game *game)
{
	if (wall_check(game->map->map) == false)
		call_error(ERROR_INV_WALL, game);
	if (exit_check(game->map->map) == false)
		call_error(ERROR_INV_EXIT, game);
	if (player_check(game) == false)
		call_error(ERROR_INV_P, game);
	if (items_check(game) == false)
		call_error(ERROR_INV_COL, game);
	if (map_is_ret_check(game->map->map) == false)
		call_error(ERROR_INV_DIM, game);
	if (map_impossible(game) == false)
		call_error(ERROR_IMPOSS, game);
	if (invalid_char(game->map->map) == false)
		call_error(ERROR_INV_CHAR, game);
}

void	save_map(char *map_loc, t_game *game)
{
	int	map_fd;
	int	i;

	map_fd = open(map_loc, O_RDONLY);
	if (map_fd == -1)
		call_error(ERROR_OPEN_MAP, game);
	i = 0;
	game->map->map[i] = get_next_line(map_fd);
	while (game->map->map[i] != NULL)
	{
		i++;
		game->map->map[i] = get_next_line(map_fd);
	}
	game->map->map[i] = NULL;
	if (!game->map->map[0])
		call_error(ERROR_MAP_EMPTY, game);
}

void	validade_map_file(char	*map_loc)
{
	int	len;
	int	i;

	len = ft_strlen(map_loc);
	i = 0;
	while (map_loc[i] != '/' && map_loc[i])
		i++;
	if (len - (i + 1) < 5)
	{
		ft_printf(1,"%s", ERROR_INV_MAP_EXT);
		exit(1);
	}
	if (map_loc[len - 1] != 'r' || map_loc[len - 2] != 'e'
		|| map_loc[len - 3] != 'b' || map_loc[len - 4] != '.')
	{
		ft_printf(1,"%s", ERROR_INV_MAP_EXT);
		exit(1);
	}
}

void	read_map(char *map_loc, t_game *game)
{
	int		map_fd;
	char	*line;
	int		i;

	i = 0;
	map_fd = open(map_loc, O_RDONLY);
	if (map_fd == -1)
		call_error(ERROR_OPEN_MAP, game);
	line = get_next_line(map_fd);
	while (line != NULL)
	{
		i++;
		free(line);
		line = get_next_line(map_fd);
	}
	close(map_fd);
	game->map = malloc(sizeof(t_map));
	if (!game->map)
		call_error(ERR0R_MALLOC, game);
	game->map->map = (char **)malloc((i + 1) * (sizeof(char *)));
	game->map->cpy_map = (char **)malloc((i + 1) * (sizeof(char *)));
	save_map(map_loc, game);
	fix_map(game);
}
