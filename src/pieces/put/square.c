/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   square.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efinda <efinda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 13:11:50 by efinda            #+#    #+#             */
/*   Updated: 2025/05/27 13:34:15 by efinda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/tetr.h"

void    square(t_point start, t_tile *tile, t_img *img)
{
    tile->crd = start;
    paint_tile(tile, img);
    tile->crd.x += TILE;
    paint_tile(tile, img);
    tile->crd = (t_point){.x = tile->crd.x - TILE, .y = tile->crd.y + TILE};
    paint_tile(tile, img);
    tile->crd.x += TILE;
    paint_tile(tile, img);
    // Horizontal lines
    my_mlx_draw_line_to_img(img, (t_point){start.x, start.y}, (t_point){TILE * 2, 1}, WHITE);
    my_mlx_draw_line_to_img(img, (t_point){start.x, start.y + TILE}, (t_point){TILE * 2, 1}, WHITE);
    my_mlx_draw_line_to_img(img, (t_point){start.x, start.y + (TILE * 2)}, (t_point){(TILE * 2) + 1, 1}, WHITE);
    // Vertical lines
    my_mlx_draw_line_to_img(img, (t_point){start.x, start.y}, (t_point){1, TILE * 2}, WHITE);
    my_mlx_draw_line_to_img(img, (t_point){start.x + TILE, start.y}, (t_point){1, TILE * 2}, WHITE);
    my_mlx_draw_line_to_img(img, (t_point){start.x + (TILE * 2), start.y}, (t_point){1, TILE * 2}, WHITE);
}
