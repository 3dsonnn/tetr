/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   paint.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efinda <efinda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 07:47:36 by efinda            #+#    #+#             */
/*   Updated: 2025/05/26 07:52:40 by efinda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/tetr.h"

void    paint_tile(t_tile *tile, t_img *img)
{
    t_point iter;

    if (!tile)
        return ;
    iter = (t_point){.x = -1, .y = -1};
    while (++iter.y < TILE - 1)
    {
        iter.x = -1;
        while (++iter.x < TILE - 1)
            my_mlx_pixel_put(img, tile->crd.x + iter.x, tile->crd.y + iter.y, tile->color);
    }
}
