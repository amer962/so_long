/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalquraa <aalquraa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 15:11:25 by aalquraa          #+#    #+#             */
/*   Updated: 2025/02/04 19:15:44 by aalquraa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static char	*trim_line(char *line)
{
	size_t	len;

	len = ft_strlen(line);
	while (len > 0 && (line[len - 1] == '\n'))
	{
		line[len - 1] = '\0';
		len--;
	}
	return (line);
}

static size_t	count_lines(char *filename)
{
	int		fd;
	char	*line;
	size_t	count;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
	{
		write (2, "Error open file", 16);
		exit(EXIT_FAILURE);
	}
	count = 0;
	line = get_next_line(fd);
	while (1)
	{
		line = trim_line(line);
		count++;
		free(line);
		line = get_next_line(fd);
		if (!line)
			break ;
	}
	close(fd);
	return (count);
}

static void	fill_map(char **map, int fd)
{
	char	*line;
	int		i;

	i = 0;
	line = get_next_line(fd);
	while (line != NULL)
	{
		line = trim_line(line);
		map[i] = ft_strdup(line);
		if (!map[i])
		{
			while (i > 0)
				free(map[--i]);
			free(map);
			free(line);
			close(fd);
			write (2, "Error duplicating line", 23);
			exit(EXIT_FAILURE);
		}
		free(line);
		i++;
		line = get_next_line(fd);
	}
	map[i] = NULL;
}

char	**readmap(char *str)
{
	int		fd;
	char	**map;
	size_t	raw_count;

	raw_count = count_lines(str);
	map = malloc((raw_count + 1) * sizeof(char *));
	if (!map)
	{
		write (2, "Error allocating memory for map", 32);
		exit(EXIT_FAILURE);
	}
	fd = open(str, O_RDONLY);
	if (fd == -1)
	{
		write (2, "Error opening file", 19);
		free(map);
		exit(EXIT_FAILURE);
	}
	fill_map(map, fd);
	close(fd);
	return (map);
}

int	main(int argc, char **argv)
{
	t_game	game;

	if (checkfile(argc, argv))
		exit(EXIT_FAILURE);
	game.map = readmap(argv[1]);
	check_errormap(game.map);
	find_player_pos(&game);
	game.mlx = mlx_init();
	game.map_width = columns(&game);
	game.map_height = row(&game);
	game.win = mlx_new_window(game.mlx, game.map_width * 50, game.map_height
			* 50, "so_long");
	load_images(&game);
	display_map(&game);
	init(&game);
	mlx_hook(game.win, KeyPress, KeyPressMask, key_handler, &game);
	mlx_hook(game.win, ClientMessage, StructureNotifyMask, close_handler,
		&game);
	mlx_loop(game.mlx);
}
