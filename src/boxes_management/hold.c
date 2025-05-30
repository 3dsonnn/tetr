/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hold.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efinda <efinda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 20:34:44 by efinda            #+#    #+#             */
/*   Updated: 2025/05/30 09:22:01 by efinda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/tetr.h"

static  void    first_time_holding(t_tetr *tetr, t_piece *holded_piece)
{
    *holded_piece = tetr->cur;
    holded_piece->color = GRAY;
    put_piece(*holded_piece, tetr->hold_box_size, &tetr->main_img);
    holded_piece->color = tetr->cur.color;
    update_piece(tetr);
    tetr->hold_toggle = 0;
}

void	hold_piece(t_tetr *tetr, int flag)
{
	static t_piece	holded_piece;
    t_piece         tmp;

    if (tetr->hold_toggle == -1)
        first_time_holding(tetr, &holded_piece);
    else if (flag)
    {
        clean_box(&tetr->main_img, tetr->background_img, tetr->hold_box_size);
        put_piece(holded_piece, tetr->hold_box_size, &tetr->main_img);
        tetr->hold_toggle = 1;
    }
    else if (tetr->hold_toggle == 1)
    {
        tmp = holded_piece;
        holded_piece = tetr->cur;
        holded_piece.color = GRAY;
        clean_box(&tetr->main_img, tetr->background_img, tetr->hold_box_size);
        put_piece(holded_piece, tetr->hold_box_size, &tetr->main_img);
        holded_piece.color = tetr->cur.color;
        tetr->cur = tmp;
        tetr->hold_toggle = 0;
    }
}
