/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   widthandheight.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalquraa <aalquraa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 20:07:51 by aalquraa          #+#    #+#             */
/*   Updated: 2025/02/01 20:37:28 by aalquraa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int row(t_game *game)
{
    int n;
    
    n = 0;
    while (game->map[n] != NULL)
    {
        n++;
    }
    
    return (n);
}
int columns(t_game *game)
{
    int m;
    
    m = 0;
    if (game->map[0] != NULL)
    {
        while (game->map[0][m] != '\0')
        {
            m++;
        }
    }
        return (m);
}