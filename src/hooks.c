/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efinda <efinda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/24 17:51:07 by efinda            #+#    #+#             */
/*   Updated: 2025/05/29 15:30:30 by efinda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/tetr.h"

static int	my_mlx_close(t_tetr *tetr)
{
	deallocate_tetr(tetr, "The Game Was Closed Through The Window's Close Button.", 0);
	return (0);
}

static int	my_mlx_key_press(int keycode, t_tetr *tetr)
{
	if (keycode == ESC)
        deallocate_tetr(tetr, "The Game Was Closed Through The ESC Key Press.", 0);
	if (keycode == CKEY && tetr->hold_toggle)
		hold_piece(tetr, 0);
	if (keycode == AKEY)
		update_piece(tetr);
	return (0);
}

static int	my_mlx_loop_hook(t_tetr *tetr)
{
	update_time(tetr);
	update_scenario(tetr);
	return (0);
}

void	my_mlx_hooks(t_tetr *tetr)
{
	mlx_hook(tetr->win, 2, 1L << 0, my_mlx_key_press, tetr);
	mlx_hook(tetr->win, 17, 1L << 17, my_mlx_close, tetr);
	tetr->start_time = ft_gettimeofday();
	mlx_loop_hook(tetr->mlx, my_mlx_loop_hook, tetr);
}
