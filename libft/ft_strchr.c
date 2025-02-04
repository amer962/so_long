/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalquraa <aalquraa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 12:24:32 by aalquraa          #+#    #+#             */
/*   Updated: 2025/02/04 16:43:32 by aalquraa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char	*a;

	if (!s)
		return (NULL);
	if ((char)c == '\0')
		return ((char *)s);
	a = (char *)s;
	while (*a)
	{
		if (*a == (char)c)
			return (a);
		a++;
	}
	return (0);
}
/*int main()
{
	printf("%s my\n",ft_strchr("amer",'z'));
	printf("%s u\n",strchr("amer",'e'));
}*/
