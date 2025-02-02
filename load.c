/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalquraa <aalquraa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 18:09:28 by aalquraa          #+#    #+#             */
/*   Updated: 2025/02/02 03:48:54 by aalquraa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void    load_images(t_game *game)
{
    game->player = mlx_xpm_file_to_image(game->mlx, "images/player.xpm", &game->img_width, &game->img_height);
    game->wall = mlx_xpm_file_to_image(game->mlx, "images/wall.xpm", &game->img_width, &game->img_height);
    game->exit= mlx_xpm_file_to_image(game->mlx, "images/exit.xpm", &game->img_width, &game->img_height);
    game->collectible = mlx_xpm_file_to_image(game->mlx, "images/collectible.xpm", &game->img_width, &game->img_height);
    game->ground = mlx_xpm_file_to_image(game->mlx, "images/ground.xpm", &game->img_width, &game->img_height);
    if (!game->wall || !game->ground || !game->player || !game->exit)
    {
        write(2, "Error: Missing or corrupted image files\n", 39);
        exit(EXIT_FAILURE);
    }
}

void    display_map(t_game *game)
{
    int i;
    int j;
    
    i = 0;
    while (game->map[i] != NULL)
    {
        j = 0;
        while (game->map[i][j] != '\0')
        {
            if (game->map[i][j] == '0')
                mlx_put_image_to_window(game->mlx, game->win, game->ground, j * game->img_width, i * game->img_height);
            else if (game->map[i][j] == '1')
                mlx_put_image_to_window(game->mlx, game->win, game->wall, j * game->img_width, i * game->img_height);
            else if (game->map[i][j] == 'P')
                mlx_put_image_to_window(game->mlx, game->win, game->player, j * game->img_width, i * game->img_height);
            else if (game->map[i][j] == 'E')
                mlx_put_image_to_window(game->mlx, game->win, game->exit, j * game->img_width, i * game->img_height);
            else if (game->map[i][j] == 'C')
                mlx_put_image_to_window(game->mlx, game->win, game->collectible, j * game->img_width, i * game->img_height);
            j++;
        }
        i++;
    }
}
