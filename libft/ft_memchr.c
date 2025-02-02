/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalquraa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 17:12:42 by aalquraa          #+#    #+#             */
/*   Updated: 2024/09/05 19:43:12 by aalquraa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)

{
	unsigned char	*a;
	size_t			i;

	a = (unsigned char *)s;
	i = 0;
	while (i < n)
	{
		if (a[i] == (unsigned char)c)
		{
			return (&a[i]);
		}
		i++;
	}
	return (0);
}
/*int main()
  {
  printf("%p my\n",ft_memchr("amer",'z','3'));
  printf("%p u\n",memchr("amer",'z','3'));
  }*/
