/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deallocate_tetr.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efinda <efinda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/24 12:13:27 by efinda            #+#    #+#             */
/*   Updated: 2025/05/26 08:20:16 by efinda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/tetr.h"

void    deallocate_tetr(t_tetr *tetr, char *message, int status)
{
    if (status && message)
        ft_dprintf(2, "Error!\n%s\n", message);
    my_mlx_destroy_img(tetr->mlx, &tetr->main_img);
    my_mlx_destroy_img(tetr->mlx, &tetr->background_img);
    free_tiles(&tetr->tiles, TOTAL_TILE_Y);
    ft_strfree(&tetr->player.name);
    if (tetr->mlx && tetr->win)
        mlx_destroy_window(tetr->mlx, tetr->win);
    if (tetr->mlx)
    {
        mlx_destroy_display(tetr->mlx);
        free(tetr->mlx);
    }
    exit(status);
}
