/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_tetr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efinda <efinda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/24 12:09:47 by efinda            #+#    #+#             */
/*   Updated: 2025/05/24 12:18:50 by efinda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/tetr.h"

void    init_tetr(t_tetr *tetr)
{
    tetr->mlx = NULL;
    tetr->win = NULL;
    my_mlx_init_img(&tetr->main_img);
    my_mlx_init_img(&tetr->background_img);
    tetr->tiles = NULL;
    tetr->total_tiles = (t_point){0, 0};
}
