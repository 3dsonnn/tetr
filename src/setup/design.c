/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   design.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efinda <efinda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/25 19:53:48 by efinda            #+#    #+#             */
/*   Updated: 2025/05/26 08:19:18 by efinda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/tetr.h"

void	design_tiles_divisions(t_img *background, t_tile **tiles)
{
	t_point	iter;
	t_tile	*tmp;

	iter = (t_point){-1, -1};
	while (++iter.y < TOTAL_TILE_Y)
	{
		iter.x = -1;
		while (++iter.x < TOTAL_TILE_X)
		{
			tmp = &tiles[iter.y][iter.x];
			my_mlx_draw_line_to_img(background, (t_point){tmp->crd.x - 1, tmp->crd.y - 1}, (t_point){1, TILE}, WHITE);
			if (iter.y)
			    my_mlx_draw_line_to_img(background, (t_point){tmp->crd.x - 1, tmp->crd.y - 1}, (t_point){TILE, 1}, WHITE);
            if (iter.x + 1 == TOTAL_TILE_X)
				my_mlx_draw_line_to_img(background, (t_point){tmp->crd.x - 1 + TILE, tmp->crd.y - 1}, (t_point){1, TILE}, WHITE);
			if (iter.y + 1 == TOTAL_TILE_Y)
				my_mlx_draw_line_to_img(background, (t_point){tmp->crd.x - 1, tmp->crd.y - 1 + TILE}, (t_point){TILE, 1}, WHITE);
		}
	}
}

void	design_hold_tile_box(t_img *background_img, t_tile **tiles)
{
    t_tile  *first;
    int     line_thickness;

    first = *tiles;
    line_thickness = 3;
	my_mlx_draw_line_to_img(background_img,
        (t_point){first->crd.x - ((TILE * 5) + (line_thickness * 2)), first->crd.y - 1},
        (t_point){(TILE * 5) + (line_thickness * 2), TILE}, WHITE);
    my_mlx_draw_line_to_img(background_img,
        (t_point){first->crd.x - ((TILE * 5) + (line_thickness * 2)), first->crd.y - 1},
        (t_point){line_thickness, (TILE * 4)}, WHITE);
    my_mlx_draw_line_to_img(background_img,
        (t_point){first->crd.x - ((TILE * 5) + (line_thickness * 2)), (first->crd.y - 2) + (TILE * 4)},
        (t_point){((TILE * 5) + (line_thickness * 2)), line_thickness}, WHITE);
    my_mlx_draw_line_to_img(background_img,
        (t_point){first->crd.x - line_thickness, first->crd.y},
        (t_point){line_thickness, (TILE * TOTAL_TILE_Y)}, WHITE);
    my_mlx_draw_line_to_img(background_img,
        (t_point){first->crd.x + (TILE * TOTAL_TILE_X), first->crd.y - 1},
        (t_point){line_thickness, ((TILE * TOTAL_TILE_Y) + 1)}, WHITE);
    my_mlx_draw_line_to_img(background_img,
        (t_point){first->crd.x - line_thickness, (first->crd.y - 1) + (TILE * TOTAL_TILE_Y)},
        (t_point){(TILE * TOTAL_TILE_X) + (line_thickness * 2), line_thickness}, WHITE);
}

void	design_next_tile_box(t_img *background_img, t_tile **tiles)
{
    t_tile  *last;
    int     line_thickness;

    line_thickness = 3;
    last = &tiles[TOTAL_TILE_X - 1][TOTAL_TILE_Y - 1];
	my_mlx_draw_line_to_img(background_img,
        (t_point){last->crd.x, last->crd.y + (TILE * TOTAL_TILE_Y)},
        (t_point){(TILE / 2), line_thickness}, WHITE);
    // my_mlx_draw_line_to_img(background_img,
    //     (t_point){first->crd.x - ((TILE * 5) + (line_thickness * 2)), first->crd.y - 1},
    //     (t_point){line_thickness, (TILE * 4)}, WHITE);
    // my_mlx_draw_line_to_img(background_img,
    //     (t_point){first->crd.x - ((TILE * 5) + (line_thickness * 2)), (first->crd.y - 2) + (TILE * 4)},
    //     (t_point){((TILE * 5) + (line_thickness * 2)), line_thickness}, WHITE);
    // my_mlx_draw_line_to_img(background_img,
    //     (t_point){first->crd.x - line_thickness, first->crd.y},
    //     (t_point){line_thickness, (TILE * TOTAL_TILE_Y)}, WHITE);
    // my_mlx_draw_line_to_img(background_img,
    //     (t_point){first->crd.x + (TILE * TOTAL_TILE_X), first->crd.y - 1},
    //     (t_point){line_thickness, ((TILE * TOTAL_TILE_Y) + 1)}, WHITE);
    // my_mlx_draw_line_to_img(background_img,
    //     (t_point){first->crd.x - line_thickness, (first->crd.y - 1) + (TILE * TOTAL_TILE_Y)},
    //     (t_point){(TILE * TOTAL_TILE_X) + (line_thickness * 2), line_thickness}, WHITE);
}
