/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efinda <efinda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/24 19:46:13 by efinda            #+#    #+#             */
/*   Updated: 2025/06/10 10:32:18 by efinda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/tetr.h"

static void	get_texture(t_tetr *tetr, t_img *texture)
{
	const char	*paths[] = {SKY, EYES, HOME, JPINA, OCEAN,
							CLUSTER, SPINEL, LAPIS, AMETHYST,
							MOON, BEACH, BONFIRE, GARNET};
	int			index;

	index = rand() % TEXTURES;
    if (open((char *)paths[index], O_RDONLY) < 0)
		deallocate_tetr(tetr, strerror(errno), 1);
	texture->img = mlx_xpm_file_to_image(tetr->mlx, (char *)paths[index], &texture->size.x, &texture->size.y);
	if (!texture->img)
		deallocate_tetr(tetr, "Failed to convert the .xpm file into an image. Make sure the assets weren't modified, and then you can try again, please!", 1);
    my_mlx_get_data_addr(texture);
    if (!texture->addr)
		deallocate_tetr(tetr, "Failed to get the address of the background image.", 1);
    my_mlx_resize_img(tetr->mlx, texture, (t_point){WIDTH, HEIGHT});
}

void	setup_mlx(t_tetr *tetr)
{
	srand(time(NULL));
	tetr->mlx = mlx_init();
	if (!tetr->mlx)
		deallocate_tetr(tetr, "Failed to initialize minilibx.", 1);
	get_texture(tetr, &tetr->texture);
	tetr->win = mlx_new_window(tetr->mlx, WIDTH, HEIGHT, "42 t3tr");
	if (!tetr->win)
		deallocate_tetr(tetr, "Failed to open the window.", 1);
	my_mlx_new_img(tetr->mlx, &tetr->img, (t_point){WIDTH, HEIGHT});
	if (!tetr->img.img)
		deallocate_tetr(tetr, "Failed to create the main image.", 1);
	my_mlx_get_data_addr(&tetr->img);
	if (!tetr->img.addr)
		deallocate_tetr(tetr, "Failed to get the address of the main image.", 1);
	my_mlx_put_img_to_img((t_img_to_img){
		.dst = &tetr->img,
		.src = tetr->texture,
		.aux = NULL,
		.dst_point = (t_point){0, 0},
		.src_point = (t_point){0, 0},
		.size = (t_point){WIDTH, HEIGHT},
		.filter = 0,
		.skip = 0,
		.color_aux = 0
	});
    mlx_put_image_to_window(tetr->mlx, tetr->win, tetr->img.img, 0, 0);
}
