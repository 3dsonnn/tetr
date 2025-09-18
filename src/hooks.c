/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efinda <efinda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/24 17:51:07 by efinda            #+#    #+#             */
/*   Updated: 2025/06/17 21:12:02 by efinda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/tetr.h"

static int	my_mlx_close(t_tetr *tetr)
{
	deallocate_tetr(tetr, "The Game Was Closed Through The Window's Close Button.", 0);
	return (0);
}

static inline int	my_mlx_key_release(int keycode, t_tetr *tetr)
{
	if (keycode == DOWN)
		tetr->down = 0;
	return (0);
}

static int	my_mlx_key_press(int keycode, t_tetr *tetr)
{
	static	unsigned long long last_time;

	if (keycode == ESC)
		deallocate_tetr(tetr, "The Game Was Closed Through The ESC Key Press.", 0);
	if (keycode == SPACE)
	{
		render_piece(tetr, false);
		for (int i = 0; i < 4; i++)
			tetr->cur.coords[i] = tetr->cur.hollow[i];
		render_piece(tetr, true);
		update_piece(tetr);
	}
	else if (keycode == UP)
	{
		if (ft_gettimeofday() - last_time > 100)
		{
			rotate_piece(tetr);
			last_time = ft_gettimeofday();
		}


	}
	else if (keycode == DOWN)
		tetr->down = 1;
	else if (keycode == LEFT || keycode == RIGHT)
		move_piece(tetr, keycode);
	else if ((keycode == CKEY && tetr->hold_toggle) || keycode == AKEY)
	{
		render_piece(tetr, false);
		if (keycode == AKEY)
			update_piece(tetr);
		else
			hold_piece(tetr, 0);
		render_piece(tetr, true);
	}
	return (0);
}

static int	my_mlx_loop_hook(t_tetr *tetr)
{
	(void)tetr;
	static unsigned long long	last_time;
	unsigned long long			cur_time;

	cur_time = ft_gettimeofday();
	if (cur_time - last_time > BREAK
		|| (tetr->down && (cur_time - last_time > 50)))
	{
		fall_piece(tetr);
		last_time = cur_time;
	}
	update_time(tetr);
	update_scenario(tetr);
	return (0);
}

void	my_mlx_hooks(t_tetr *tetr)
{
	mlx_hook(tetr->win, 2, 1L << 0, my_mlx_key_press, tetr);
	mlx_hook(tetr->win, 3, 1L << 1, my_mlx_key_release, tetr);
	mlx_hook(tetr->win, 17, 1L << 17, my_mlx_close, tetr);
	tetr->start_time = ft_gettimeofday();
	mlx_loop_hook(tetr->mlx, my_mlx_loop_hook, tetr);
}

