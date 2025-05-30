/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shared.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efinda <efinda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 10:56:49 by efinda            #+#    #+#             */
/*   Updated: 2025/05/30 09:21:41 by efinda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/tetr.h"

void    clean_box(t_img *main_img, t_img background_img, t_plane size)
{
    my_mlx_put_img_to_img((t_img_to_img){
        .dst = main_img,
        .src = background_img,
        .aux = NULL,
        .dst_point = (t_point){.x = size.x0, .y = size.y0},
        .src_point = (t_point){.x = size.x0, .y = size.y0},
        .size = (t_point){.x = size.x - size.x0, .y = size.y - size.y0},
        .filter = 0,
        .skip = 0,
        .color_aux = 0
    });
}
