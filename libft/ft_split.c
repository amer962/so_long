/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalquraa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 17:02:43 by aalquraa          #+#    #+#             */
/*   Updated: 2024/09/07 12:07:56 by aalquraa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_count(char const *s, char c)
{
	int	count;

	count = 0;
	while (*s)
	{
		while (*s == c)
			s++;
		if (*s)
			count++;
		while (*s && *s != c)
			s++;
	}
	return (count);
}

static void	*ft_free(char **str, int i)
{
	while (i >= 0)
	{
		free(str[i]);
		i--;
	}
	free(str);
	return (NULL);
}

static int	ft_len(char const *s, char c)
{
	int	i;

	i = 0;
	while (s[i] != '\0' && s[i] != c)
		i++;
	return (i);
}

static char	**ft_fill(char **str, const char *s, char c)
{
	int	i;
	int	j;
	int	x;

	i = 0;
	x = 0;
	while (s[i])
	{
		if (s[i] != c)
		{
			j = 0;
			str[x] = malloc(ft_len(&s[i], c) + 1);
			if (!str[x])
				return (ft_free(str, x - 1));
			while (s[i] && s[i] != c)
				str[x][j++] = s[i++];
			str[x][j] = '\0';
			x++;
		}
		else
			i++;
	}
	str[x] = NULL;
	return (str);
}

char	**ft_split(char const *s, char c)
{
	char	**str;
	int		word;

	if (!s)
		return (NULL);
	if (s[0] == '\0')
	{
		str = (char **)malloc(sizeof(char *));
		if (str != NULL)
			str[0] = NULL;
		return (str);
	}
	word = ft_count(s, c);
	str = (char **)malloc((word + 1) * sizeof(char *));
	if (!str)
		return (NULL);
	str = ft_fill(str, s, c);
	return (str);
}
