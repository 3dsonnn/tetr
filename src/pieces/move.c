/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efinda <efinda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 11:32:21 by efinda            #+#    #+#             */
/*   Updated: 2025/06/18 09:57:07 by efinda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tetr.h"

void    move_piece(t_tetr *tetr, int keycode)
{
    t_piece *piece;
    t_piece	cur;
    t_point mtxend;

    piece = &tetr->cur;
    mtxend = (t_point){.x = piece->mtxstart.x + piece->mtxlen.x - 1,
        .y = piece->mtxstart.y + piece->mtxlen.y - 1};
    cur = tetr->cur;
    render_piece(tetr, 0, clean_piece_tile);
    if (keycode == LEFT)
    {
		//Se ainda pode ser decrementado
		if (piece->start_index.x)
		{
			if (piece->reverse.x)
				piece->reverse.x--;
			piece->start_index.x--;
		}
		//Se o range do objecto esta na parede esquerda mas a sua forma fisica ainda não tocou
		else if (piece->mtxstart.x && (piece->mtxstart.x - piece->iterator.x))
			piece->iterator.x++;
    }
    else
    {
        //Verifica se o há colunas vazias dentro da matriz e se o iterador do objecto é diferente de zero, caso para quando o objecto estiver do lado esquerdo
		if (piece->mtxstart.x && piece->iterator.x) //ERRO ESTÁ AQUI!!!!!!!!!!!!!!!!!!!!!!!!
			piece->iterator.x--;
		//Se o índex de inicio dos tales mais o maior comprimento do objecto for menor que o numero de tiles em x, para evitar que ele vá além da tabela
		else if (piece->start_index.x + ft_max_point(piece->mtxlen) < TOTAL_TILE_X)
			piece->start_index.x++;
		//Se o range do objecto esta na parede direita mas a sua forma fisica ainda não tocou
		else if (mtxend.x + 1 + piece->reverse.x < ft_max_point(piece->mtxlen))
		{
			piece->start_index.x++;
			piece->reverse.x++;
		}
    }
    if (!render_piece(tetr, 1, paint_piece_tile))
    {
        tetr->cur = cur;
        render_piece(tetr, 1, paint_piece_tile);
    }
}

void    fall_piece(t_tetr *tetr)
{
    t_piece *piece;
    t_piece cur;
    int     mtxend_y;
    int     max_len;

    piece = &tetr->cur;
    cur = *piece;
    max_len = ft_max_point(piece->mtxlen);
    mtxend_y = piece->mtxstart.y + piece->mtxlen.y - 1;
    if (piece->start_index.y + max_len < TOTAL_TILE_Y)
    {
        render_piece(tetr, 0, clean_piece_tile);
        piece->start_index.y++;
    }
    else if (mtxend_y + 1 + piece->reverse.y < max_len)
    {
        render_piece(tetr, 0, clean_piece_tile);
        piece->start_index.y++;
        piece->reverse.y++;
    }
    else
    {
        update_piece(tetr);
        cur = tetr->cur;
    }
    if (!render_piece(tetr, 1, paint_piece_tile))
    {
        tetr->cur = cur;
        render_piece(tetr, 1, paint_piece_tile);
        update_piece(tetr);
    }
}
