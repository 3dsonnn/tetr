/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efinda <efinda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 07:46:13 by efinda            #+#    #+#             */
/*   Updated: 2025/05/24 13:46:20 by efinda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/tetr.h"

void	init_tiles(t_tile ***tiles, t_point size)
{
	t_point	iter;

	iter = (t_point){.x = -1, .y = -1};
	if (!tiles || ft_origin(size))
		return ;
	*tiles = (t_tile **)malloc(sizeof(t_tile *) * size.y);
	if (!(*tiles))
		return ;
	while (++iter.y < size.y)
	{
		(*tiles)[iter.y] = (t_tile *)malloc(sizeof(t_tile) * size.x);
		if (!(*tiles)[iter.y])
		{
			free_tiles(tiles, iter.y);
			return ;
		}
		iter.x = -1;
		while (++iter.x < size.x)
			(*tiles)[iter.y][iter.x] = (t_tile){.color = 0, .crd = (t_point){0, 0},
				.up = NULL, .down = NULL, .right = NULL, .left = NULL};
	}
}
