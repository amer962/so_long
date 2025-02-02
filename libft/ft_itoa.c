/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalquraa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 10:53:04 by aalquraa          #+#    #+#             */
/*   Updated: 2024/09/05 19:39:34 by aalquraa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	intlen(int n)
{
	int	i;

	i = 0;
	if (n < 0)
		i++;
	while (n != 0)
	{
		n /= 10;
		i++;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	char			*str;
	unsigned int	len;

	if (n == 0)
		return (ft_strdup("0"));
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	len = intlen(n);
	str = malloc(sizeof(char) * (len + 1));
	if (str)
	{
		str[len] = '\0';
		if (n < 0)
		{
			str[0] = '-';
			n = -n;
		}
		while (n)
		{
			str[--len] = '0' + (n % 10);
			n /= 10;
		}
	}
	return (str);
}

/*int	main(void)
{
	printf("%s", ft_itoa(5));
}*/
