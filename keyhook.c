/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyhook.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalquraa <aalquraa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 21:35:10 by aalquraa          #+#    #+#             */
/*   Updated: 2025/02/04 16:46:00 by aalquraa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	key_handler(int keycode, t_game *game)
{
	if (keycode == XK_W || keycode == XK_w || keycode == XK_Up)
		moveup(game);
	if (keycode == XK_S || keycode == XK_s)
		movedown(game);
	if (keycode == XK_A || keycode == XK_a)
		moveleft(game);
	if (keycode == XK_D || keycode == XK_d)
		moveright(game);
	if (keycode == XK_Escape)
		close_handler(game);
	return (0);
}

void	moveup(t_game *game)
{
	char	new_pos;

	if (game->player_y - 1 >= 0)
	{
		new_pos = game->map[game->player_y - 1][game->player_x];
		if (new_pos == '1')
			return ;
		if (new_pos == 'C')
		{
			game->collected_items++;
			game->map[game->player_y - 1][game->player_x] = '0';
		}
		if (new_pos == 'E' && game->collected_items == game->total_collectibles)
		{
			write(1, "You win!", 9);
			clean_game(game);
			exit(EXIT_SUCCESS);
		}
		movepart(game);
		game->player_y--;
		ft_putnbr_fd(game->moves, 1);
		write(1, " = MOVES\n", 10);
		game->map[game->player_y][game->player_x] = 'P';
		display_map(game);
	}
}

void	movedown(t_game *game)
{
	char	new_pos;

	if (game->player_y + 1 >= 0)
	{
		new_pos = game->map[game->player_y + 1][game->player_x];
		if (new_pos == '1')
			return ;
		if (new_pos == 'C')
		{
			game->collected_items++;
			game->map[game->player_y + 1][game->player_x] = '0';
		}
		if (new_pos == 'E' && game->collected_items == game->total_collectibles)
		{
			write(1, "You win!", 9);
			clean_game(game);
			exit(EXIT_SUCCESS);
		}
		movepart(game);
		game->player_y++;
		ft_putnbr_fd(game->moves, 1);
		write(1, " = MOVES\n", 10);
		game->map[game->player_y][game->player_x] = 'P';
		display_map(game);
	}
}

void	moveleft(t_game *game)
{
	char	new_pos;

	if (game->player_x - 1 >= 0)
	{
		new_pos = game->map[game->player_y][game->player_x - 1];
		if (new_pos == '1')
			return ;
		if (new_pos == 'C')
		{
			game->collected_items++;
			game->map[game->player_y][game->player_x - 1] = '0';
		}
		if (new_pos == 'E' && game->collected_items == game->total_collectibles)
		{
			write(1, "You win!", 9);
			clean_game(game);
			exit(EXIT_SUCCESS);
		}
		movepart(game);
		game->player_x--;
		ft_putnbr_fd(game->moves, 1);
		write(1, " = MOVES\n", 10);
		game->map[game->player_y][game->player_x] = 'P';
		display_map(game);
	}
}

void	moveright(t_game *game)
{
	char	new_pos;

	if (game->player_x + 1 >= 0)
	{
		new_pos = game->map[game->player_y][game->player_x + 1];
		if (new_pos == '1')
			return ;
		if (new_pos == 'C')
		{
			game->collected_items++;
			game->map[game->player_y][game->player_x + 1] = '0';
		}
		if (new_pos == 'E' && game->collected_items == game->total_collectibles)
		{
			write(1, "You win!", 9);
			clean_game(game);
			exit(EXIT_SUCCESS);
		}
		movepart(game);
		game->player_x++;
		ft_putnbr_fd(game->moves, 1);
		write(1, " = MOVES\n", 10);
		game->map[game->player_y][game->player_x] = 'P';
		display_map(game);
	}
}
