/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tetr.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efinda <efinda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/23 12:59:02 by efinda            #+#    #+#             */
/*   Updated: 2025/05/26 18:35:10 by efinda           ###   ########.fr       */
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
void	design_border(t_img *background_img, t_tile **tiles);
void	design_hold_box(t_img *background_img, t_tile **tiles, t_point *hold_box_crd);
void    design_imbroglio_bar(t_img *background_img, t_tile **tiles, t_plane *imbroglio_bar);
void	design_next_box(t_img *background_img, t_tile **tiles, t_point *next_box_crd, t_point start);

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
