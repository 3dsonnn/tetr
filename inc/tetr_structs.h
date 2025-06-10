/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tetr_structs.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efinda <efinda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/23 12:58:58 by efinda            #+#    #+#             */
/*   Updated: 2025/06/10 09:53:57 by efinda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TETR_STRUCTS_H
# define TETR_STRUCTS_H

# include "tetr.h"
# include "my_mlx.h"

# define TEXTURES 13

# define GRAY 0xA9A9A9

# define RED_ANSI "\x1b[31m"
# define BOLD_ANSI "\x1b[1m"
# define CYAN_ANSI "\x1b[36m"
# define BLUE_ANSI "\x1b[34m"
# define RESET_ANSI "\x1b[0m"
# define GREEN_ANSI "\x1b[32m"
# define YELLOW_ANSI "\x1b[33m"
# define MAGENTA_ANSI "\x1b[35m"

# define SKY "assets/sky.xpm"
# define EYES "assets/eyes.xpm"
# define HOME "assets/home.xpm"
# define LAPIS "assets/lapis.xpm"
# define JPINA "assets/jpina.xpm"
# define OCEAN "assets/ocean.xpm"
# define SPINEL "assets/spinel.xpm"
# define BONFIRE "assets/bonfire.xpm"
# define CLUSTER "assets/cluster.xpm"

# define AMETHYST "assets/amethyst.xpm"
# define GARNET "assets/garnet.xpm"
# define MOON "assets/moon.xpm"
# define BEACH "assets/beach.xpm"

typedef struct s_plane
{
	int					x0;
	int					x;
	int					y0;
	int					y;
}						t_plane;

typedef enum e_ID
{
	SQUARE,
	T_SHAPE,
	L_SHAPE,
	TILTED_Z,
	TILTED_S,
	STRAIGHT,
	L_MIRRORED
}						t_ID;

typedef struct s_piece
{
	int					id;
	int					color;
}						t_piece;

typedef struct s_tile
{
	int					color;
	t_point				crd;
	struct s_tile		*up;
	struct s_tile		*down;
	struct s_tile		*left;
	struct s_tile		*right;
}						t_tile;

typedef struct s_player
{
	char				*name;
}						t_player;

typedef struct s_tetr
{
	void				*mlx;
	void				*win;
	t_img				img;
	t_img				texture;
	t_tile				**tiles;
	t_plane				hold_box_size;
	t_piece				cur;
	t_plane				next_box_size;
	t_piece				next_stack[5];
	t_plane				imbroglio_bar_size;
	t_plane				time_box_size;
	t_player			player;
	int					hold_toggle;
	unsigned long long	start_time;
	char				*cur_time;
}						t_tetr;

#endif