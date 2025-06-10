/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_scenario.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efinda <efinda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 13:21:41 by efinda            #+#    #+#             */
/*   Updated: 2025/06/10 10:01:24 by efinda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/tetr.h"

void    update_scenario(t_tetr *tetr)
{
    int         step;
    const int   half_size = (tetr->time_box_size.x - tetr->time_box_size.x0) / 2;

    step = half_size - ((ft_strlen(tetr->cur_time) * 7) / 2);
    mlx_put_image_to_window(tetr->mlx, tetr->win, tetr->img.img, 0, 0);
    mlx_string_put(tetr->mlx, tetr->win, tetr->hold_box_size.x0 + (TILE * 2), tetr->hold_box_size.y0 - (TILE / 2.5), BLACK, "");
    mlx_string_put(tetr->mlx, tetr->win, tetr->hold_box_size.x0 + (TILE * 2), tetr->hold_box_size.y0 - (TILE / 2.5), BLACK, "HOLD");
	mlx_string_put(tetr->mlx, tetr->win, tetr->next_box_size.x0 + (TILE * 2), tetr->next_box_size.y0 - (TILE / 2.5), BLACK, "NEXT");
    mlx_string_put(tetr->mlx, tetr->win, tetr->time_box_size.x0 + (TILE * 2), tetr->time_box_size.y0 - (TILE / 2.5), BLACK, "TIME");
    mlx_string_put(tetr->mlx, tetr->win, tetr->time_box_size.x0 + step, tetr->time_box_size.y0 + (TILE / 1.5), BLACK, tetr->cur_time);
    ft_strfree(&tetr->cur_time);
}
