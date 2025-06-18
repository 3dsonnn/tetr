/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efinda <efinda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 11:17:08 by efinda            #+#    #+#             */
/*   Updated: 2025/06/16 17:34:22 by efinda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/tetr.h"

void	mtxcpy(const char (*src)[4], char (*dst)[4], int size)
{
	t_point	iter;

	iter.y = -1;
	while (++iter.y < size)
	{
		iter.x = -1;
		while (++iter.x < size)
			dst[iter.y][iter.x] = src[iter.y][iter.x];
	}
}

void	putmtx(Shape mtx, int limit)
{
	t_point	iter;

	iter.y = -1;
	while (++iter.y < limit)
	{
		iter.x = -1;
		while (++iter.x < limit)
		{
			write(1, &mtx[iter.y][iter.x], 1);
			write(1, " ", 1);
		}
	}
	write(1, "\n", 1);
}
