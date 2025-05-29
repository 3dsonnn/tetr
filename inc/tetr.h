/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tetr.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efinda <efinda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/23 12:59:02 by efinda            #+#    #+#             */
/*   Updated: 2025/05/29 15:15:35 by efinda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TETR_H
# define TETR_H

# include "../my_mlx/inc/my_mlx.h"
# include "tetr_structs.h"
# include <errno.h>
# include <string.h>
# include <sys/time.h>
# include <time.h>
# include <math.h>

# define WIDTH 1920
# define HEIGHT 1010

# define TILE 32
# define TOTAL_TILE_X 10
# define TOTAL_TILE_Y 20

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
void    design_tiles_divisions(t_img *background, t_tile **tiles);
void	design_border(t_img *main_img, t_tile **tiles);
void    design_imbroglio_bar(t_img *main_img, t_tile **tiles, t_plane *imbroglio_bar);
void	design_hold_box(t_tetr *tetr, t_img *main_img, t_tile **tiles, t_plane *size);
void	design_next_box(t_tetr *tetr, t_img *main_img, t_tile **tiles, t_plane *size, t_point start);
void	design_time_box(t_tetr *tetr, t_img *main_img, t_plane *size, t_plane hold_box_size);

// PIECES
t_piece get_random_piece(void);
// UPDATED
void    update_piece(t_tetr *tetr);
// PUT
void    put_piece(t_piece ref, t_plane size, t_img *img);
void    square(t_point start, t_tile *tile, t_img *img);
void    straight(t_point start, t_tile *tile, t_img *img);
void    tilted_z(t_point start, t_tile *tile, t_img *img);
void    tilted_s(t_point start, t_tile *tile, t_img *img);
void    t_shape(t_point start, t_tile *tile, t_img *img);
void    l_shape(t_point start, t_tile *tile, t_img *img);
void    l_mirrored(t_point start, t_tile *tile, t_img *img);

// UPDATE_SCENARIO
void    update_scenario(t_tetr *tetr);

// BOXES
void    clean_box(t_tetr *tetr, t_img *main_img, t_img background_img, t_plane size);
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
extern void	swap_tile_attr(t_tile *a, t_tile *z);
void        paint_tile(t_tile *tile, t_img *img);
void		free_tiles(t_tile ***tiles, int rows);
void		link_tiles(t_tile **tiles);
void		init_tiles(t_tile ***tiles);
void		set_tiles(t_tile **tiles, t_point padd);

#endif
