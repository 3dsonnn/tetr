/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_tetr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efinda <efinda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/24 12:09:47 by efinda            #+#    #+#             */
/*   Updated: 2025/05/26 17:43:44 by efinda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/tetr.h"

void    init_tetr(t_tetr *tetr)
{
    tetr->mlx = NULL;
    tetr->win = NULL;
    my_mlx_init_img(&tetr->main_img);
    my_mlx_init_img(&tetr->background_img);
    tetr->hold_box_crd = (t_point){0, 0};
    tetr->next_box_crd = (t_point){0, 0};
    tetr->imbroglio_bar_crd = (t_plane){0, 0, 0, 0};
    tetr->tiles = NULL;
    tetr->player.name = NULL;
}
