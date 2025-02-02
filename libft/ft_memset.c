/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalquraa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 14:22:29 by aalquraa          #+#    #+#             */
/*   Updated: 2024/09/05 19:46:24 by aalquraa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)

{
	size_t		i;
	char		*str;

	i = 0;
	str = (char *)s;
	while (i < n)
	{
		str[i] = c;
		i++;
	}
	return (str);
}

/*int	main(void)
{
	char	arr[12] = "12345678910";

	ft_memset(arr, 'q', 5);
	printf("Array elements: ");
	for (int i = 0; i < 10; i++)
	{
		printf("%c ", arr[i]);
	}
	printf("\n");
	arr[9] = '\0';
	printf("Array as string: %s\n", arr);
	return (0);
}*/
