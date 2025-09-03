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

int	render_piece( t_tetr *tetr, bool renderize )
{
	t_piece	*curr_piece;
	t_tile	*tile;
	t_point	pos;

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
			clean_piece_tile( tetr, tile );
	}
	return (1);
}
