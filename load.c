/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalquraa <aalquraa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 18:09:28 by aalquraa          #+#    #+#             */
/*   Updated: 2025/02/04 17:47:00 by aalquraa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	load_images(t_game *game)
{
	game->player = mlx_xpm_file_to_image(game->mlx, "images/player.xpm",
			&game->img_width, &game->img_height);
	game->wall = mlx_xpm_file_to_image(game->mlx, "images/wall.xpm",
			&game->img_width, &game->img_height);
	game->exit = mlx_xpm_file_to_image(game->mlx, "images/exit.xpm",
			&game->img_width, &game->img_height);
	game->collectible = mlx_xpm_file_to_image(game->mlx,
			"images/collectible.xpm", &game->img_width, &game->img_height);
	game->ground = mlx_xpm_file_to_image(game->mlx, "images/ground.xpm",
			&game->img_width, &game->img_height);
	if (!game->wall || !game->ground || !game->player || !game->exit
		|| !game->collectible)
	{
		write(2, "Error: Missing or corrupted image files\n", 39);
		clean_game(game);
		exit(EXIT_FAILURE);
	}
}

static void	put_image(t_game *game, void *image, int i, int j)
{
	mlx_put_image_to_window(game->mlx, game->win, image, j * game->img_width,
		i * game->img_height);
}

void	display_map(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (game->map[i] != NULL)
	{
		j = 0;
		while (game->map[i][j] != '\0')
		{
			if (game->map[i][j] == '0')
				put_image(game, game->ground, i, j);
			else if (game->map[i][j] == '1')
				put_image(game, game->wall, i, j);
			else if (game->map[i][j] == 'P')
				put_image(game, game->player, i, j);
			else if (game->map[i][j] == 'E')
				put_image(game, game->exit, i, j);
			else if (game->map[i][j] == 'C')
				put_image(game, game->collectible, i, j);
			j++;
		}
		i++;
	}
}
