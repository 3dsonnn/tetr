/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_piece.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efinda <efinda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 10:58:36 by efinda            #+#    #+#             */
/*   Updated: 2025/05/29 16:40:18 by efinda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/tetr.h"

void    update_piece(t_tetr *tetr)
{
    if (!tetr->hold_toggle)
		  hold_piece(tetr, 1);
    tetr->cur = *tetr->next_stack;
    move_next_box(tetr);
}
