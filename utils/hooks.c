/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpinho-c <cpinho-c@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-06-01 14:32:25 by cpinho-c          #+#    #+#             */
/*   Updated: 2025-06-01 14:32:25 by cpinho-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../so_long.h"

int	hook_handler(int keycode, t_game *game)
{
	if (keycode == 65307)
		free_all(game, 0);
	if (keycode == 97 || keycode == 65361)
		move_left(game);
	if (keycode == 119 || keycode == 65362)
		move_up(game);
	if (keycode == 100 || keycode == 65363)
		move_right(game);
	if (keycode == 115 || keycode == 65364)
		move_down(game);
	return (0);
}

void	move_left(t_game *g)
{
	if (g->map->map[g->player->x][g->player->y - 1] != '1')
	{
		g->move_count++;
		ft_printf(1,"move counter:%i\n", g->move_count);
		if (g->map->map[g->player->x][g->player->y] == 'X')
			g->map->map[g->player->x][g->player->y] = 'E';
		else
			g->map->map[g->player->x][g->player->y] = '0';
		if (g->map->map[g->player->x][g->player->y - 1] == 'C')
		{
			g->map->map[g->player->x][g->player->y - 1] = 'P';
			g->found_items++;
		}
		else if (g->map->map[g->player->x][g->player->y - 1] == 'E'
			&& g->found_items != g->total_items)
			g->map->map[g->player->x][g->player->y - 1] = 'X';
		else if (g->map->map[g->player->x][g->player->y - 1] == 'E'
			&& g->found_items == g->total_items)
			finish_game(g);
		else
			g->map->map[g->player->x][g->player->y - 1] = 'P';
		g->player->y -= 1;
		render_map(g, 'A');
	}
}

void	move_up(t_game *g)
{
	if (g->map->map[g->player->x - 1][g->player->y] != '1')
	{
		g->move_count++;
		ft_printf(1,"move counter:%i\n", g->move_count);
		if (g->map->map[g->player->x][g->player->y] == 'X')
			g->map->map[g->player->x][g->player->y] = 'E';
		else
			g->map->map[g->player->x][g->player->y] = '0';
		if (g->map->map[g->player->x - 1][g->player->y] == 'C')
		{
			g->map->map[g->player->x - 1][g->player->y] = 'P';
			g->found_items++;
		}
		else if (g->map->map[g->player->x - 1][g->player->y] == 'E'
			&& g->found_items != g->total_items)
			g->map->map[g->player->x - 1][g->player->y] = 'X';
		else if (g->map->map[g->player->x - 1][g->player->y] == 'E'
			&& g->found_items == g->total_items)
			finish_game(g);
		else
			g->map->map[g->player->x - 1][g->player->y] = 'P';
		g->player->x -= 1;
		render_map(g, 'W');
	}
}

void	move_right(t_game *g)
{
	if (g->map->map[g->player->x][g->player->y + 1] != '1')
	{
		g->move_count++;
		ft_printf(1,"move counter:%i\n", g->move_count);
		if (g->map->map[g->player->x][g->player->y] == 'X')
			g->map->map[g->player->x][g->player->y] = 'E';
		else
			g->map->map[g->player->x][g->player->y] = '0';
		if (g->map->map[g->player->x][g->player->y + 1] == 'C')
		{
			g->map->map[g->player->x][g->player->y + 1] = 'P';
			g->found_items++;
		}
		else if (g->map->map[g->player->x][g->player->y + 1] == 'E'
			&& g->found_items != g->total_items)
			g->map->map[g->player->x][g->player->y + 1] = 'X';
		else if (g->map->map[g->player->x][g->player->y + 1] == 'E'
			&& g->found_items == g->total_items)
			finish_game(g);
		else
			g->map->map[g->player->x][g->player->y + 1] = 'P';
		g->player->y += 1;
		render_map(g, 'D');
	}
}

void	move_down(t_game *g)
{
	if (g->map->map[g->player->x + 1][g->player->y] != '1')
	{
		g->move_count++;
		ft_printf(1,"move counter:%i\n", g->move_count);
		if (g->map->map[g->player->x][g->player->y] == 'X')
			g->map->map[g->player->x][g->player->y] = 'E';
		else
			g->map->map[g->player->x][g->player->y] = '0';
		if (g->map->map[g->player->x + 1][g->player->y] == 'C')
		{
			g->map->map[g->player->x + 1][g->player->y] = 'P';
			g->found_items++;
		}
		else if (g->map->map[g->player->x + 1][g->player->y] == 'E'
			&& g->found_items != g->total_items)
			g->map->map[g->player->x + 1][g->player->y] = 'X';
		else if (g->map->map[g->player->x + 1][g->player->y] == 'E'
			&& g->found_items == g->total_items)
			finish_game(g);
		else
			g->map->map[g->player->x + 1][g->player->y] = 'P';
		g->player->x += 1;
		render_map(g, 'S');
	}
}
