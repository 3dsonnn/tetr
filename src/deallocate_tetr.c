/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deallocate_tetr.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efinda <efinda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/24 12:13:27 by efinda            #+#    #+#             */
/*   Updated: 2025/06/10 10:01:54 by efinda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/tetr.h"

void    deallocate_tetr(t_tetr *tetr, char *message, int status)
{
    if (status && message)
        ft_dprintf(2, "Error!\n%s\n", message);
    my_mlx_destroy_img(tetr->mlx, &tetr->img);
    my_mlx_destroy_img(tetr->mlx, &tetr->texture);
    free_tiles(&tetr->tiles, TOTAL_TILE_Y);
    ft_strfree(&tetr->player.name);
    ft_strfree(&tetr->cur_time);
    if (tetr->mlx && tetr->win)
        mlx_destroy_window(tetr->mlx, tetr->win);
    if (tetr->mlx)
    {
        mlx_destroy_display(tetr->mlx);
        free(tetr->mlx);
    }
    exit(status);
}
