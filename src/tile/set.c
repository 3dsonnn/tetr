/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efinda <efinda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/22 15:28:03 by efinda            #+#    #+#             */
/*   Updated: 2025/05/24 14:01:05 by efinda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/tetr.h"

void	set_tiles(t_tile **tiles, t_point size, t_point padd)
{
	t_point	iter;

	iter = (t_point){-1, -1};
	if (!tiles || !(*tiles) || ft_origin(size))
		return ;
	while (++iter.y < size.y)
	{
		iter.x = -1;
		while (++iter.x < size.x)
		{
			tiles[iter.y][iter.x].crd = (t_point){.x = padd.x + (iter.x * TILE), .y = padd.y + (iter.y * TILE)};
			tiles[iter.y][iter.x].color = BLACK;
		}
	}
}
