/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efinda <efinda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/29 14:59:04 by efinda            #+#    #+#             */
/*   Updated: 2025/05/29 15:32:17 by efinda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/tetr.h"

static void	format_time(unsigned long long elapsed_ms, char **buffer)
{
	static const char	*aux[2] = {":", "."};
	int					milliseconds;
	int					seconds;
	int					minutes;
	char				*tmp;

	milliseconds = elapsed_ms % 1000;
	seconds = (elapsed_ms % 60000) / 1000;
	minutes = elapsed_ms / 60000;
	*buffer = ft_itoa(minutes);
	*buffer = ft_strjoin(buffer, (char **)&aux[0], 1);
	tmp = ft_itoa(seconds);
	*buffer = ft_strjoin(buffer, &tmp, 3);
	*buffer = ft_strjoin(buffer, (char **)&aux[1], 1);
	tmp = ft_itoa(milliseconds);
	*buffer = ft_strjoin(buffer, &tmp, 3);
}

void    update_time(t_tetr *tetr)
{
    format_time(ft_gettimeofday() - tetr->start_time, &tetr->cur_time);
    my_mlx_draw_line_to_img(&tetr->main_img,
        (t_point){tetr->time_box_size.x0, tetr->time_box_size.y0},
        (t_point){(tetr->time_box_size.x - tetr->time_box_size.x0), (tetr->time_box_size.y - tetr->time_box_size.y0)}, WHITE);
}