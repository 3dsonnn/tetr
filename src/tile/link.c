/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   link.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efinda <efinda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 17:43:36 by efinda            #+#    #+#             */
/*   Updated: 2025/05/26 08:18:27 by efinda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/tetr.h"

static void	link_horizontal_boundary_tiles(t_tile **tiles, int x)
{
    while (++x < TOTAL_TILE_X - 1)
	{
        // FIRST ROW
        tiles[0][x].right = &tiles[0][x + 1];
        tiles[0][x].left = &tiles[0][x - 1];
        tiles[0][x].down = &tiles[1][x];
        // LAST ROW
        tiles[TOTAL_TILE_Y - 1][x].right = &tiles[TOTAL_TILE_Y - 1][x + 1];
        tiles[TOTAL_TILE_Y - 1][x].left = &tiles[TOTAL_TILE_Y - 1][x - 1];
        tiles[TOTAL_TILE_Y - 1][x].up = &tiles[TOTAL_TILE_Y - 2][x];
    }
}

static void	link_vertical_boundary_tiles(t_tile **tiles, int y)
{
    // FIRST ROW
    tiles[0][0].down = &tiles[1][0];
    tiles[0][TOTAL_TILE_X - 1].down = &tiles[1][TOTAL_TILE_X - 1];
    // LAST ROW
    tiles[TOTAL_TILE_Y - 1][0].up = &tiles[TOTAL_TILE_Y - 2][0];
    tiles[TOTAL_TILE_Y - 1][TOTAL_TILE_X - 1].up = &tiles[TOTAL_TILE_Y - 2][TOTAL_TILE_X - 1];
    while (++y < TOTAL_TILE_Y)
	{
        tiles[y][0].right = &tiles[y][1];
        tiles[y][TOTAL_TILE_X - 1].left = &tiles[y][TOTAL_TILE_X - 2];
        if (!y || y == (TOTAL_TILE_Y - 1))
            continue ;
        tiles[y][0].up = &tiles[y - 1][0];
        tiles[y][0].down = &tiles[y + 1][0];
        tiles[y][TOTAL_TILE_X - 1].up = &tiles[y - 1][TOTAL_TILE_X - 1];
        tiles[y][TOTAL_TILE_X - 1].down = &tiles[y + 1][TOTAL_TILE_X - 1];
    }
}

void	link_tiles(t_tile **tiles)
{
    t_point iter;

    iter = (t_point){0, 0};
    link_vertical_boundary_tiles(tiles, -1);
    link_horizontal_boundary_tiles(tiles, 0);
    while (++iter.y < TOTAL_TILE_Y - 1)
	{
		iter.x = 0;
		while (++iter.x < TOTAL_TILE_X - 1)
		{
			tiles[iter.y][iter.x].up = &tiles[iter.y - 1][iter.x];
			tiles[iter.y][iter.x].down = &tiles[iter.y + 1][iter.x];
			tiles[iter.y][iter.x].left = &tiles[iter.y][iter.x - 1];
			tiles[iter.y][iter.x].right = &tiles[iter.y][iter.x + 1];
		}
	}
}
