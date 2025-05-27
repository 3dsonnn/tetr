/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   next.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efinda <efinda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 20:33:45 by efinda            #+#    #+#             */
/*   Updated: 2025/05/27 13:43:18 by efinda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/tetr.h"

void    fill_next_box(t_tetr *tetr, t_img *main_img, t_plane size)
{
    int     iter;
    int     vertical_step;
    int     base_y0;

    iter = -1;
    base_y0 = size.y0;
    vertical_step = (TILE * 2) + (TILE / 2);
    while (++iter < 5)
    {
        size.y0 = base_y0 + vertical_step * iter;
        size.y = size.y0 + vertical_step;
        put_piece(get_random_piece(), size, main_img);
    }
}
