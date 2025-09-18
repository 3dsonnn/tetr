/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tetr.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efinda <efinda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/23 12:59:02 by efinda            #+#    #+#             */
/*   Updated: 2025/06/17 17:02:37 by efinda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TETR_H
# define TETR_H

# include "libft.h"
# include "tetr_structs.h"
# include <errno.h>
# include <string.h>
# include <sys/time.h>
# include <time.h>
# include <math.h>
# include <stdbool.h>

# define WIDTH 960
# define HEIGHT 1010

# define TILE 32
# define TOTAL_TILE_X 10
# define TOTAL_TILE_Y 25

# define SPACE 32
# define ALT 65513
# define CTRL 65507
# define ESC 65307
# define CKEY 99
# define AKEY 97
# define DKEY 100
# define SKEY 115
# define WKEY 119
# define EKEY 101
# define RIGHT 65363
# define DOWN 65364
# define LEFT 65361
# define UP 65362

// INIT_TETR
void		init_tetr(t_tetr *tetr);

// DEALLOCATE_TETR
void		deallocate_tetr(t_tetr *tetr, char *message, int status);

// PROMPT_USER
void		prompt_user(t_tetr *tetr);

// SETUP
void		setup_game(t_tetr *tetr);

// DESIGN
void    design_tiles_divisions(t_img *texture, t_tile **tiles);
void	design_border(t_img *img, t_tile **tiles);
void    design_imbroglio_bar(t_img *img, t_tile **tiles, t_plane *imbroglio_bar);
void	design_hold_box(t_tetr *tetr, t_img *img, t_tile **tiles, t_plane *size);
void	design_next_box(t_tetr *tetr, t_img *img, t_plane *size, t_point start);
void	design_time_box(t_tetr *tetr, t_img *img, t_plane *size, t_plane hold_box_size);

// PIECES
t_piece get_random_piece(t_tetr *tetr);
// INIT
void	init_pieces(t_piece *pieces);
// ROTATE
void	rotate_piece(t_tetr *tetr);
// MOVE
void    move_piece(t_tetr *tetr, int keycode);
void    fall_piece(t_tetr *tetr);
// BURN_LINE
void	burn_lines(t_tetr *tetr);
// RENDER
void	clean_piece_tile(t_tetr *tetr, t_tile *tile);
void	paint_piece_tile(t_tetr *tetr, t_tile *tile);
int	render_piece( t_tetr *tetr, bool renderize );
// UPDATED
void    update_piece(t_tetr *tetr);
// PUT
void    put_piece(t_piece *curr_piece, const t_plane *size, t_img *img);
void    draw_square_divisions( t_point start, t_img *img );
void    draw_straight_divisions( t_point start, t_img *img );
void    draw_t_divisions( t_point start, t_img *img );
void    draw_l_divisions( t_type piece_type, t_point start, t_img *img );
void    draw_s_or_z_divisions( t_type piece_type, t_point start, t_img *img );

// UPDATE_SCENARIO
void    update_scenario(t_tetr *tetr);

// BOXES
void    clean_box(t_img *img, const t_img *texture, const t_plane *size);
//  NEXT
void    fill_next_box(t_tetr *tetr, t_plane size);
void    move_next_box(t_tetr *tetr);
    //  HOLD
void    hold_piece(t_tetr *tetr, int flag);
    // TIME
void    update_time(t_tetr *tetr);

// INIT_MLX
void		setup_mlx(t_tetr *tetr);

// HOOKS
void		my_mlx_hooks(t_tetr *tetr);

// TILES
void		free_tiles(t_tile ***tiles, int rows);
void		link_tiles(t_tile **tiles);
void		init_tiles(t_tile ***tiles);
void		set_tiles(t_tile **tiles, t_point padd);
void        paint_tile(t_tile *tile, t_img *img, bool paint_dark);
extern void	swap_tile_attr(t_tile *a, t_tile *z);

void	get_piece_limits( const t_point *coords, t_point *great_x, t_point *great_y, t_point *low_x, t_point *low_y );
bool	object_will_collide( t_tetr *tetr );
#endif
