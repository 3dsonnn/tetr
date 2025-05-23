/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tetr_structs.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efinda <efinda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/23 12:58:58 by efinda            #+#    #+#             */
/*   Updated: 2025/05/23 13:03:18 by efinda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TETR_STRUCTS_H
# define TETR_STRUCTS_H

# include "tetr.h"

typedef struct s_tile
{
	char				dir;
	int					color;
	t_point				crd;
	struct s_tile		*up;
	struct s_tile		*down;
	struct s_tile		*left;
	struct s_tile		*right;
}						t_tile;

typedef struct s_tetr
{
	void	*mlx;
	void	*win;
	t_img	main_img;
	t_img	background_img;
    t_tile  **tiles;
}			t_tetr;

#endif