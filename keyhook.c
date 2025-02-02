/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyhook.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalquraa <aalquraa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 21:35:10 by aalquraa          #+#    #+#             */
/*   Updated: 2025/02/02 03:52:23 by aalquraa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"


int key_handler(int keycode, t_game *game)
{
    if (keycode == 119)
        moveup(game);
    else if (keycode == 115)
        movedown(game);
    else if (keycode == 97)
        moveleft(game);
    else if (keycode == 100)
        moveright(game);
    else if (keycode == 65307)
        close_handler(game);
    return (0); 
}

void moveup(t_game *game)
{
    if (game->player_y - 1 >= 0)
    {
        char new_pos = game->map[game->player_y - 1][game->player_x];

        if (new_pos == '1')
            return;
        if (new_pos == 'C')
        {
            game->collected_items++;
            game->map[game->player_y - 1][game->player_x] = '0';
            if (game->collected_items == game->total_collectibles)
                unlock_exit(game);
        }
        if (new_pos == 'E' && game->collected_items == game->total_collectibles)
        {
            win_game(game);
            return;
        }
        game->map[game->player_y][game->player_x] = '0';
        game->player_y--;
        game->map[game->player_y][game->player_x] = 'P';
        display_map(game);
    }
}
void movedown(t_game *game)
{
    if(game->map[game->player_y + 1][game->player_x] != '1')
    {
        game->map[game->player_y][game->player_x] = '0';  
        game->player_y++;
        game->map[game->player_y][game->player_x] = 'P';  
        display_map(game);
    }
}
void moveleft(t_game *game)
{
    if(game->map[game->player_y][game->player_x - 1] != '1')
    {
        game->map[game->player_y][game->player_x] = '0';  
        game->player_x--;
        game->map[game->player_y][game->player_x] = 'P';  
        display_map(game);
    }
}
void moveright(t_game *game)
{
    if(game->map[game->player_y][game->player_x + 1] != '1')
    {
       game->map[game->player_y][game->player_x] = '0';
       game->player_x++;
       game->map[game->player_y][game->player_x] = 'P';
       display_map(game);
    }
}