/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inits.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpinho-c <cpinho-c@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-05-28 16:52:02 by cpinho-c          #+#    #+#             */
/*   Updated: 2025-05-28 16:52:02 by cpinho-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	init_player(t_game *game)
{
	t_player	*player;

	player = malloc(sizeof(t_player));
	if (!player)
		call_error(ERR0R_MALLOC, game);
	game->player = player;
}

t_game	*init_game(void)
{
	t_game	*game;

	game = malloc(sizeof(t_game));
	if (!game)
	{
		ft_printf(1,"%s", ERROR_STRUCT);
		exit(1);
	}
	game->mlx = NULL;
	game->win = NULL;
	game->map = NULL;
	game->player = NULL;
	game->found_items = 0;
	game->total_items = 0;
	game->imgs = NULL;
	game->move_count = 0;
	game->cx = 0;
	game->cy = 0;
	game->maxh = 0;
	game->maxw = 0;
	return (game);
}

void	init_imgs(t_game *g)
{
	t_imgs	*i;

	i = malloc(sizeof(t_imgs));
	if (!i)
		call_error(ERR0R_MALLOC, g);
	i->h = g->map->max_row * 32;
	i->w = g->map->max_col * 32;
	i->bg = mlx_xpm_file_to_image(g->mlx, "textures/bg.xpm", &i->w, &i->h);
	i->wall = mlx_xpm_file_to_image(g->mlx, "textures/wall.xpm", &i->w, &i->h);
	i->p_s = mlx_xpm_file_to_image(g->mlx, "textures/p_S.xpm", &i->w, &i->h);
	i->p_a = mlx_xpm_file_to_image(g->mlx, "textures/p_A.xpm", &i->w, &i->h);
	i->p_d = mlx_xpm_file_to_image(g->mlx, "textures/p_D.xpm", &i->w, &i->h);
	i->p_w = mlx_xpm_file_to_image(g->mlx, "textures/p_W.xpm", &i->w, &i->h);
	i->item = mlx_xpm_file_to_image(g->mlx, "textures/item.xpm", &i->w, &i->h);
	i->exitc = mlx_xpm_file_to_image(g->mlx, "textures/eC.xpm", &i->w, &i->h);
	i->exito = mlx_xpm_file_to_image(g->mlx, "textures/eO.xpm", &i->w, &i->h);
	i->pone = mlx_xpm_file_to_image(g->mlx, "textures/PonE.xpm", &i->w, &i->h);
	g->imgs = i;
	if (!(i->bg) || !(i->item) || !(i->exitc) || !(i->exito)
		|| !(i->p_s) || !(i->p_a) || !(i->p_d) || !(i->p_w)
		|| !(i->wall) || !(i->pone))
		call_error(ERROR_IMG_LOAD, g);
}

void	get_cam_pos(t_game *game)
{
	if ((game->map->max_col * 32) < game->maxw
		&& (game->map->max_row * 32) < game->maxh)
	{
		game->cx = 0;
		game->cy = 0;
		return ;
	}
	game->cy = (game->player->x * 32) - (game->maxh / 2);
	game->cx = (game->player->y * 32) - (game->maxw / 2);
	if (game->cx < 0)
		game->cx = 0;
	else if (game->cx > (game->map->max_col * 32) - game->maxw)
		game->cx = (game->map->max_col * 32) - game->maxw;
	if (game->cy < 0)
		game->cy = 0;
	else if (game->cy > (game->map->max_row * 32) - game->maxh)
		game->cy = (game->map->max_row * 32) - game->maxh;
}

void	init_mlx(t_game *game)
{
	game->mlx = mlx_init();
	if (!game->mlx)
		call_error(ERROR_MLX, game);
	init_imgs(game);
	mlx_get_screen_size(game->mlx, &game->maxw, &game->maxh);
	game->maxh -= 64;
	if ((game->map->max_col * 32) > game->maxw
		&& (game->map->max_row * 32) > game->maxh)
		game->win = mlx_new_window(game->mlx, game->maxw,
				game->maxh, "So_long");
	else if ((game->map->max_col * 32) > game->maxw
		&& (game->map->max_row * 32) <= game->maxh)
		game->win = mlx_new_window(game->mlx, game->maxw,
				game->map->max_row * 32, "So_long");
	else if ((game->map->max_col * 32) <= game->maxw
		&& (game->map->max_row * 32) > game->maxh)
		game->win = mlx_new_window(game->mlx, game->map->max_col * 32,
				game->maxh, "So_long");
	else
		game->win = mlx_new_window(game->mlx, game->map->max_col * 32,
				game->map->max_row * 32, "So_long");
	if (!game->win)
		call_error(ERROR_MLX, game);
	render_map(game, 'D');
}
