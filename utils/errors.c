/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpinho-c <cpinho-c@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-05-18 18:21:01 by cpinho-c          #+#    #+#             */
/*   Updated: 2025-05-18 18:21:01 by cpinho-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	call_error(char *str, t_game *game)
{
	ft_printf(1,"%s", str);
	free_all(game, 1);
}

void	free_map(t_game *game)
{
	int	i;

	i = 0;
	while (game->map->map[i])
	{
		free(game->map->map[i]);
		free(game->map->cpy_map[i]);
		i++;
	}
	i = 0;
	free(game->map->map);
	free(game->map->cpy_map);
	free(game->map);
}

void	free_imgs(t_game *game)
{
	if (game->imgs->bg)
		mlx_destroy_image(game->mlx, game->imgs->bg);
	if (game->imgs->item)
		mlx_destroy_image(game->mlx, game->imgs->item);
	if (game->imgs->exitc)
		mlx_destroy_image(game->mlx, game->imgs->exitc);
	if (game->imgs->exito)
		mlx_destroy_image(game->mlx, game->imgs->exito);
	if (game->imgs->p_s)
		mlx_destroy_image(game->mlx, game->imgs->p_s);
	if (game->imgs->p_a)
		mlx_destroy_image(game->mlx, game->imgs->p_a);
	if (game->imgs->p_d)
		mlx_destroy_image(game->mlx, game->imgs->p_d);
	if (game->imgs->p_w)
		mlx_destroy_image(game->mlx, game->imgs->p_w);
	if (game->imgs->wall)
		mlx_destroy_image(game->mlx, game->imgs->wall);
	if (game->imgs->pone)
		mlx_destroy_image(game->mlx, game->imgs->pone);
}

void	free_all(t_game *game, int status)
{
	if (game->map)
		free_map(game);
	if (game->player)
		free(game->player);
	if (game->imgs)
	{
		free_imgs(game);
		free(game->imgs);
		game->imgs = NULL;
	}
	if (game->win)
	{
		mlx_destroy_window(game->mlx, game->win);
		game->win = NULL;
	}
	if (game->mlx)
	{
		mlx_destroy_display(game->mlx);
		free(game->mlx);
		game->mlx = NULL;
	}
	if (game)
		free(game);
	exit(status);
}
