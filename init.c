/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalquraa <aalquraa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 18:26:58 by aalquraa          #+#    #+#             */
/*   Updated: 2025/02/04 16:45:01 by aalquraa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init(t_game *game)
{
	game->moves = 0;
	game->collected_items = 0;
	game->total_collectibles = count_collectible(game->map);
	find_exit_pos(game);
}

void	movepart(t_game *game)
{
	game->map[game->player_y][game->player_x] = '0';
	if (game->exit_x == game->player_x && game->exit_y == game->player_y)
		game->map[game->player_y][game->player_x] = 'E';
	game->moves++;
}
