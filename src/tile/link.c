/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   link.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efinda <efinda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 17:43:36 by efinda            #+#    #+#             */
/*   Updated: 2025/05/24 13:55:14 by efinda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/tetr.h"

static void	link_horizontal_boundary_tiles(t_tile **tiles, t_point size, int x)
{
    while (++x < size.x - 1)
	{
        // FIRST ROW
        tiles[0][x].right = &tiles[0][x + 1];
        tiles[0][x].left = &tiles[0][x - 1];
        tiles[0][x].down = &tiles[1][x];
        // LAST ROW
        tiles[size.y - 1][x].right = &tiles[size.y - 1][x + 1];
        tiles[size.y - 1][x].left = &tiles[size.y - 1][x - 1];
        tiles[size.y - 1][x].up = &tiles[size.y - 2][x];
    }
}

static void	link_vertical_boundary_tiles(t_tile **tiles, t_point size, int y)
{
    // FIRST ROW
    tiles[0][0].down = &tiles[1][0];
    tiles[0][size.x - 1].down = &tiles[1][size.x - 1];
    // LAST ROW
    tiles[size.y - 1][0].up = &tiles[size.y - 2][0];
    tiles[size.y - 1][size.x - 1].up = &tiles[size.y - 2][size.x - 1];
    while (++y < size.y)
	{
        tiles[y][0].right = &tiles[y][1];
        tiles[y][size.x - 1].left = &tiles[y][size.x - 2];
        if (!y || y == (size.y - 1))
            continue ;
        tiles[y][0].up = &tiles[y - 1][0];
        tiles[y][0].down = &tiles[y + 1][0];
        tiles[y][size.x - 1].up = &tiles[y - 1][size.x - 1];
        tiles[y][size.x - 1].down = &tiles[y + 1][size.x - 1];
    }
}

void	link_tiles(t_tile **tiles, t_point size)
{
    t_point iter;

    iter = (t_point){0, 0};
    link_vertical_boundary_tiles(tiles, size, -1);
    link_horizontal_boundary_tiles(tiles, size, 0);
    while (++iter.y < size.y - 1)
	{
		iter.x = 0;
		while (++iter.x < size.x - 1)
		{
			tiles[iter.y][iter.x].up = &tiles[iter.y - 1][iter.x];
			tiles[iter.y][iter.x].down = &tiles[iter.y + 1][iter.x];
			tiles[iter.y][iter.x].left = &tiles[iter.y][iter.x - 1];
			tiles[iter.y][iter.x].right = &tiles[iter.y][iter.x + 1];
		}
	}
}
