/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efinda <efinda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/14 22:41:08 by efinda            #+#    #+#             */
/*   Updated: 2025/06/16 18:00:48 by efinda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tetr.h"

bool	object_will_collide( t_tetr *tetr )
{
	t_piece	*curr_piece;
	t_point	pos;

	curr_piece = &tetr->cur;
	for (int i = 0; i < 4; i++)
	{
		pos = curr_piece->coords[i];
		if (tetr->tiles[pos.y][pos.x].color)
			return (true);
	}
	return (false);
}

static void	fix_limits( t_point *coords, t_point lowest, t_point greatest )
{
	if (lowest.x < 0)
		for (int i = 0; i < 4; i++)
			coords[i].x += -lowest.x;
	else if (greatest.x >= TOTAL_TILE_X)
		for (int i = 0; i < 4; i++)
			coords[i].x -= lowest.x - TOTAL_TILE_X + 1;

	if (lowest.y < 0)
		for (int i = 0; i < 4; i++)
			coords[i].y += -lowest.y;
	else if (greatest.y >= TOTAL_TILE_Y)
		for (int i = 0; i < 4; i++)
			coords[i].y -= lowest.y - TOTAL_TILE_Y + 1;
}

static void	apply_rotation( t_piece *piece )
{
	t_point	*coords;
	t_point	lowest;
	t_point	greatest;

	coords = piece->coords;
	lowest = (t_point){42, 42};
	greatest = (t_point){-42, -42};
	for (int i = 0; i < 4; i++)
	{
		coords[i] = (t_point){-coords[i].y, coords[i].x};
		if (piece->mod)
			coords[i].x--;
		else
			coords[i].x++;

		if (coords[i].x < lowest.x)
			lowest.x = coords[i].x;
		else if (coords[i].x > greatest.x)
			greatest.x = coords[i].x;

		if (coords[i].y < lowest.y)
			lowest.y = coords[i].y;
		else if (coords[i].y > greatest.y)
			greatest.y = coords[i].y;
	}
	ft_printf("-----------------LIMITS---------------------------\n");
	for (int i = 0; i < 4; i++)
		ft_printf("x: %d | y: %d\n", coords[i].x, coords[i].y);
	ft_printf("----------------------------------------------------\n");
	fix_limits( coords, lowest, greatest );
	piece->mod = !piece->mod;
}

void	rotate_piece( t_tetr *tetr )
{
	t_piece		*cur;
	t_point		copy[4];

	cur = &tetr->cur;
	ft_printf("-------------------START--------------------------\n");
	for (int i = 0; i < 4; i++)
		ft_printf("x: %d | y: %d\n", cur->coords[i].x, cur->coords[i].y);
	ft_printf("----------------------------------------------------\n");
	ft_memcpy(copy, cur->coords, sizeof(t_point) * 4);
	render_piece(tetr, false);
	apply_rotation( cur );
	if (object_will_collide( tetr ))
	{
		cur->mod = !cur->mod;
		ft_memcpy(cur->coords, copy, sizeof(t_point) * 4);
	}
	ft_printf("-----------------END--------------------------\n");
	for (int i = 0; i < 4; i++)
		ft_printf("x: %d | y: %d\n", cur->coords[i].x, cur->coords[i].y);
	ft_printf("----------------------------------------------------\n");
	render_piece(tetr, true);
}
