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

static void	rotate_design(t_piece *piece)
{
	Shape	old;
	t_point	iter;
	int		limit;
	int		reverse_index;

	if (!piece || piece->type == SQUARE)
		return ;
    limit = ft_max_point(piece->mtxlen);
    mtxcpy(piece->design, old, limit);
	iter.y = -1;
    piece->mtxstart = (t_point){TOTAL_TILE_X, TOTAL_TILE_Y};
	while (++iter.y < limit)
	{
		iter.x = -1;
		while (++iter.x < limit)
		{
			reverse_index = limit - iter.y - 1;
			piece->design[iter.x][reverse_index] = old[iter.y][iter.x];
			if (old[iter.y][iter.x] == '1' && reverse_index < piece->mtxstart.x)
				piece->mtxstart.x = reverse_index;
			if (old[iter.y][iter.x] == '1' && iter.x < piece->mtxstart.y)
				piece->mtxstart.y = iter.x;
		}
	}
	ft_swap_point(&piece->mtxlen);
}

void	rotate_piece(t_tetr *tetr, t_piece *piece)
{
    t_piece cur;

    cur = tetr->cur;
    render_piece(tetr, 0, clean_piece_tile);
    rotate_design(piece);
    //Se o objecto está na parede esquerda e a sua rotação poderá faze-lo ir alem da parede
    if (!piece->start_index.x && piece->iterator.x)
        piece->iterator.x = 0;
    else if (piece->start_index.x + ft_max_point(piece->mtxlen) >= TOTAL_TILE_X)
    {
        piece->start_index.x -= piece->reverse.x;
        piece->reverse.x = 0;
    }
    if (!render_piece(tetr, 1, paint_piece_tile))
    {
        tetr->cur = cur;
        render_piece(tetr, 1, paint_piece_tile);
    }
}
