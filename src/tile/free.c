/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efinda <efinda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/22 15:23:37 by efinda            #+#    #+#             */
/*   Updated: 2025/05/24 13:46:34 by efinda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/tetr.h"

void	free_tiles(t_tile ***tiles, int	rows)
{
	t_point	iter;

	iter = (t_point){.x = -1, .y = -1};
	if (!tiles || !(*tiles) || rows < 1)
		return ;
	while (++iter.y < rows)
	{
		free((*tiles)[iter.y]);
        (*tiles)[iter.y] = NULL;
	}
	free(*tiles);
    *tiles = NULL;
}
