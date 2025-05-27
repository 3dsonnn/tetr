/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup_game.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efinda <efinda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/24 19:46:16 by efinda            #+#    #+#             */
/*   Updated: 2025/05/26 08:17:07 by efinda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/tetr.h"

 void	setup_tiles(t_tetr *tetr, t_tile ***tiles)
{
	t_point	padd;
	t_point	half_tiles;

	half_tiles = (t_point){.x = (int)ceil(TOTAL_TILE_X / 2), .y = (int)ceil(TOTAL_TILE_Y / 2)};
	padd = (t_point){.x = ((WIDTH / 2) - (half_tiles.x * TILE)) - half_tiles.x,
		.y = ((HEIGHT / 2) - (half_tiles.y * TILE)) - half_tiles.y};
	init_tiles(tiles);
	if (!tiles || !*tiles)
		deallocate_tetr(tetr, "Failed to allocate memory for the tiles", 1);
	link_tiles(*tiles);
	set_tiles(*tiles, padd);
}

static void	setup_design(t_tetr *tetr, t_tile **tiles, t_img *background_img)
{
    t_tile  *first;
    int     line_thickness;

    first = *tiles;
    line_thickness = 3;
    design_tiles_divisions(background_img, tetr->tiles);
    design_hold_tile_box(background_img, tetr->tiles);
    design_next_tile_box(background_img, tetr->tiles);
}

void	setup_game(t_tetr *tetr)
{
	setup_mlx(tetr);
	setup_tiles(tetr, &tetr->tiles);
	setup_design(tetr, tetr->tiles, &tetr->background_img);
}
