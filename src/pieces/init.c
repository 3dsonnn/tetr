/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efinda <efinda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/13 21:08:55 by efinda            #+#    #+#             */
/*   Updated: 2025/06/16 11:28:23 by efinda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tetr.h"

void	init_pieces(t_piece *pieces)
{
	pieces[SQUARE] = (t_piece){.color = SQUARE_COLOR, .type = SQUARE};
	pieces[STRAIGHT] = (t_piece){.color = STRAIGHT_COLOR, .type = STRAIGHT, .straight_rotation = 1};
	pieces[T_SHAPE] = (t_piece){.color = T_SHAPE_COLOR, .type = T_SHAPE};
	pieces[TILTED_S] = (t_piece){.color = TILTED_S_COLOR, .type = TILTED_S};
	pieces[TILTED_Z] = (t_piece){.color = TILTED_Z_COLOR, .type = TILTED_Z};
	pieces[L_SHAPE] = (t_piece){.color = L_SHAPE_COLOR, .type = L_SHAPE};
	pieces[L_MIRRORED] = (t_piece){.color = L_MIRRORED_COLOR, .type = L_MIRRORED};

	const t_point	objs_coords[7][4] = {
					{{4, 0}, {4, 1}, {5, 0}, {5, 1}}, //SQUARE COORDS
					{{3, 0}, {4, 0}, {5, 0}, {6, 0}}, //STRAIGHT COORDS
					{{3, 1}, {4, 1}, {4, 0}, {5, 1}}, //T_SHAPE COORDS
					{{3, 1}, {4, 1}, {4, 0}, {5, 0}}, //TILTED_Z COORDS
					{{5, 1}, {4, 1}, {4, 0}, {3, 0}}, //TILTED_S COORDS
					{{3, 1}, {4, 1}, {5, 1}, {5, 0}}, //L_SHAPE COORDS
					{{5, 1}, {4, 1}, {3, 1}, {3, 0}}  //L_MIRRORED
	};

	for (int i = 0; i < 7; i++)
		ft_memcpy(pieces[i].coords, objs_coords[i], sizeof(t_point) * 4);
}
