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

void	init_piece(t_piece *piece)
{
	ft_memset(piece->design, 0, sizeof(piece->design));
	piece->color = 0;
	piece->type = 0;
	piece->mtxlen = (t_point){0, 0};
	piece->mtxstart = (t_point){0, 0};
	piece->start_index = (t_point){0, 0};
	piece->reverse = (t_point){0, 0};
	piece->iterator = (t_point){0, 0};
}

void	init_pieces(t_piece *pieces, int i, t_point empty)
{
	pieces[SQUARE] = (t_piece){.color = SQUARE_COLOR, .type = SQUARE, .mtxlen = (t_point){2, 2}, .mtxstart = empty, .start_index = empty, .iterator = empty, .reverse = empty};
	pieces[STRAIGHT] = (t_piece){.color = STRAIGHT_COLOR, .type = STRAIGHT, .mtxlen = (t_point){4, 1}, .mtxstart = (t_point){0, 1}, .start_index = empty, .iterator = empty, .reverse = empty};
	pieces[T_SHAPE] = (t_piece){.color = T_SHAPE_COLOR, .type = T_SHAPE, .mtxlen = (t_point){3, 2}, .mtxstart = empty, .start_index = empty, .iterator = empty, .reverse = empty};
	pieces[TILTED_S] = (t_piece){.color = TILTED_S_COLOR, .type = TILTED_S, .mtxlen = (t_point){3, 2}, .mtxstart = empty, .start_index = empty, .iterator = empty, .reverse = empty};
	pieces[TILTED_Z] = (t_piece){.color = TILTED_Z_COLOR, .type = TILTED_Z, .mtxlen = (t_point){3, 2}, .mtxstart = empty, .start_index = empty, .iterator = empty, .reverse = empty};
	pieces[L_SHAPE] = (t_piece){.color = L_SHAPE_COLOR, .type = L_SHAPE, .mtxlen = (t_point){3, 2}, .mtxstart = empty, .start_index = empty, .iterator = empty, .reverse = empty};
	pieces[L_MIRRORED] = (t_piece){.color = L_MIRRORED_COLOR, .type = L_MIRRORED, .mtxlen = (t_point){3, 2}, .mtxstart = empty, .start_index = empty, .iterator = empty, .reverse = empty};

	Shape	designs[7] = {
		{
			{'1', '1', '0', '0'},
			{'1', '1', '0', '0'},
			{'0', '0', '0', '0'},
			{'0', '0', '0', '0'}
		},
		{
			{'0', '0', '0', '0'},
			{'1', '1', '1', '1'},
			{'0', '0', '0', '0'},
			{'0', '0', '0', '0'}
		},
		{
			{'0', '1', '0', '0'},
			{'1', '1', '1', '0'},
			{'0', '0', '0', '0'},
			{'0', '0', '0', '0'}
		},
		{
			{'0', '1', '1', '0'},
			{'1', '1', '0', '0'},
			{'0', '0', '0', '0'},
			{'0', '0', '0', '0'}
		},
		{
			{'1', '1', '0', '0'},
			{'0', '1', '1', '0'},
			{'0', '0', '0', '0'},
			{'0', '0', '0', '0'}
		},
		{
			{'1', '0', '0', '0'},
			{'1', '1', '1', '0'},
			{'0', '0', '0', '0'},
			{'0', '0', '0', '0'}
		},
		{
			{'0', '0', '1', '0'},
			{'1', '1', '1', '0'},
			{'0', '0', '0', '0'},
			{'0', '0', '0', '0'}
		},
	};

	while (++i < 7)
		mtxcpy(designs[i], pieces[i].design, ft_max_point(pieces[i].mtxlen));
}
