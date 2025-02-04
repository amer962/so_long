/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalquraa <aalquraa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 14:19:05 by aalquraa          #+#    #+#             */
/*   Updated: 2025/02/04 16:42:06 by aalquraa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char *s1, char const *s2)
{
	int		i;
	int		j;
	char	*join;

	if (!s1)
	{
		s1 = malloc(1);
		s1[0] = '\0';
	}
	i = -1;
	j = -1;
	join = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!join || !s1 || !s2)
		return (NULL);
	while (s1[++i] != '\0')
		join[i] = s1[i];
	while (s2[++j] != '\0')
		join[i + j] = s2[j];
	join[i + j] = '\0';
	free(s1);
	return (join);
}
