/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tetr.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efinda <efinda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/23 12:59:02 by efinda            #+#    #+#             */
/*   Updated: 2025/05/24 14:08:43 by efinda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TETR_H
# define TETR_H

# include "../my_mlx/inc/my_mlx.h"
# include "tetr_structs.h"
# include <sys/time.h>
# include <time.h>

# define WIDTH 1920
# define HEIGHT 1080

# define TILE 16

// INIT_TETR
void		init_tetr(t_tetr *tetr);

// DEALLOCATE_TETR
void		deallocate_tetr(t_tetr *tetr, char *message, int status);

// TILES
extern void	swap_tile_attr(t_tile *a, t_tile *z);
void		free_tiles(t_tile ***tiles, int rows);
void		link_tiles(t_tile **tiles, t_point size);
void		init_tiles(t_tile ***tiles, t_point size);
void		set_tiles(t_tile **tiles, t_point size, t_point padd);

#endif