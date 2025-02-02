/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalquraa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/31 11:15:32 by aalquraa          #+#    #+#             */
/*   Updated: 2024/09/01 18:31:09 by aalquraa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *nptr)
{
	int		i;
	int		sn;
	int		num;
	char	*a;

	a = (char *)nptr;
	i = 0;
	sn = 1;
	num = 0;
	while ((a[i] == ' ') || (a[i] >= 9 && a[i] <= 13))
	{
		i++;
	}
	if (a[i] == '-' || a[i] == '+')
	{
		if (a[i] == '-')
			sn = sn * -1;
		i++;
	}
	while (a[i] <= '9' && a[i] >= '0')
	{
		num = num * 10 + (a[i] - '0');
		i++;
	}
	return (sn * num);
}

/*int	main(void)
{
	char a[] ="-4886";

	printf("%d\n", ft_atoi(a));
	printf("%d\n", atoi(a));
}*/
