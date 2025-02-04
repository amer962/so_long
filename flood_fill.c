/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalquraa <aalquraa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 18:59:12 by aalquraa          #+#    #+#             */
/*   Updated: 2025/02/04 20:15:08 by aalquraa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

#include "so_long.h"

static void	flood_fill(t_game *game, int x, int y, int *collectibles, int *exit_found)
{
    if (x < 0 || y < 0 || x >= game->map_height || y >= game->map_width
        || game->map[x][y] == '1' || game->visited[x][y])
        return ;
    game->visited[x][y] = 1;
    if (game->map[x][y] == 'C')
        (*collectibles)++;
    if (game->map[x][y] == 'E')
        *exit_found = 1;
    flood_fill(game, x + 1, y, collectibles, exit_found);
    flood_fill(game, x - 1, y, collectibles, exit_found);
    flood_fill(game, x, y + 1, collectibles, exit_found);
    flood_fill(game, x, y - 1, collectibles, exit_found);
}
