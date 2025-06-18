/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efinda <efinda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 17:01:37 by efinda            #+#    #+#             */
/*   Updated: 2025/06/17 17:02:09 by efinda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tetr.h"

inline void swap_tile_attr(t_tile *a, t_tile *z)
{
    t_tile tmp;

    if (!a || !z)
        return ;
    tmp = *a;
    a->color = z->color;
    z->color = tmp.color;
}
