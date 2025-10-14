/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpinho-c <cpinho-c@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-05-18 13:55:36 by cpinho-c          #+#    #+#             */
/*   Updated: 2025-05-18 13:55:36 by cpinho-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include "libft/libft.h"
# include <stdbool.h>
# include <stdio.h>
# include <errno.h>
# include <fcntl.h>
# include "minilibx-linux/mlx.h"
# include "minilibx-linux/mlx_int.h"

# define ERROR_INV_ARGS "Error\nInvalid argument(s)\n"
# define ERR0R_MALLOC "Error\nFailed to allocate memory\n"
# define ERROR_INV_MAP_EXT "Error\nInvalid Map extension\n"
# define ERROR_STRUCT "Error\nFailed to create struct\n"
# define ERROR_OPEN_MAP "Error\nFailed to open map file\n"
# define ERROR_MAP_EMPTY "Error\nMap file is empty\n"
# define ERROR_INV_WALL "Error\nMap not surrounded by walls\n"
# define ERROR_INV_EXIT "Error\nInvalid number of Exits on map\n"
# define ERROR_INV_P "Error\nInvalid number of Players on map\n"
# define ERROR_INV_COL "Error\nThere are no collectibles on the map\n"
# define ERROR_INV_DIM "Error\nInvalid map dimensions\n"
# define ERROR_INV_CHAR "Error\nMap has invalid characters\n"
# define ERROR_IMPOSS "Error\nMap impossible to complete\n"
# define ERROR_IMG_LOAD "Error\nFailed to load images\n"
# define ERROR_MLX "Error\nFailed to initialize minilibX\n"
# define GAME_WON "Congratulations! You completed the game\n"

typedef struct s_player
{
	int	x;
	int	y;
}				t_player;

typedef struct s_map
{
	char	**map;
	char	**cpy_map;
	int		max_row;
	int		max_col;
}				t_map;

typedef struct s_imgs
{
	void	*bg;
	void	*wall;
	void	*p_a;
	void	*p_w;
	void	*p_d;
	void	*p_s;
	void	*exitc;
	void	*exito;
	void	*item;
	void	*pone;
	int		h;
	int		w;
}				t_imgs;

typedef struct s_game
{
	void		*mlx;
	void		*win;
	t_player	*player;
	int			total_items;
	int			found_items;
	t_map		*map;
	t_imgs		*imgs;
	int			move_count;
	int			cy;
	int			cx;
	int			maxw;
	int			maxh;
}				t_game;

//general
void	read_map(char *map_loc, t_game *game);
void	fix_map(t_game *game);
void	render_map(t_game *game, char c);
void	render_node(t_game *g, char c, int x, int y);
int		hook_handler(int keycode, t_game *game);
void	render_player(t_game *g, char c, int x, int y);
int		close_game(t_game *game);
void	get_cam_pos(t_game *game);
void	finish_game(t_game *game);

//movements
void	move_left(t_game *g);
void	move_up(t_game *g);
void	move_right(t_game *g);
void	move_down(t_game *g);

//inits
t_game	*init_game(void);
void	init_player(t_game *game);
void	init_mlx(t_game *game);
void	init_imgs(t_game *game);

// validade map
void	validade_map_file(char	*map_loc);
void	check_valid_map(t_game *game);
bool	wall_check(char **map);
bool	player_check(t_game *game);
bool	exit_check(char **map);
bool	items_check(t_game *game);
bool	map_is_ret_check(char **map);
bool	map_impossible(t_game *game);
void	flood_fill(t_game *game, int x, int y);

//handle errors and frees
void	call_error(char *str, t_game *game);
void	free_map(t_game *game);
void	free_all(t_game *game, int status);

#endif