/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   piece_on_box_division.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbofengo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/17 18:32:54 by jbofengo          #+#    #+#             */
/*   Updated: 2025/09/17 18:32:56 by jbofengo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/tetr.h"

void    draw_square_divisions( t_point start, t_img *img )
{
	// Horizontal lines
	my_mlx_draw_line_to_img(img, (t_point){start.x, start.y}, (t_point){TILE * 2, 1}, WHITE);
	my_mlx_draw_line_to_img(img, (t_point){start.x, start.y + TILE}, (t_point){TILE * 2, 1}, WHITE);
	my_mlx_draw_line_to_img(img, (t_point){start.x, start.y + (TILE * 2)}, (t_point){(TILE * 2) + 1, 1}, WHITE);
	// Vertical lines
	my_mlx_draw_line_to_img(img, (t_point){start.x, start.y}, (t_point){1, TILE * 2}, WHITE);
	my_mlx_draw_line_to_img(img, (t_point){start.x + TILE, start.y}, (t_point){1, TILE * 2}, WHITE);
	my_mlx_draw_line_to_img(img, (t_point){start.x + (TILE * 2), start.y}, (t_point){1, TILE * 2}, WHITE);
}

void    draw_straight_divisions( t_point start, t_img *img )
{
	// Horizontal lines
	my_mlx_draw_line_to_img(img, (t_point){start.x, start.y}, (t_point){(TILE * 4), 1}, WHITE);
	my_mlx_draw_line_to_img(img, (t_point){start.x, start.y + TILE}, (t_point){(TILE * 4) + 1, 1}, WHITE);
	// Vertical lines
	my_mlx_draw_line_to_img(img, (t_point){start.x, start.y}, (t_point){1, TILE}, WHITE);
	my_mlx_draw_line_to_img(img, (t_point){start.x + TILE, start.y}, (t_point){1, TILE}, WHITE);
	my_mlx_draw_line_to_img(img, (t_point){start.x + (2 * TILE), start.y}, (t_point){1, TILE}, WHITE);
	my_mlx_draw_line_to_img(img, (t_point){start.x + (TILE * 3), start.y}, (t_point){1, TILE}, WHITE);
	my_mlx_draw_line_to_img(img, (t_point){start.x + (TILE * 4), start.y}, (t_point){1, TILE}, WHITE);
}


void    draw_t_divisions( t_point start, t_img *img )
{
	// Horizontal lines
	my_mlx_draw_line_to_img(img, (t_point){start.x + TILE, start.y}, (t_point){TILE, 1}, WHITE);
	my_mlx_draw_line_to_img(img, (t_point){start.x, start.y + TILE}, (t_point){(3 * TILE), 1}, WHITE);
	my_mlx_draw_line_to_img(img, (t_point){start.x, start.y + (TILE * 2)}, (t_point){(3 * TILE) + 1, 1}, WHITE);
	// Vertical lines
	my_mlx_draw_line_to_img(img, (t_point){start.x, start.y + TILE}, (t_point){1, TILE}, WHITE);
	my_mlx_draw_line_to_img(img, (t_point){start.x + TILE, start.y}, (t_point){1, (TILE * 2)}, WHITE);
	my_mlx_draw_line_to_img(img, (t_point){start.x + (TILE * 2), start.y}, (t_point){1, (2 * TILE)}, WHITE);
	my_mlx_draw_line_to_img(img, (t_point){start.x + (TILE * 3), start.y + TILE}, (t_point){1, TILE}, WHITE);
}

void    draw_l_divisions( t_type piece_type, t_point start, t_img *img )
{
	if (piece_type == L_MIRRORED)
	{
		// Horizontal lines
		my_mlx_draw_line_to_img(img, (t_point){start.x, start.y}, (t_point){TILE, 1}, WHITE);
		my_mlx_draw_line_to_img(img, (t_point){start.x, start.y + TILE}, (t_point){(TILE * 3), 1}, WHITE);
		my_mlx_draw_line_to_img(img, (t_point){start.x, start.y + (TILE * 2)}, (t_point){(TILE * 3) + 1, 1}, WHITE);
		// Vertical lines
		my_mlx_draw_line_to_img(img, (t_point){start.x, start.y}, (t_point){1, (TILE * 2)}, WHITE);
		my_mlx_draw_line_to_img(img, (t_point){start.x + TILE, start.y}, (t_point){1, (TILE * 2)}, WHITE);
		my_mlx_draw_line_to_img(img, (t_point){start.x + (2 * TILE), start.y + TILE}, (t_point){1, TILE}, WHITE);
		my_mlx_draw_line_to_img(img, (t_point){start.x + (3 * TILE), start.y + TILE}, (t_point){1, TILE}, WHITE);
	}
	else
	{
		// Horizontal lines
		my_mlx_draw_line_to_img(img, (t_point){start.x + (2 * TILE), start.y}, (t_point){TILE, 1}, WHITE);
		my_mlx_draw_line_to_img(img, (t_point){start.x, start.y + TILE}, (t_point){(3 * TILE), 1}, WHITE);
		my_mlx_draw_line_to_img(img, (t_point){start.x, start.y + (2 * TILE)}, (t_point){(3 * TILE) + 1, 1}, WHITE);
		// Vertical lines
		my_mlx_draw_line_to_img(img, (t_point){start.x, start.y + TILE}, (t_point){1, TILE}, WHITE);
		my_mlx_draw_line_to_img(img, (t_point){start.x + TILE, start.y + TILE}, (t_point){1, TILE}, WHITE);
		my_mlx_draw_line_to_img(img, (t_point){start.x + (2 * TILE), start.y}, (t_point){1, (TILE * 2)}, WHITE);
		my_mlx_draw_line_to_img(img, (t_point){start.x + (TILE * 3), start.y}, (t_point){1, (2 * TILE)}, WHITE);
	}
}

void    draw_s_or_z_divisions( t_type piece_type, t_point start, t_img *img )
{
	if (piece_type == TILTED_S)
	{
		// Horizontal lines
		my_mlx_draw_line_to_img(img, (t_point){start.x + TILE, start.y}, (t_point){(TILE * 2), 1}, WHITE);
		my_mlx_draw_line_to_img(img, (t_point){start.x, start.y + TILE}, (t_point){(TILE * 3), 1}, WHITE);
		my_mlx_draw_line_to_img(img, (t_point){start.x, start.y + (TILE * 2)}, (t_point){(TILE * 2) + 1, 1}, WHITE);
		// Vertical lines
		my_mlx_draw_line_to_img(img, (t_point){start.x, start.y + TILE}, (t_point){1, TILE}, WHITE);
		my_mlx_draw_line_to_img(img, (t_point){start.x + TILE, start.y}, (t_point){1, (2 * TILE)}, WHITE);
		my_mlx_draw_line_to_img(img, (t_point){start.x + (TILE * 2), start.y}, (t_point){1, (2 * TILE)}, WHITE);
		my_mlx_draw_line_to_img(img, (t_point){start.x + (TILE * 3), start.y}, (t_point){1, TILE}, WHITE);
	}
	else
	{
		// Horizontal lines
		my_mlx_draw_line_to_img(img, (t_point){start.x, start.y}, (t_point){(TILE * 2), 1}, WHITE);
		my_mlx_draw_line_to_img(img, (t_point){start.x, start.y + TILE}, (t_point){(TILE * 3), 1}, WHITE);
		my_mlx_draw_line_to_img(img, (t_point){start.x + TILE, start.y + (2 * TILE)}, (t_point){(TILE * 2) + 1, 1}, WHITE);
		// Vertical lines
		my_mlx_draw_line_to_img(img, (t_point){start.x, start.y}, (t_point){1, TILE}, WHITE);
		my_mlx_draw_line_to_img(img, (t_point){start.x + TILE, start.y}, (t_point){1, (TILE * 2)}, WHITE);
		my_mlx_draw_line_to_img(img, (t_point){start.x + (TILE * 2), start.y}, (t_point){1, (TILE * 2)}, WHITE);
		my_mlx_draw_line_to_img(img, (t_point){start.x + (TILE * 3), start.y + TILE}, (t_point){1, TILE}, WHITE);
	}       
}


