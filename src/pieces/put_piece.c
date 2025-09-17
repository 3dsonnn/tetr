/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_piece.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efinda <efinda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 21:07:29 by efinda            #+#    #+#             */
/*   Updated: 2025/06/14 21:02:33 by efinda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/tetr.h"

static  t_point get_padded_start(const t_plane *size, t_point lil)
{
    t_point res;
    t_point range;
    t_point center;

    range = (t_point){size->x - size->x0, size->y - size->y0};
    center = ft_center_range(range, lil);
    res = (t_point){.x = size->x0 + center.x, .y = size->y0 + center.y};
    return (res);
}

static t_point get_piece_padded_start( t_type piece_type, const t_plane *size )
{
	if (piece_type == SQUARE)
		return (get_padded_start(size, (t_point){(TILE * 2), (TILE * 2)}));
	else if (piece_type == L_MIRRORED || piece_type == L_SHAPE)
		return (get_padded_start(size, (t_point){(TILE * 3), (TILE * 2)}));
	else if (piece_type == TILTED_Z || piece_type == TILTED_S)
		return (get_padded_start(size, (t_point){(TILE * 3), (TILE * 2)}));
	else if (piece_type == STRAIGHT)
		return (get_padded_start(size, (t_point){(TILE * 4), TILE}));
	return (get_padded_start(size, (t_point){(TILE * 3), (TILE * 2)}));
}

static void    init_piece_coords_on_box( t_type piece_type, t_point *coords, t_point start )
{
    coords[0] = start;
    if (piece_type == SQUARE)
    {
        coords[1] = (t_point){start.x + TILE, start.y};
        coords[2] = (t_point){start.x, start.y + TILE};
        coords[3] = (t_point){coords[1].x, coords[2].y};
    }
    else if (piece_type == L_MIRRORED)
    {
        coords[1] = (t_point){start.x, start.y + TILE};
        coords[2] = (t_point){start.x + TILE, coords[1].y};
        coords[3] = (t_point){coords[2].x + TILE, coords[1].y};
    }
    else if (piece_type == L_SHAPE)
    {
        coords[0].x += TILE * 2;
        coords[1] = (t_point){start.x, start.y + TILE};
        coords[2] = (t_point){start.x + TILE, coords[1].y};
        coords[3] = (t_point){coords[2].x + TILE, coords[1].y};
    }
    else if (piece_type == STRAIGHT)
    {
        coords[1] = (t_point){start.x + TILE, start.y};
        coords[2] = (t_point){coords[1].x + TILE, start.y};
        coords[3] = (t_point){coords[2].x + TILE, start.y};
    }
    else if (piece_type == T_SHAPE)
    {
        coords[0].y += TILE;
        coords[1] = (t_point){start.x + TILE, coords[0].y};
        coords[2] = (t_point){coords[1].x, start.y};
        coords[3] = (t_point){coords[1].x + TILE, coords[0].y};
    }
    else if (piece_type == TILTED_Z)
    {
        coords[1] = (t_point){start.x + TILE, start.y};
        coords[2] = (t_point){coords[1].x, start.y + TILE};
        coords[3] = (t_point){coords[1].x + TILE, coords[2].y};
    }
    else if (piece_type == TILTED_S)
    {
        coords[0].y += TILE;
        coords[1] = (t_point){start.x + TILE, coords[0].y};
        coords[2] = (t_point){coords[1].x, start.y};
        coords[3] = (t_point){coords[1].x + TILE, start.y};
    }
}

static void	render_piece_division_on_box( t_type piece_type, t_point start, t_img *img )
{
	if (piece_type == SQUARE)
		draw_square_divisions( start, img );
	else if (piece_type == L_MIRRORED || piece_type == L_SHAPE)
		draw_l_divisions( piece_type, start, img );
	else if (piece_type == TILTED_Z || piece_type == TILTED_S)
		draw_s_or_z_divisions( piece_type, start, img );
	else if (piece_type == STRAIGHT)
		draw_straight_divisions( start, img );
	else if (piece_type == T_SHAPE)
		draw_t_divisions( start, img );
}

void	put_piece( t_piece *curr_piece, const t_plane *size, t_img *img )
{
	t_point start;
	t_tile  tile;
	t_point coords[4];

	tile.color = curr_piece->color;
	start = get_piece_padded_start( curr_piece->type, size );
	init_piece_coords_on_box( curr_piece->type, coords, start );
	for (int i = 0; i < 4; i++)
	{
		tile.crd = coords[i];
		paint_tile( &tile, img, true );
	}
	render_piece_division_on_box( curr_piece->type, start, img );
}
