/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   paint.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efinda <efinda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 07:47:36 by efinda            #+#    #+#             */
/*   Updated: 2025/06/16 18:30:35 by efinda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/tetr.h"

void    paint_tile(t_tile *tile, t_img *img)
{
	if (!tile)
		return ;
	for (int y = 0; y < TILE; y++)
	{
		for (int x = 0; x < TILE; x++)
			my_mlx_pixel_put(img, tile->crd.x + x, tile->crd.y + y, tile->color);
	}
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

