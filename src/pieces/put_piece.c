/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_piece.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efinda <efinda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 21:07:29 by efinda            #+#    #+#             */
/*   Updated: 2025/05/27 13:42:52 by efinda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/tetr.h"

static  t_point get_padded_start(t_plane size, t_point lil)
{
    t_point res;
    t_point range;
    t_point center;

    range = (t_point){size.x - size.x0, size.y - size.y0};
    center = ft_center_range(range, lil);
    res = (t_point){.x = size.x0 + center.x, .y = size.y0 + center.y};
    return (res);
}

void    put_piece(t_piece ref, t_plane size, t_img *img)
{
    t_tile  tile;

    tile = (t_tile){.color = ref.color, .crd = {0, 0},
        .up = NULL, .down = NULL, .right = NULL, .left = NULL};
    if (ref.id == SQUARE)
        square(get_padded_start(size, (t_point){(TILE * 2), (TILE * 2)}), &tile, img);
    else if (ref.id == L_MIRRORED)
        l_mirrored(get_padded_start(size, (t_point){(TILE * 3), (TILE * 2)}), &tile, img);
    else if (ref.id == L_SHAPE)
        l_shape(get_padded_start(size, (t_point){(TILE * 3), (TILE * 2)}), &tile, img);
    else if (ref.id == TILTED_Z)
        tilted_z(get_padded_start(size, (t_point){(TILE * 3), (TILE * 2)}), &tile, img);
    else if (ref.id == TILTED_S)
        tilted_s(get_padded_start(size, (t_point){(TILE * 3), (TILE * 2)}), &tile, img);
    else if (ref.id == STRAIGHT)
        straight(get_padded_start(size, (t_point){(TILE * 4), TILE}), &tile, img);
    else if (ref.id == T_SHAPE)
        t_shape(get_padded_start(size, (t_point){(TILE * 3), (TILE * 2)}), &tile, img);
}
