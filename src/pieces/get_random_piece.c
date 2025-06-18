/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_random_piece.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efinda <efinda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 20:51:38 by efinda            #+#    #+#             */
/*   Updated: 2025/06/16 12:01:12 by efinda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/tetr.h"

t_piece	get_random_piece(t_tetr *tetr)
{
	static t_piece	prev;
	int				index;

	while (-42)
	{
		index = rand() % 7;
		if (tetr->pieces[index].type == prev.type)
			continue ;
		prev = tetr->pieces[index];
		prev.start_index = (t_point){.x = (TOTAL_TILE_X - prev.mtxlen.x) / 2, .y = 0};
		break ;
	}
	return (prev);
}
