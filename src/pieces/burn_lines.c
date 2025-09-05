/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   burn_lines.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efinda <efinda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 13:16:18 by efinda            #+#    #+#             */
/*   Updated: 2025/06/18 09:17:25 by efinda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tetr.h"

static  int line_state(t_tile *ref, int flag)
{
    if (!ref)
        return (0);
    while (ref)
    {
        if (flag && !ref->color)
            return (0);
        else if (!flag && ref->color)
            return (0);
        ref = ref->right;
    }
    return (1);
}

static void drop_off_line(t_tetr *tetr, t_tile *top, t_tile *down)
{
    while (top && down)
    {
        down->color = top->color;
        if (down->color)
            paint_tile(down, &tetr->img);
        else
            clean_piece_tile(tetr, down);
        top = top->right;
        down = down->right;
    }
}

void	burn_lines(t_tetr *tetr)
{
    t_point iter;
    t_tile  *tmp;

	iter.y = TOTAL_TILE_Y;
	while (--iter.y >= 0)
	{
        if (line_state(tetr->tiles[iter.y], 1))
        {
            tmp = tetr->tiles[iter.y];
            while (tmp)
            {
                clean_piece_tile(tetr, tmp);
                tmp = tmp->right;
            }
            while (iter.y)
            {
                drop_off_line(tetr, tetr->tiles[iter.y - 1], tetr->tiles[iter.y]);
                iter.y--;
            }
            iter.y = TOTAL_TILE_Y;
        }
	}
}
