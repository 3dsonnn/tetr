/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup_game.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efinda <efinda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/24 19:46:16 by efinda            #+#    #+#             */
/*   Updated: 2025/05/27 20:31:20 by efinda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/tetr.h"

static void	setup_tiles(t_tetr *tetr, t_tile ***tiles)
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

static void	setup_design(t_tetr *tetr, t_tile **tiles, t_img *main_img)
{
    design_tiles_divisions(main_img, tetr->tiles);
	design_border(main_img, tetr->tiles);
	design_imbroglio_bar(main_img, tetr->tiles, &tetr->imbroglio_bar_size);
    design_hold_box(tetr, main_img, tetr->tiles, &tetr->hold_box_size);
    design_next_box(tetr, main_img, tetr->tiles, &tetr->next_box_size, (t_point){tetr->imbroglio_bar_size.x + 3, tetr->imbroglio_bar_size.y0});
}

void	setup_game(t_tetr *tetr)
{
	setup_mlx(tetr);
	setup_tiles(tetr, &tetr->tiles);
	setup_design(tetr, tetr->tiles, &tetr->main_img);
	fill_next_box(tetr, &tetr->main_img, tetr->next_box_size);
}
