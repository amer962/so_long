/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalquraa <aalquraa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 15:11:25 by aalquraa          #+#    #+#             */
/*   Updated: 2025/02/02 04:12:15 by aalquraa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#include "so_long.h"

static char *trim_line(char *line)
{
    size_t len = ft_strlen(line);
    
    while (len > 0 && (line[len - 1] == '\n'))
    {
        line[len - 1] = '\0';
        len--;
    }
    
    return (line);
}

char **readmap(char *str)
{
    int fd;
    char *line;
    char **map;
    int i;
    size_t raw_count;
    
    i = 0;
    raw_count = 0;
    fd = open(str, O_RDONLY);
    if (fd == -1)
    {
        perror("Error open file");
        exit(EXIT_FAILURE);
    }
    while((line = get_next_line(fd)) != NULL)
    {
        line = trim_line(line);
        raw_count++;
        free(line);
    }
    close(fd);
    map = malloc((raw_count + 1) * sizeof(char *));
    if (!map)
    {
        perror("Error allocating memory for map");
        exit(EXIT_FAILURE);
    }
    fd = open(str, O_RDONLY);
    if (fd == -1)
    {
        perror("Error opening file");
        free(map);
        exit(EXIT_FAILURE);
    }
    while((line = get_next_line(fd)) != NULL)
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
            perror("Error duplicating line");
            exit(EXIT_FAILURE);
        }
        free(line);
        i++;
    }
    map[i] = NULL;
    close(fd);
    return (map);
}

int main(int argc, char **argv)
{
    t_game game;
    int fd;
    
    if (argc != 2)
    {
        perror("Error");
        exit(EXIT_FAILURE);
    }
    if (ft_strncmp(argv[1] + ft_strlen(argv[1]) - 4, ".ber", 4) != 0)
    {
        ft_putstr_fd("Error: Map file must have .ber extension\n", 2);
        exit(EXIT_FAILURE);
    }
    fd = open(argv[1], O_RDONLY);
    if (fd == -1)
    {
        perror("Error: File does not exist");
        exit(EXIT_FAILURE);
    }
    close(fd);
    game.map = readmap(argv[1]);
    check_errormap(game.map);
    find_player_pos(&game);
    game.mlx = mlx_init();
    game.map_width = columns(&game);
    game.map_height = row(&game);
    game.win = mlx_new_window(game.mlx, game.map_width * 50, game.map_height * 50, "so_long");
    load_images(&game);
    display_map(&game);
    mlx_hook(game.win, 2, 1L << 0, key_handler, &game);
	mlx_hook(game.win, 17, 0, close_handler, &game);
    mlx_loop(game.mlx);
}


