/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalquraa <aalquraa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 00:33:21 by aalquraa          #+#    #+#             */
/*   Updated: 2025/02/04 17:05:16 by aalquraa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	clean_game(t_game *game)
{
	int	i;

	i = -1;
	while (game->map[++i] != NULL)
		free(game->map[i]);
	free(game->map);
	if (game->player)
		mlx_destroy_image(game->mlx, game->player);
	if (game->wall)
		mlx_destroy_image(game->mlx, game->wall);
	if (game->exit)
		mlx_destroy_image(game->mlx, game->exit);
	if (game->collectible)
		mlx_destroy_image(game->mlx, game->collectible);
	if (game->ground)
		mlx_destroy_image(game->mlx, game->ground);
	if (game->win)
		mlx_destroy_window(game->mlx, game->win);
	if (game->mlx)
	{
		mlx_destroy_display(game->mlx);
		free(game->mlx);
	}
}

int	close_handler(t_game *game)
{
	clean_game(game);
	exit(EXIT_SUCCESS);
}
