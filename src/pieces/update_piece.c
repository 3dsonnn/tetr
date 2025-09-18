/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_piece.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efinda <efinda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 10:58:36 by efinda            #+#    #+#             */
/*   Updated: 2025/06/17 21:10:06 by efinda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/tetr.h"

void	update_piece(t_tetr *tetr)
{
	if (!tetr->hold_toggle)
		hold_piece(tetr, 1);
	burn_lines(tetr);
	tetr->cur = *tetr->next_stack;
	move_next_box(tetr);
	if (object_will_collide( tetr ))
		deallocate_tetr(tetr, "END OF THE GAME YOU LOST !!!!!!!!!", 0);
	render_piece(tetr, true);
}
