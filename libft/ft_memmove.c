/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalquraa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 12:52:06 by aalquraa          #+#    #+#             */
/*   Updated: 2024/09/07 17:20:00 by aalquraa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char	*d;
	unsigned char	*s;
	size_t			i;

	i = 0;
	d = (unsigned char *)dest;
	s = (unsigned char *)src;
	if (d == NULL && s == NULL)
		return (NULL);
	if (s >= d)
	{
		while (i < n)
		{
			d[i] = s[i];
			i++;
		}
		return (d);
	}
	else if (d > s)
	{
		i = n;
		while (i-- > 0)
			d[i] = s[i];
	}
	return (d);
}

/*int	main(void)
{
  char buffer1[20] = "12345";

  ft_memmove(buffer1 + 2, buffer1, 13);

  printf("After memmove: %s\n", buffer1);
  memmove(buffer1 + 2, buffer1, 13);
  printf("After memmove: %s\n",buffer1);
}
#include "libft.h"

void    *ft_memmove(void *dest, const void *src, size_t n)
{
    unsigned char   *d;
    unsigned char   *s;
    size_t          i;

    d = (unsigned char *)dest;
    s = (unsigned char *)src;

    // Fixing NULL pointer check
    if (d == NULL || s == NULL)
        return (NULL);

    // If src and dest overlap and src is before dest, copy backwards
    if (s < d && d < s + n)
    {
        i = n;
        while (i-- > 0)
        {
            d[i] = s[i];
        }
    }
    else
    {
        // If src is after or equal to dest, copy forwards
        i = 0;
        while (i < n)
        {
            d[i] = s[i];
            i++;
        }
    }

    return (d);
}
*/
