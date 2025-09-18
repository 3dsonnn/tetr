/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_tetr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efinda <efinda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/24 12:09:47 by efinda            #+#    #+#             */
/*   Updated: 2025/06/17 14:34:30 by efinda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/tetr.h"

void    init_tetr(t_tetr *tetr)
{
	int	i;

	i = -1;
	tetr->mlx = NULL;
	tetr->win = NULL;
	my_mlx_init_img(&tetr->img);
	my_mlx_init_img(&tetr->texture);
	tetr->hold_box_size = (t_plane){0, 0, 0, 0};
	tetr->next_box_size = (t_plane){0, 0, 0, 0};
	tetr->time_box_size = (t_plane){0, 0, 0, 0};
	tetr->imbroglio_bar_size = (t_plane){0, 0, 0, 0};
	ft_memset(&tetr->cur, 0, sizeof(t_piece));
	tetr->up = 0;
	tetr->down = 0;
	tetr->hold_toggle = -1;
	tetr->start_time = 0;
	tetr->tiles = NULL;
	tetr->cur_time = NULL;
	tetr->player.name = NULL;
	while (++i < TOTAL_TILE_Y)
	{
		if (i < 5)
			ft_memset(&tetr->next_stack[i], 0, sizeof(t_piece));
		tetr->lines[i] = -1;
	}
	init_pieces(tetr->pieces);
}
