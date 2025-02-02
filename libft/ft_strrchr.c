/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalquraa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 18:14:15 by aalquraa          #+#    #+#             */
/*   Updated: 2024/09/01 16:12:28 by aalquraa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*a;
	int		b;

	a = (char *)s;
	b = ft_strlen(a);
	while (b >= 0)
	{
		if (a[b] == (char)c)
		{
			return (&a[b]);
		}
		b--;
	}
	return (0);
}
/*
int	main(void)
{
	printf("%s my\n",ft_strrchr("aememr",'e'));
	printf("%s u\n",strrchr("aememr",'e'));
}*/
