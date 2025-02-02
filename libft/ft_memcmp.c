/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalquraa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 17:54:54 by aalquraa          #+#    #+#             */
/*   Updated: 2024/09/05 19:44:46 by aalquraa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)

{
	unsigned char	*sr1;
	unsigned char	*sr2;
	size_t			i;
	int				res;

	i = 0;
	sr1 = (unsigned char *)s1;
	sr2 = (unsigned char *)s2;
	while (i < n)
	{
		if (sr1[i] != sr2[i])
		{
			res = (unsigned char)sr1[i] - (unsigned char)sr2[i];
			if (res > 0)
				return (1);
			if (res < 0)
				return (-1);
			return ((unsigned char)sr1[i] - (unsigned char)sr2[i]);
		}
		i++;
	}
	return (0);
}
/*int  main()
{
	printf("%d\n",ft_memcmp("ame","ame", 3));
	printf("%d\n",memcmp("ame","ame", 3));
}*/
