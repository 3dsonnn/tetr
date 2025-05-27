/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_random_piece.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efinda <efinda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 20:51:38 by efinda            #+#    #+#             */
/*   Updated: 2025/05/27 13:04:16 by efinda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/tetr.h"

t_piece	get_random_piece(void)
{
    static t_piece	prev;
	int				index;
	static const t_piece pieces[] = {
		{.id = SQUARE, .color = 0xFFFF00},     // Square
		{.id = T_SHAPE, .color = 0xFF00FF},    // T-Shape
		{.id = TILTED_Z, .color = 0xFF3333},   // Tilted Z
		{.id = TILTED_S, .color = 0x99FF33},   // Tilted S
		{.id = STRAIGHT, .color = 0x99FFFF},   // Straight line
		{.id = L_MIRRORED, .color = 0x6666FF}, // L mirrored
		{.id = L_SHAPE, .color = 0xFF9933},    // L-shape
	};
	while (-42)
	{
        index = rand() % 7;
		if (pieces[index].id == prev.id)
			continue ;
		prev = pieces[index];
        break ;
	}
	return (prev);
}
