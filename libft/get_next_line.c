/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalquraa <aalquraa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 12:49:06 by aalquraa          #+#    #+#             */
/*   Updated: 2025/01/29 19:54:39 by aalquraa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_read(char *str, int fd)
{
	char	*buffer;
	int		byet_read;

	buffer = malloc(BUFFER_SIZE + 1);
	if (!buffer)
	{
		free(str);
		return (NULL);
	}
	byet_read = 1;
	while (!ft_strchr(str, '\n') && byet_read != 0)
	{
		byet_read = read(fd, buffer, BUFFER_SIZE);
		if (byet_read < 0)
		{
			free(buffer);
			free(str);
			return (NULL);
		}
		buffer[byet_read] = '\0';
		str = ft_strjoin(str, buffer);
	}
	free(buffer);
	return (str);
}

static char	*ft_line(char *str)
{
	int		i;
	char	*buffer;

	i = 0;
	while (str[i] && str[i] != '\n')
		i++;
	buffer = malloc(i + 2);
	if (!buffer)
	{
		free(str);
		return (NULL);
	}
	i = 0;
	while (str[i] && str[i] != '\n')
	{
		buffer[i] = str[i];
		i++;
	}
	if (str[i] == '\n')
	{
		buffer[i] = str[i];
		i++;
	}
	buffer[i] = '\0';
	return (buffer);
}

static char	*ft_cut(char *str)
{
	int		i;
	int		j;
	char	*buffer;

	i = 0;
	while (str[i] && str[i] != '\n')
		i++;
	if (!str[i])
	{
		free(str);
		return (NULL);
	}
	buffer = malloc(ft_strlen(str) - i + 1);
	if (!buffer)
	{
		free(str);
		return (NULL);
	}
	i++;
	j = 0;
	while (str[i] != '\0')
		buffer[j++] = str[i++];
	buffer[j] = '\0';
	free(str);
	return (buffer);
}

char	*get_next_line(int fd)
{
	static char	*str = NULL;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	str = ft_read(str, fd);
	if (!str)
		return (NULL);
	line = ft_line(str);
	str = ft_cut(str);
	if (!line[0])
	{
		free(line);
		return (NULL);
	}
	return (line);
}
/*int	main(void)
{
	int		fd;
	char	*line;

	fd = open("test.txt", O_RDONLY);
	while ((line = get_next_line(fd)) != NULL)
	{
		printf("%s", line);
		free(line);
	}
	close(fd);
	return (0);
}*/