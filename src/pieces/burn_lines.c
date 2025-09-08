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
    for (int i = 0; i < TOTAL_TILE_X; i++)
    {
        if (flag && !ref[i].color)
            return (0);
        else if (!flag && ref[i].color)
            return (0);
    }
    return (1);
}

static void	drop_off_line( t_tetr *tetr, t_tile *top, t_tile *down )
{
	if (!top || !down)
		return ;
	for (int i = 0; i < TOTAL_TILE_X; i++)
	{
		down[i].color = top[i].color;
		if (down[i].color)
			paint_tile(down + i, &tetr->img);
		else
			clean_piece_tile(tetr, down + i);
	}
}

void	burn_lines(t_tetr *tetr)
{
	t_point	iter;
	t_point low_y;
	t_tile	*tmp;

	get_piece_limits( tetr->cur.coords, NULL, &iter, NULL, &low_y );
	iter.x = ++iter.y;
	while (--iter.y >= low_y.y)
	{
		if (line_state(tetr->tiles[iter.y], 1))
		{
			tmp = tetr->tiles[iter.y];
			for (int i = 0; i < TOTAL_TILE_X; i++)
				clean_piece_tile(tetr, tmp + i);
			while (--iter.y)
				drop_off_line(tetr, tetr->tiles[iter.y], tetr->tiles[iter.y + 1]);
			iter.y = iter.x; //iter.x is used as a tmp var to store de iter.y
		}
	}
}
