/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efinda <efinda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/24 19:46:13 by efinda            #+#    #+#             */
/*   Updated: 2025/05/27 20:31:35 by efinda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/tetr.h"

static void	get_background_img(t_tetr *tetr, t_img *img)
{
	const char	*paths[] = {SKY, HOME, JPINA, OCEAN, BONFIRE, CLUSTER};
	int			index;

	index = rand() % 6;
    if (open((char *)paths[index], O_RDONLY) < 0)
		deallocate_tetr(tetr, strerror(errno), 1);
	img->img = mlx_xpm_file_to_image(tetr->mlx, (char *)paths[index], &img->size.x, &img->size.y);
	if (!img->img)
		deallocate_tetr(tetr, "Failed to convert the .xpm file into an image. Make sure the assets weren't modified, and then you can try again, please!", 1);
    my_mlx_get_data_addr(img);
    if (!img->addr)
		deallocate_tetr(tetr, "Failed to get the address of the background image.", 1);
    my_mlx_resize_img(tetr->mlx, img, (t_point){WIDTH, HEIGHT});
}

void	setup_mlx(t_tetr *tetr)
{
	srand(time(NULL));
	tetr->mlx = mlx_init();
	if (!tetr->mlx)
		deallocate_tetr(tetr, "Failed to initialize minilibx.", 1);
	get_background_img(tetr, &tetr->background_img);
	tetr->win = mlx_new_window(tetr->mlx, WIDTH, HEIGHT, "42 t3tr");
	if (!tetr->win)
		deallocate_tetr(tetr, "Failed to open the window.", 1);
	my_mlx_new_img(tetr->mlx, &tetr->main_img, (t_point){WIDTH, HEIGHT});
	if (!tetr->main_img.img)
		deallocate_tetr(tetr, "Failed to create the main image.", 1);
	my_mlx_get_data_addr(&tetr->main_img);
	if (!tetr->main_img.addr)
		deallocate_tetr(tetr, "Failed to get the address of the main image.", 1);
	my_mlx_put_img_to_img((t_img_to_img){
		.dst = &tetr->main_img,
		.src = tetr->background_img,
		.aux = NULL,
		.dst_point = (t_point){0, 0},
		.src_point = (t_point){0, 0},
		.size = (t_point){WIDTH, HEIGHT},
		.filter = 0,
		.skip = 0,
		.color_aux = 0
	});
    mlx_put_image_to_window(tetr->mlx, tetr->win, tetr->main_img.img, 0, 0);
}
