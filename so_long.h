/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalquraa <aalquraa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 17:02:39 by aalquraa          #+#    #+#             */
/*   Updated: 2025/02/02 02:07:44 by aalquraa         ###   ########.fr       */
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
# include <stdio.h>

#define key_w 13
#define key_s 1
#define key_a 0
#define key_d 2
#define key_esc 53



typedef struct s_game 
{
    void *mlx;      
    void *win;
    char **map;
    
    void    *player;
    void    *wall;
    void    *exit;
    void    *collectible;
    void    *ground;
    
    int     player_x;
    int     player_y;
    int collected_items;
    int total_collectibles;
    int map_width;
    int map_height;
    
    int	img_width;
	int	img_height;

} t_game;

void    check_errormap(char **map);
void    load_images(t_game *game);
void    display_map(t_game *game);
int row(t_game *game);
int columns(t_game *game);
void find_player_pos(t_game *game);

int key_handler(int keycode, t_game *game);


void moveup(t_game *game);
void movedown(t_game *game);
void moveleft(t_game *game);
void moveright(t_game *game);

int close_handler(t_game *game);
void win_game(t_game *game);
void unlock_exit(t_game *game);





#endif
