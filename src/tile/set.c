/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efinda <efinda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/22 15:28:03 by efinda            #+#    #+#             */
/*   Updated: 2025/05/26 08:18:50 by efinda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/tetr.h"

void	set_tiles(t_tile **tiles, t_point padd)
{
	t_point	iter;

	iter = (t_point){-1, -1};
	if (!tiles || !(*tiles))
		return ;
	while (++iter.y < TOTAL_TILE_Y)
	{
		iter.x = -1;
		while (++iter.x < TOTAL_TILE_X)
		{
			tiles[iter.y][iter.x].color = BLACK;
			if (!iter.x)
				tiles[iter.y][iter.x].crd = (t_point){
					.x = padd.x + (iter.x * TILE),
					.y = padd.y + (iter.y * TILE)
				};
			else
				tiles[iter.y][iter.x].crd = (t_point){
					.x = (padd.x + (iter.x * TILE)) + 1,
					.y = (padd.y + (iter.y * TILE)) + 1
				};
		}
	}
}
