/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalquraa <aalquraa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 17:02:39 by aalquraa          #+#    #+#             */
/*   Updated: 2025/02/04 19:23:01 by aalquraa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <mlx.h>
# include "libft/libft.h"
# include <stdlib.h>
# include <unistd.h>
# include <string.h>
# include <fcntl.h>
# include <X11/X.h>
# include <X11/keysym.h>
# include <stdio.h>

typedef struct s_game
{
	void	*mlx;
	void	*win;
	char	**map;

	void	*player;
	void	*wall;
	void	*exit;
	void	*collectible;
	void	*ground;
	int		player_x;
	int		player_y;
	int		exit_x;
	int		exit_y;
	int		collected_items;
	int		total_collectibles;
	int		map_width;
	int		map_height;
	int		moves;	
	int		img_width;
	int		img_height;
	int		**visited;

}	t_game;

int		row(t_game *game);
int		columns(t_game *game);
void	init(t_game *game);
void	check_errormap(char **map);
void	load_images(t_game *game);
void	display_map(t_game *game);
void	find_player_pos(t_game *game);
int		key_handler(int keycode, t_game *game);
int		count_collectible(char **map);
void	moveup(t_game *game);
void	movedown(t_game *game);
void	moveleft(t_game *game);
void	moveright(t_game *game);
int		close_handler(t_game *game);
int		checkfile(int argc, char **argv);
void	clean_game(t_game *game);
void	find_exit_pos(t_game *game);
void	movepart(t_game *game);

#endif
