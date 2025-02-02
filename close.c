/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalquraa <aalquraa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 00:33:21 by aalquraa          #+#    #+#             */
/*   Updated: 2025/02/02 01:35:30 by aalquraa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int close_handler(t_game *game)
{
    int i;
     
     i = 0;
    while (game->map[i] != NULL)
    {
        free(game->map[i]);
    }
    free(game->map);
    mlx_destroy_window(game->mlx, game->win);
    mlx_destroy_image(game->mlx, game->player);
    mlx_destroy_image(game->mlx, game->wall);
    mlx_destroy_image(game->mlx, game->exit);
    mlx_destroy_image(game->mlx, game->collectible);
    mlx_destroy_image(game->mlx, game->ground);

    exit(0);
}
void unlock_exit(t_game *game)
{
    int i = 0;
    while (i < game->map_height)  
    {
        int j = 0;
        while (j < game->map_width)  
        {
            if (game->map[i][j] == 'E')  
            {
                game->map[i][j] = 'e';  
            }
            j++;
        }
        i++;
    }
}
void win_game(t_game *game)
{
    (void) game;
    int count = 0;
    while (count < 1)  
    {
        write(1, "Congratulations! You have won the game!\n", 40);
        count++;  
    }
    exit(EXIT_SUCCESS);  
}
