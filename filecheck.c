/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filecheck.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalquraa <aalquraa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 16:28:48 by aalquraa          #+#    #+#             */
/*   Updated: 2025/02/04 19:18:39 by aalquraa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	isempty(char **argv)
{
	int		fd;
	int		bytes_read;
	char	*c;

	c = (char *)malloc(sizeof(char));
	if (!c)
		return (1);
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		return (1);
	bytes_read = read(fd, c, 1);
	free(c);
	close(fd);
	return (bytes_read == 0);
}

static int	isexist(char **argv)
{
	int	fd;

	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
	{
		write(2, "Error: File does not exist", 27);
		return (1);
	}
	close(fd);
	return (0);
}

int	checkfile(int argc, char **argv)
{
	if (argc != 2)
	{
		write(1, "Wrong Args ./so_long [map]\n", 28);
		return (1);
	}
	else if (ft_strncmp(argv[1] + ft_strlen(argv[1]) - 4, ".ber", 4) != 0)
	{
		ft_putstr_fd("Error: Map file must have .ber extension\n", 2);
		return (1);
	}
	if (isexist(argv) || isempty(argv))
	{
		return (1);
	}
	return (0);
}
