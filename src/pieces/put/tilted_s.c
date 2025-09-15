/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tilted_s.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efinda <efinda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 13:15:12 by efinda            #+#    #+#             */
/*   Updated: 2025/06/16 18:33:37 by efinda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/tetr.h"

void    tilted_s(t_point start, unsigned int color, t_img *img)
{
    t_tile  tile;

    tile = (t_tile){.color = color, .crd = start};
    tile.crd.y += TILE;
    paint_tile(&tile, img, true);
    tile.crd.x += TILE;
    paint_tile(&tile, img, true);
    tile.crd.y -= TILE;
    paint_tile(&tile, img, true);
    tile.crd.x += TILE;
    paint_tile(&tile, img, true);
    // Horizontal lines
    my_mlx_draw_line_to_img(img, (t_point){start.x + TILE, start.y}, (t_point){(TILE * 2), 1}, WHITE);
    my_mlx_draw_line_to_img(img, (t_point){start.x, start.y + TILE}, (t_point){(TILE * 3), 1}, WHITE);
    my_mlx_draw_line_to_img(img, (t_point){start.x, start.y + (TILE * 2)}, (t_point){(TILE * 2) + 1, 1}, WHITE);
    // Vertical lines
    my_mlx_draw_line_to_img(img, (t_point){start.x, start.y + TILE}, (t_point){1, TILE}, WHITE);
    my_mlx_draw_line_to_img(img, (t_point){start.x + TILE, start.y}, (t_point){1, (2 * TILE)}, WHITE);
    my_mlx_draw_line_to_img(img, (t_point){start.x + (TILE * 2), start.y}, (t_point){1, (2 * TILE)}, WHITE);
    my_mlx_draw_line_to_img(img, (t_point){start.x + (TILE * 3), start.y}, (t_point){1, TILE}, WHITE);
}
