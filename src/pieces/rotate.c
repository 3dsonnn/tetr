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
			coords[i].x -= greatest.x - TOTAL_TILE_X + 1;

	if (lowest.y < 0)
		for (int i = 0; i < 4; i++)
			coords[i].y += -lowest.y;
	else if (greatest.y >= TOTAL_TILE_Y)
		for (int i = 0; i < 4; i++)
			coords[i].y -= greatest.y - TOTAL_TILE_Y + 1;
}

static void	apply_rotation( t_piece *piece, t_point center )
{
	t_point	*coords;
	t_point	lowest;
	t_point	greatest;

	coords = piece->coords;
	lowest = (t_point){42, 42};
	greatest = (t_point){-42, -42};
	for (int i = 0; i < 4; i++)
	{
		//Fazer Coords[x] - Center, ou seja subtrair centro de todas as coordenadas
		coords[i] = (t_point){coords[i].x - center.x, coords[i].y - center.y};
		//Aplicar a regra para rotacionar horário (x, y) = (-y, x)
		coords[i] = (t_point){-coords[i].y, coords[i].x};
		//Depois disso voltar a somar o resultado com o centro
		coords[i] = (t_point){coords[i].x + center.x, coords[i].y + center.y};

		if (coords[i].x < lowest.x)
			lowest.x = coords[i].x;
		else if (coords[i].x > greatest.x)
			greatest.x = coords[i].x;

		if (coords[i].y < lowest.y)
			lowest.y = coords[i].y;
		else if (coords[i].y > greatest.y)
			greatest.y = coords[i].y;
	}
	fix_limits( coords, lowest, greatest );
}

void	rotate_piece( t_tetr *tetr )
{
	t_piece		*cur;
	t_point		copy[4];

	cur = &tetr->cur;
	if (cur->type == SQUARE)
		return ;
	ft_memcpy(copy, cur->coords, sizeof(t_point) * 4);
	render_piece(tetr, 0);
	apply_rotation( cur, copy[1 + (cur->type == STRAIGHT)] );
	if (object_will_collide( tetr ))
		ft_memcpy(cur->coords, copy, sizeof(t_point) * 4);
	render_piece(tetr, 1);
}
