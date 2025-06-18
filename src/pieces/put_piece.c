/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_piece.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efinda <efinda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 21:07:29 by efinda            #+#    #+#             */
/*   Updated: 2025/06/14 21:02:33 by efinda           ###   ########.fr       */
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
    if (ref.type == SQUARE)
        square(get_padded_start(size, (t_point){(TILE * 2), (TILE * 2)}), ref.color, img);
    else if (ref.type == L_MIRRORED)
        l_mirrored(get_padded_start(size, (t_point){(TILE * 3), (TILE * 2)}), ref.color, img);
    else if (ref.type == L_SHAPE)
        l_shape(get_padded_start(size, (t_point){(TILE * 3), (TILE * 2)}), ref.color, img);
    else if (ref.type == TILTED_Z)
        tilted_z(get_padded_start(size, (t_point){(TILE * 3), (TILE * 2)}), ref.color, img);
    else if (ref.type == TILTED_S)
        tilted_s(get_padded_start(size, (t_point){(TILE * 3), (TILE * 2)}), ref.color, img);
    else if (ref.type == STRAIGHT)
        straight(get_padded_start(size, (t_point){(TILE * 4), TILE}), ref.color, img);
    else if (ref.type == T_SHAPE)
        t_shape(get_padded_start(size, (t_point){(TILE * 3), (TILE * 2)}), ref.color, img);
}
