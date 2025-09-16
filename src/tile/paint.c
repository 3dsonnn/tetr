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

void    paint_tile(t_tile *tile, t_img *img, bool paint_dark)
{
	if (!tile)
		return ;
    int end;
	int	lerp_color;

	if (paint_dark)
		lerp_color = my_mlx_get_lerp_color(0, tile->color, 0.4f);
	end = roundf(TILE / 8.0f);
    for (int y = 0; y < TILE; y++)
    {
        for (int x = 0; x < TILE; x++)
        {
            if (y < end || y >= TILE - end || x < end || x >= TILE - end)
                my_mlx_pixel_put(img, tile->crd.x + x, tile->crd.y + y, tile->color);
			else if (((x == end + 1 && y > end && y < TILE - end - 1) || (y == end + 1 && x > end && x < TILE - end - 1))
					|| ((x == TILE - end - 2 && y > end && y < TILE - end - 1) || (y == TILE - end - 2 && x > end && x < TILE - end - 1)))
				my_mlx_pixel_put(img, tile->crd.x + x, tile->crd.y + y, tile->color);
			else if (paint_dark)
				my_mlx_pixel_put(img, tile->crd.x + x, tile->crd.y + y, lerp_color);
        }
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

