/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tetr_structs.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efinda <efinda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/23 12:58:58 by efinda            #+#    #+#             */
/*   Updated: 2025/05/26 17:36:13 by efinda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TETR_STRUCTS_H
# define TETR_STRUCTS_H

# include "tetr.h"

# define RED_ANSI "\x1b[31m"
# define BOLD_ANSI "\x1b[1m"
# define CYAN_ANSI "\x1b[36m"
# define BLUE_ANSI "\x1b[34m"
# define RESET_ANSI "\x1b[0m"
# define GREEN_ANSI "\x1b[32m"
# define YELLOW_ANSI "\x1b[33m"
# define MAGENTA_ANSI "\x1b[35m"

# define SKY "assets/sky.xpm"
# define HOME "assets/home.xpm"
# define JPINA "assets/jpina.xpm"
# define OCEAN "assets/ocean.xpm"
# define BONFIRE "assets/bonfire.xpm"
# define CLUSTER "assets/cluster.xpm"

typedef struct s_plane
{
	int				x0;
	int				x;
	int				y0;
	int				y;
}					t_plane;

typedef struct s_tile
{
	int				color;
	t_point			crd;
	struct s_tile	*up;
	struct s_tile	*down;
	struct s_tile	*left;
	struct s_tile	*right;
}					t_tile;

typedef struct s_player
{
	char			*name;
}					t_player;

typedef struct s_tetr
{
	void			*mlx;
	void			*win;
	t_img			main_img;
	t_img			background_img;
	t_tile			**tiles;
	t_point			hold_box_crd;
	t_point			next_box_crd;
	t_plane			imbroglio_bar_crd;
	t_player		player;
}					t_tetr;

#endif