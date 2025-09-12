/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efinda <efinda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 07:46:13 by efinda            #+#    #+#             */
/*   Updated: 2025/06/16 18:27:00 by efinda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/tetr.h"

void	init_tiles(t_tile ***tiles)
{
	t_point	iter;

	iter = (t_point){.x = -1, .y = -1};
	if (!tiles)
		return ;
	*tiles = (t_tile **)malloc(sizeof(t_tile *) * TOTAL_TILE_Y);
	if (!(*tiles))
		return ;
	while (++iter.y < TOTAL_TILE_Y)
	{
		(*tiles)[iter.y] = (t_tile *)malloc(sizeof(t_tile) * TOTAL_TILE_X);
		if (!(*tiles)[iter.y])
		{
			free_tiles(tiles, iter.y);
			return ;
		}
		iter.x = -1;
		while (++iter.x < TOTAL_TILE_X)
			(*tiles)[iter.y][iter.x] = (t_tile){
				.color = 0, .crd = (t_point){0, 0}
			};
	}
}
