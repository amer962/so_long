/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalquraa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/31 18:13:53 by aalquraa          #+#    #+#             */
/*   Updated: 2024/09/01 16:10:51 by aalquraa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*p;
	char	*src;
	int		i;

	src = (char *)s;
	i = 0;
	while (src[i] != '\0')
	{
		i++;
	}
	p = (char *)malloc(i + 1 * sizeof(char));
	if (!p)
		return (NULL);
	i = 0;
	while (src[i] != '\0')
	{
		p[i] = src[i];
		i++;
	}
	p[i] = '\0';
	return (p);
}
/*int	main(void)

{
	char *p = ft_strdup("Amer");
	printf("%s",p);
	free(p);

}*/
