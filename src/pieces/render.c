/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efinda <efinda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/14 23:47:42 by efinda            #+#    #+#             */
/*   Updated: 2025/06/17 14:17:17 by efinda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tetr.h"

int	render_piece( t_tetr *tetr, int renderize )
{
	t_piece	*curr_piece;
	t_tile	*tile;
	t_point	hollow[4];
	t_point	pos;
	int	deep;

	curr_piece = &tetr->cur;
	for (int i = 0; i < 4; i++)
	{
		pos = curr_piece->coords[i];
		tile = &tetr->tiles[pos.y][pos.x];
		if (renderize)
		{
			tile->color = curr_piece->color;
			paint_tile( tile, &tetr->img );
		}
		else
		{
			clean_piece_tile( tetr, tile );
			return (1);
		}
	}
	if (i > 0)
	{
		get_limits( curr_piece->coords, NULL, NULL, &pos, NULL );
		for (int i = 0; i < 4; i++)
			hollow[i] = curr_piece->coords[i];
		while ()
		{
			for (int i = 0; i < 4 && hollo; i++)
				hollow[i].y++;
			{
				hollow[i].y++;
				if (hollow[i].y > pos.y && hollow[i].y < TOTAL_TILE_Y)
				{
					if (tetr->tiles[hollow[i].y][hollow[i].x].color)
					{
						while (i >= 0)
							hollow[i].y--;
						break ;
					}
					else if (hollow[i].y == TOTAL_TILE_Y - 1)
						break ;
				}
			}
		}
	}
	
	return (1);
}
