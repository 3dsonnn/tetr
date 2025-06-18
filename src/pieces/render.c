/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efinda <efinda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/14 23:47:42 by efinda            #+#    #+#             */
/*   Updated: 2025/06/17 14:17:17 by efinda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tetr.h"

void	paint_piece_tile(t_tetr *tetr, t_tile *tile)
{
	paint_tile(tile, &tetr->img);
}

void	clean_piece_tile(t_tetr *tetr, t_tile *tile)
{
	tile->color = 0;
	my_mlx_put_img_to_img((t_img_to_img){
		.dst = &tetr->img,
		.src = tetr->texture,
		.aux = NULL,
		.dst_point = (t_point){tile->crd.x, tile->crd.y},
		.src_point = (t_point){tile->crd.x, tile->crd.y},
		.size = (t_point){.x = TILE, .y = TILE},
		.filter = 0,
		.skip = 0,
		.color_aux = 0
	});
}

int	has_collision(t_piece *piece, t_tetr *tetr, t_point mtxend)
{
	t_point	iter;
	t_point	index;

	if (!piece->start_index.y)
	{
		for (int i = piece->start_index.x; i < piece->start_index.x + piece->mtxlen.x; i++)
		{
			if (tetr->tiles[mtxend.y + 1][i].color)
				deallocate_tetr(tetr, "Failed to initialize minilibx.", 1);
		}
	}
	iter.y = piece->iterator.y - 1;
	while (++iter.y < mtxend.y)
	{
		iter.x = piece->iterator.x - 1;
		while (++iter.x < mtxend.x)
		{
			if (piece->design[iter.y][iter.x] == '1')
            {
				index = (t_point){.x = piece->start_index.x + iter.x - piece->iterator.x,
                    .y = piece->start_index.y + iter.y - piece->iterator.y};
				if (tetr->tiles[index.y][index.x].color)
					return (1);
            }
		}
	}
	return (0);
}

int	render_piece(t_tetr	*tetr, char flag, void (*action)(t_tetr *, t_tile *))
{
	t_tile		*tile;
	t_point		mtxend;
	t_point		index;
	t_point		iter;
	t_piece		*piece;

	if (!action)
		return (0);
	piece = &tetr->cur;
    mtxend = (t_point){.x = piece->mtxstart.x + piece->mtxlen.x, .y = piece->mtxstart.y + piece->mtxlen.y};
	if (flag && has_collision(piece, tetr, mtxend) && piece->start_index.y)
		return (0);
	iter.y = piece->iterator.y - 1;
	while (++iter.y < mtxend.y)
	{
		iter.x = piece->iterator.x - 1;
		while (++iter.x < mtxend.x)
		{
			if (piece->design[iter.y][iter.x] == '1')
            {
				index = (t_point){.x = piece->start_index.x + iter.x - piece->iterator.x,
                    .y = piece->start_index.y + iter.y - piece->iterator.y};
				tile = &tetr->tiles[index.y][index.x];
				tile->color = piece->color;
				action(tetr, tile);
            }
		}
	}
	return (1);
}
