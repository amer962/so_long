/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalquraa <aalquraa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 17:06:11 by aalquraa          #+#    #+#             */
/*   Updated: 2025/02/04 19:18:11 by aalquraa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	check_map_rectangular(char **map)
{
	int	i;
	int	len;

	i = 0;
	len = ft_strlen(map[0]);
	while (map[i] != NULL)
	{
		if (ft_strlen(map[i]) != len)
		{
			return (0);
		}
		i++;
	}
	return (1);
}

static int	check_walls(char **map)

{
	int	i;
	int	len;
	int	row;

	row = 0;
	len = ft_strlen(map[0]);
	i = 0;
	while (map[row] != NULL)
		row++;
	while (i < len)
	{
		if (map[0][i] != '1' || map[row - 1][i] != '1')
			return (0);
		i++;
	}
	i = 1;
	while (map[i] != NULL)
	{
		if (map[i][0] != '1' || map[i][len - 1] != '1')
			return (0);
		i++;
	}
	return (1);
}

static int	count_exit(char **map)
{
	int	i;
	int	j;
	int	count;

	i = 0;
	j = 0;
	count = 0;
	while (map[i] != NULL)
	{
		j = 0;
		while (map[i][j] != '\0')
		{
			if (map[i][j] == 'E')
				count++;
			j++;
		}
		i++;
	}
	if (count > 1)
	{
		return (0);
	}
	return (1);
}

static int	count_player(char **map)
{
	int	i;
	int	j;
	int	count;

	i = 0;
	j = 0;
	count = 0;
	while (map[i] != NULL)
	{
		j = 0;
		while (map[i][j] != '\0')
		{
			if (map[i][j] == 'P')
				count++;
			j++;
		}
		i++;
	}
	if (count != 1)
	{
		return (0);
	}
	return (1);
}

static int	count_collectibles(char **map)
{
	int	i;
	int	j;
	int	count;

	i = 0;
	j = 0;
	count = 0;
	while (map[i] != NULL)
	{
		j = 0;
		while (map[i][j] != '\0')
		{
			if (map[i][j] == 'C')
				count++;
			j++;
		}
		i++;
	}
	if (count >= 1)
	{
		return (1);
	}
	return (0);
}
static int	notchar(char **map)
{
	int	i;
	int	j;
	int	count;

	i = 0;
	j = 0;
	count = 0;
	while (map[i] != NULL)
	{
		j = 0;
		while (map[i][j] != '\0')
		{
			if (map[i][j] != 'C' && map[i][j] != 'P' && map[i][j] != 'E'
				&& map[i][j] != '1' && map[i][j] != '0')
				count++;
			j++;
		}
		i++;
		if (count != 0)
		{
			return (0);
		}
	}
	return (1);
}

void	check_errormap(char **map)
{
	if (!check_map_rectangular(map))
	{
		write (2, "Error: The map is not rectangular.\n", 36);
		exit(EXIT_FAILURE);
	}
	if (!check_walls(map))
	{
		write (2, "Error: The map is not enclosed by walls.\n", 42);
		exit(EXIT_FAILURE);
	}
	if (!count_exit(map))
	{
		write (2, "Error: The map must have exactly one exit.\n", 44);
		exit(EXIT_FAILURE);
	}
	if (!count_player(map))
	{
		write (2, "Error: The map must have exactly one start position.\n", 54);
		exit(EXIT_FAILURE);
	}
	if (!count_collectibles(map))
	{
		write (2, "Error: The map must contain at least one collectible.\n", 55);
	}
	if (!notchar(map))
	{
		write (2, "Error: The map contain char not allow.\n", 40);
		exit(EXIT_FAILURE);
	}
	return ;
}
