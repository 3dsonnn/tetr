/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efinda <efinda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/22 15:28:03 by efinda            #+#    #+#             */
/*   Updated: 2025/05/26 14:18:55 by efinda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/tetr.h"

void	set_tiles(t_tile **tiles, t_point padd)
{
	t_point	iter;
	t_tile	*tmp;

	iter = (t_point){-1, -1};
	if (!tiles || !(*tiles))
		return ;
	while (++iter.y < TOTAL_TILE_Y)
	{
		iter.x = -1;
		while (++iter.x < TOTAL_TILE_X)
		{
			tmp = &tiles[iter.y][iter.x];
			tmp->color = BLACK;
			if (!iter.x && !iter.y)
				tmp->crd = padd;
			else if (!iter.x)
				tmp->crd = (t_point){.x = padd.x,
					.y = tmp->up->crd.y + TILE + 1};
			else
				tmp->crd = (t_point){.x = tmp->left->crd.x + TILE + 1,
					.y = tmp->left->crd.y};
		}
	}
}
