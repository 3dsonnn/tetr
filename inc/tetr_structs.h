/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tetr_structs.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efinda <efinda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/23 12:58:58 by efinda            #+#    #+#             */
/*   Updated: 2025/06/17 13:40:17 by efinda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TETR_STRUCTS_H
# define TETR_STRUCTS_H

# include "my_mlx.h"
# include "tetr.h"

# define TEXTURES 14
# define BREAK 800

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
# define EFINDA "assets/efinda.xpm"
# define SPINEL "assets/spinel.xpm"
# define BONFIRE "assets/bonfire.xpm"
# define CLUSTER "assets/cluster.xpm"

# define AMETHYST "assets/amethyst.xpm"
# define GARNET "assets/garnet.xpm"
# define MOON "assets/moon.xpm"
# define BEACH "assets/beach.xpm"

#define SQUARE_COLOR		0xFFFF00
#define STRAIGHT_COLOR		0x99FFFF
#define T_SHAPE_COLOR		0xFF00FF
#define TILTED_S_COLOR		0x99FF33
#define TILTED_Z_COLOR		0xFF3333
#define L_SHAPE_COLOR		0xFF9933
#define L_MIRRORED_COLOR	0x6666FF

typedef struct s_plane
{
	int					x0;
	int					x;
	int					y0;
	int					y;
}						t_plane;

typedef enum e_type
{
	SQUARE,
	STRAIGHT,
	T_SHAPE,
	TILTED_S,
	TILTED_Z,
	L_SHAPE,
	L_MIRRORED
}						t_type;

typedef struct s_tile
{
	unsigned int		color;
	t_point			crd;
	struct s_tile		*up;
	struct s_tile		*down;
	struct s_tile		*left;
	struct s_tile		*right;
}						t_tile;

typedef struct s_piece
{
	t_point		coords[4];
	t_point		hollow[4];
	unsigned int	color;
	t_type		type;
}				t_piece;

typedef struct s_player
{
	char				*name;
}						t_player;

typedef struct s_tetr
{
	int					down;
	int					hold_toggle;
	t_plane				imbroglio_bar_size;
	t_plane				hold_box_size;
	t_plane				time_box_size;
	t_plane				next_box_size;
	unsigned long long		start_time;
	char				*cur_time;
	void				*mlx;
	void				*win;
	t_player			player;
	t_tile				**tiles;
	t_img				img;
	t_img				texture;
	t_piece				cur;
	t_piece				pieces[7];
	t_piece				next_stack[5];
	int					lines[20];
}						t_tetr;

#endif
