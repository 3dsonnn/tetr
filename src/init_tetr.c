/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_tetr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efinda <efinda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/24 12:09:47 by efinda            #+#    #+#             */
/*   Updated: 2025/05/29 15:05:21 by efinda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/tetr.h"

void    init_tetr(t_tetr *tetr)
{
    int i;

    i = -1;
    tetr->mlx = NULL;
    tetr->win = NULL;
    my_mlx_init_img(&tetr->main_img);
    my_mlx_init_img(&tetr->background_img);
    tetr->hold_box_size = (t_plane){0, 0, 0, 0};
    tetr->next_box_size = (t_plane){0, 0, 0, 0};
    tetr->time_box_size = (t_plane){0, 0, 0, 0};
    tetr->imbroglio_bar_size = (t_plane){0, 0, 0, 0};
    tetr->cur = (t_piece){.id = 0, .color = 0};
    tetr->hold_toggle = -1;
    tetr->start_time = 0;
    tetr->tiles = NULL;
    tetr->cur_time = NULL;
    tetr->player.name = NULL;
    while (++i < 5)
        tetr->next_stack[i] = (t_piece){.id = 0, .color = 0};
}
