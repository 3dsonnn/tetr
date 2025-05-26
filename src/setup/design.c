/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   design.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efinda <efinda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/25 19:53:48 by efinda            #+#    #+#             */
/*   Updated: 2025/05/26 18:47:40 by efinda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/tetr.h"

void	design_tiles_divisions(t_img *background, t_tile **tiles)
{
	t_point	iter;
	t_tile	*tmp;

	iter = (t_point){0, 0};
    while (++iter.x < TOTAL_TILE_X)
	{
        tmp = &tiles[0][iter.x];
		my_mlx_draw_line_to_img(background, (t_point){tmp->crd.x - 1, tmp->crd.y}, (t_point){1, ((TOTAL_TILE_Y * TILE) + TOTAL_TILE_Y)}, WHITE);
	}
    while (++iter.y < TOTAL_TILE_Y)
	{
        tmp = &tiles[iter.y][0];
		my_mlx_draw_line_to_img(background, (t_point){tmp->crd.x, tmp->crd.y - 1}, (t_point){(TOTAL_TILE_X * TILE) + TOTAL_TILE_X, 1}, WHITE);
	}
}

void	design_border(t_img *background_img, t_tile **tiles)
{
    t_tile  *first;
    int     line_thickness;

    first = *tiles;
    line_thickness = 3;
    my_mlx_draw_line_to_img(background_img,
        (t_point){first->crd.x - line_thickness, first->crd.y},
        (t_point){line_thickness, ((TOTAL_TILE_Y * TILE) + TOTAL_TILE_Y + line_thickness)}, WHITE);
    my_mlx_draw_line_to_img(background_img,
        (t_point){first->crd.x + (TOTAL_TILE_X * TILE) + TOTAL_TILE_X, first->crd.y},
        (t_point){line_thickness, ((TOTAL_TILE_Y * TILE) + TOTAL_TILE_Y + line_thickness)}, WHITE);
    my_mlx_draw_line_to_img(background_img,
        (t_point){first->crd.x, first->crd.y + ((TOTAL_TILE_Y * TILE) + TOTAL_TILE_Y)},
        (t_point){((TOTAL_TILE_X * TILE) + TOTAL_TILE_X), line_thickness}, WHITE);
}

void	design_hold_box(t_img *background_img, t_tile **tiles, t_point *hold_box_crd)
{
    t_tile  *first;
    int     line_thickness;

    first = *tiles;
    line_thickness = 3;
	hold_box_crd->y = first->crd.y + TILE;
    hold_box_crd->x = first->crd.x - (line_thickness + (TILE * 5));
    my_mlx_draw_line_to_img(background_img,
        (t_point){hold_box_crd->x - line_thickness, hold_box_crd->y - TILE},
        (t_point){(TILE * 5) + line_thickness, TILE}, WHITE);
    my_mlx_draw_line_to_img(background_img,
        (t_point){hold_box_crd->x - line_thickness, hold_box_crd->y},
        (t_point){line_thickness, (TILE * 3)}, WHITE);
    my_mlx_draw_line_to_img(background_img,
        (t_point){hold_box_crd->x - line_thickness, hold_box_crd->y + (TILE * 3)},
        (t_point){(TILE * 5) + line_thickness, line_thickness}, WHITE);
}

void    design_imbroglio_bar(t_img *background_img, t_tile **tiles, t_plane *imbroglio_bar)
{
    t_tile  *last;
    t_tile  *last_on_line;
    int     width;
    int     line_thickness;

    line_thickness = 3;
    width = (int)floor(TILE / 2);
    last_on_line = &tiles[0][TOTAL_TILE_X - 1];
    last = &tiles[TOTAL_TILE_Y - 1][TOTAL_TILE_X - 1];
    my_mlx_draw_line_to_img(background_img,
        (t_point){last->crd.x + TILE + line_thickness, last->crd.y + TILE + 1},
        (t_point){width, line_thickness}, WHITE);
    my_mlx_draw_line_to_img(background_img,
        (t_point){last_on_line->crd.x + TILE + line_thickness + width, last_on_line->crd.y},
        (t_point){line_thickness, ((TOTAL_TILE_Y * TILE) + TOTAL_TILE_Y + line_thickness)}, WHITE);
    imbroglio_bar->x0 = last_on_line->crd.x + TILE + line_thickness + 1;
    imbroglio_bar->x = imbroglio_bar->x0 + width - 1;
    imbroglio_bar->y0 = last_on_line->crd.y;
    imbroglio_bar->y = imbroglio_bar->y0 + (TOTAL_TILE_Y * TILE) + TOTAL_TILE_Y;
}

void	design_next_box(t_img *background_img, t_tile **tiles, t_point *next_box_crd, t_point start)
{
    t_tile  *last_on_line;
    int     line_thickness;

    line_thickness = 3;
    next_box_crd->x = start.x;
    next_box_crd->y = start.y + TILE;
    last_on_line = &tiles[0][TOTAL_TILE_X - 1];
	my_mlx_draw_line_to_img(background_img,
        (t_point){start.x, start.y},
        (t_point){(TILE * 5), TILE}, WHITE);
    my_mlx_draw_line_to_img(background_img,
        (t_point){next_box_crd->x, next_box_crd->y + (TILE * 13)},
        (t_point){(TILE * 5), line_thickness}, WHITE);
    my_mlx_draw_line_to_img(background_img,
        (t_point){start.x + (TILE * 5), start.y},
        (t_point){line_thickness, (TILE * 14) + line_thickness}, WHITE);
}
