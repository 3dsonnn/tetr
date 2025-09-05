/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efinda <efinda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 11:32:21 by efinda            #+#    #+#             */
/*   Updated: 2025/06/18 09:57:07 by efinda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tetr.h"

void	get_piece_limits( t_point *coords, t_point *great_x, t_point *great_y, t_point *low_x,
	t_point *low_y )
{
	t_point	greatest;
	t_point	lowest;

	lowest = (t_point){42, 42};
	greatest = (t_point){-42, -42};
	for (int i = 0; i < 4; i++)
	{
		if (low_x && coords[i].x < lowest.x)
		{
			lowest.x = coords[i].x;
			*low_x = coords[i];
		}
		if (low_y && coords[i].y < lowest.y)
		{
			lowest.y = coords[i].y;
			*low_y = coords[i];
		}
	 	if (great_x && coords[i].x > greatest.x)
	 	{
			greatest.x = coords[i].x;
			*great_x = coords[i];
		}
		if (great_y && coords[i].y > greatest.y)
		{
			greatest.y = coords[i].y;
			*great_y = coords[i];
		}
	}
}

void    move_piece(t_tetr *tetr, int keycode)
{
	t_piece	*piece;
	t_point	great_x;
	t_point	low_x;
	char	step;

	piece = &tetr->cur;
	if (keycode == LEFT)
		step = -1;
	else
		step = 1;
	get_piece_limits( piece->coords, &great_x, NULL, &low_x, NULL );
	if (step > 0)
	{
		if (great_x.x == TOTAL_TILE_X - 1 || tetr->tiles[great_x.y][great_x.x + 1].color)
			return ;
	}
	else
	{
		if (low_x.x == 0 || tetr->tiles[low_x.y][low_x.x - 1].color)
			return ;
	}
	render_piece(tetr, 0);
	for (int i = 0; i < 4; i++)
		piece->coords[i].x += step;
	render_piece(tetr, 1);
}


void	fall_piece(t_tetr *tetr)
{
	t_piece	*piece;
	t_point	great_y;

	piece = &tetr->cur;
	get_piece_limits( piece->coords, NULL, &great_y, NULL, NULL );
	if (great_y.y == TOTAL_TILE_Y - 1)
	{
		update_piece(tetr);
		return ;
	}
	render_piece(tetr, 0);
	for (int i = 0; i < 4; i++)
		piece->coords[i].y++;
	if (object_will_collide( tetr ))
	{
		for (int i = 0; i < 4; i++)
			piece->coords[i].y--;
		render_piece(tetr, 1);
		update_piece(tetr);
		return ;
	}
	render_piece(tetr, 1);
}
