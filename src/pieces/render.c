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

static bool	point_on_coords( t_point *piece_coords, t_point to_check )
{
	for (int i = 0; i < 4; i++)
		if (to_check.y == piece_coords[i].y && to_check.x == piece_coords[i].x)
			return (true);
	return (false);
}

static void	draw_hollow( int i, t_point *hollow, t_tetr *tetr )
{
	t_tile		*tile;

	while (i >= 0)
		hollow[i--].y--;
	for (i = 0; i < 4; i++)
	{
		if (!point_on_coords( tetr->cur.coords, hollow[i] ))
		{
			tile = &tetr->tiles[hollow[i].y][hollow[i].x];
			tile->color = GRAY; //Cinzento
			paint_tile(tile, &tetr->img );
			tile->color = 0;
		}
	}
}

static void	render_hollow_piece( t_tetr *tetr, bool clean_hollow )
{
	static t_point	great_y;
	t_point		*hollow;
	int		i;

	hollow = tetr->cur.hollow;
	if (clean_hollow)
	{
		for (i = 0; i < 4; i++)
			if (hollow[i].y > great_y.y)
				clean_piece_tile( tetr, &tetr->tiles[hollow[i].y][hollow[i].x] );
	}
	else
	{
		get_piece_limits( tetr->cur.coords, NULL, &great_y, NULL, NULL );
		if (great_y.y == TOTAL_TILE_Y - 1)
			return ;
		for (i = 0; i < 4; i++)
			hollow[i] = tetr->cur.coords[i];
		i = 0;
		while (++hollow[i].y <= TOTAL_TILE_Y)
		{
			if (hollow[i].y == TOTAL_TILE_Y || (tetr->tiles[hollow[i].y][hollow[i].x].color && !point_on_coords( tetr->cur.coords, hollow[i] )))
			{
				draw_hollow(i, hollow, tetr);
				return ;
			}
			i = (i + 1) % 4;
		}
	}
}

int	render_piece( t_tetr *tetr, bool renderize )
{
	t_piece	*curr_piece;
	t_tile	*tile;

	curr_piece = &tetr->cur;
	for (int i = 0; i < 4; i++)
	{
		tile = &tetr->tiles[curr_piece->coords[i].y][curr_piece->coords[i].x];
		if (renderize)
		{
			tile->color = curr_piece->color;
			paint_tile( tile, &tetr->img );
		}
		else
			clean_piece_tile( tetr, tile );
	}
	render_hollow_piece( tetr, !renderize );
	return (1);
}
