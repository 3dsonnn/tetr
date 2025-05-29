/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   next.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efinda <efinda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 20:33:45 by efinda            #+#    #+#             */
/*   Updated: 2025/05/28 11:22:43 by efinda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/tetr.h"

void    fill_next_box(t_tetr *tetr, t_plane size)
{
    int     i;
    int     step_y;
    int     start_y;

    i = -1;
    start_y = size.y0;
    step_y = (TILE * 2) + (TILE / 2);
    while (++i < 5)
    {
        size.y0 = start_y + step_y * i;
        size.y = size.y0 + step_y;
        put_piece(tetr->next_stack[i], size, &tetr->main_img);
    }
}

void    move_next_box(t_tetr *tetr)
{
    int i;

    i = -1;
    clean_box(tetr, &tetr->main_img, tetr->background_img, tetr->next_box_size);
    while (++i < 4)
        tetr->next_stack[i] = tetr->next_stack[i + 1];
    tetr->next_stack[i] = get_random_piece();
    fill_next_box(tetr, tetr->next_box_size);
}
