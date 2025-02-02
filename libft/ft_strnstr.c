/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalquraa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 11:37:07 by aalquraa          #+#    #+#             */
/*   Updated: 2024/09/05 19:59:09 by aalquraa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

//#include<strlib.h>

char	*ft_strnstr(const char *big, const char *little, size_t len)

{
	size_t		i;
	size_t		j;
	char		*b;
	char		*l;

	j = 0;
	b = (char *)big;
	l = (char *)little;
	if (l[j] == '\0')
		return (b);
	i = 0;
	while (b[i] != '\0' && i < len)
	{
		if (b[i] == l[0])
		{
			j = 0;
			while (b[i + j] == l[j] && (i + j) < len && l[j] != '\0')
				j++;
			if (l[j] == '\0')
				return (&b[i]);
		}
		i++;
	}
	return (NULL);
}
/*int main()
{
	printf("%s",ft_strnstr("amer amin alquraa","amin", 0));
}*/
