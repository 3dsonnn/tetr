/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efinda <efinda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/23 13:07:33 by efinda            #+#    #+#             */
/*   Updated: 2025/06/10 11:17:56 by efinda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/tetr.h"
#include <stdio.h>

int	ft_close(int keycode, t_tetr *vars)
{
	if (keycode == 65307)
	{
		mlx_destroy_image(vars->mlx, vars->main_img.img);
		mlx_destroy_window(vars->mlx, vars->win);
		mlx_destroy_display(vars->mlx);
		free(vars->mlx);
		exit(0);
	}
	return (0);
}

int	ft_destroy_window(t_tetr *vars)
{
	mlx_destroy_image(vars->mlx, vars->main_img.img);
	mlx_destroy_window(vars->mlx, vars->win);
	mlx_destroy_display(vars->mlx);
	free(vars->mlx);
	exit(0);
}

int	get_greatest(t_point point)
{
	if (point.x > point.y)
		return (point.x);
	return (point.y);
}

void	copy_matrix(const char (*src)[4], int src_size, char (*dst)[4])
{
	t_point	iter;

	iter.y = -1;
	while (++iter.y < src_size)
	{
		iter.x = -1;
		while (++iter.x < src_size)
			dst[iter.y][iter.x] = src[iter.y][iter.x];
	}
}

t_obj	*get_object_data(t_obj_type type)
{
	static t_obj		objs_data[7] = {
			{.type = BLOCK, .color = 0xFFD700, .matrix_len = (t_point){2, 2}, .matrix_start = (t_point){0, 0}},
			{.type = T_OBJ, .color = 0xBA55D3, .matrix_len = (t_point){3, 2}, .matrix_start = (t_point){0, 0}},
			{.type = J_OBJ, .color = 0x7B68EE, .matrix_len = (t_point){3, 2}, .matrix_start = (t_point){0, 0}},
			{.type = L_OBJ, .color = 0xFF8C00, .matrix_len = (t_point){3, 2}, .matrix_start = (t_point){0, 0}},
			{.type = S_OBJ, .color = 0x9ACD32, .matrix_len = (t_point){3, 2}, .matrix_start = (t_point){0, 0}},
			{.type = Z_OBJ, .color = 0xFF4500, .matrix_len = (t_point){3, 2}, .matrix_start = (t_point){0, 0}},
			{.type = STICK, .color = 0xADD8E6, .matrix_len = (t_point){4, 1}, .matrix_start = (t_point){0, 1}},
	};
	static char const	block[4][4] = {
						{'1', '1', '0', '0'},
						{'1', '1', '0', '0'},
						{'0', '0', '0', '0'},
						{'0', '0', '0', '0'}
	};
	static char const	t_form[4][4] = {
						{'0', '1', '0', '0'},
						{'1', '1', '1', '0'},
						{'0', '0', '0', '0'},
						{'0', '0', '0', '0'}
	};
	static char const	j_form[4][4] = {
						{'1', '0', '0', '0'},
						{'1', '1', '1', '0'},
						{'0', '0', '0', '0'},
						{'0', '0', '0', '0'}
	};
	static char const	l_form[4][4] = {
						{'0', '0', '1', '0'},
						{'1', '1', '1', '0'},
						{'0', '0', '0', '0'},
						{'0', '0', '0', '0'}
	};
	static char const	s_form[4][4] = {
						{'0', '1', '1', '0'},
						{'1', '1', '0', '0'},
						{'0', '0', '0', '0'},
						{'0', '0', '0', '0'}
	};
	static char const	z_form[4][4] = {
						{'1', '1', '0', '0'},
						{'0', '1', '1', '0'},
						{'0', '0', '0', '0'},
						{'0', '0', '0', '0'}
	};
	static char const	stick[4][4] = {
						{'0', '0', '0', '0'},
						{'1', '1', '1', '1'},
						{'0', '0', '0', '0'},
						{'0', '0', '0', '0'}
	};
	static const char	(*forms[7])[4] = {block, t_form, j_form, l_form, s_form, z_form, stick};
	int			i;

	i = -1;
	while (++i < 7)
	{
		if (type == objs_data[i].type)
		{
			objs_data[i].iterator = (t_point){0, 0};
			copy_matrix(forms[objs_data[i].type], get_greatest(objs_data[i].matrix_len), objs_data[i].design);
			return (&objs_data[i]);
		}
	}
	return (NULL);
}

void	rotate_object(t_obj *obj)
{
	char		old_form[4][4];
	static char	height_fixer;
	int			limit;
	int			reverse_index;
	int			tmp;
	t_point		new_start;
	t_point		iter;

	if (obj->type == BLOCK)
		return ;
	limit = get_greatest(obj->matrix_len);
	copy_matrix(obj->design, limit, old_form);
	iter.y = -1;
	obj->matrix_start.x = TOTAL_TILE_X;
	obj->matrix_start.y = TOTAL_TILE_Y;
	obj->matrix_end.x = -1;
	obj->matrix_end.y = -1;
	while (++iter.y < limit)
	{
		iter.x = -1;
		while (++iter.x < limit)
		{
			reverse_index = limit - iter.y - 1;
			obj->design[iter.x][reverse_index] = old_form[iter.y][iter.x];

			if (old_form[iter.y][iter.x] == '1' && reverse_index < obj->matrix_start.x)
				obj->matrix_start.x = reverse_index;
			if (old_form[iter.y][iter.x] == '1' && reverse_index > obj->matrix_end.x)
				obj->matrix_end.x = reverse_index;

			if (old_form[iter.y][iter.x] == '1' && iter.x < obj->matrix_start.y)
				obj->matrix_start.y = iter.x;
			if (old_form[iter.y][iter.x] == '1' && iter.x > obj->matrix_end.y)
				obj->matrix_end.y = iter.x;
		}
	}
	tmp = obj->matrix_len.x;
	obj->matrix_len.x = obj->matrix_len.y;
	obj->matrix_len.y = tmp;

	/*new_start.x = ((TOTAL_TILE_X - obj->matrix_len.x) / 2) + (obj->matrix_len.x % 2);
	new_start.x += obj->compensation + obj->matrix_start.x;

	if (new_start.x < 0)
		new_start.x = 0;
	else if (new_start.x + obj->matrix_len.x > TOTAL_TILE_X)
		new_start.x = TOTAL_TILE_X - obj->matrix_len.x;

	obj->start_index.x = new_start.x;
	if (!obj->matrix_start.x && obj->matrix_start.y)
	{
		obj->start_index.y += obj->matrix_start.y;
		height_fixer = obj->matrix_start.y;
	}
	else if (obj->start_index.y - height_fixer >= 0)
		obj->start_index.y -= height_fixer;
	*/
	printf("startx: %d, starty: %d\n", obj->matrix_start.x, obj->matrix_start.y);
	printf("endx: %d, endy: %d\n", obj->matrix_end.x, obj->matrix_end.y);
	for (int i = 0; i < limit; i++)
	{
		for (int j = 0; j < limit; j++)
		{
			write(1, &obj->design[i][j], 1);
			write(1, " ", 1);
		}
		write(1, "\n", 1);
	}
}

void	paint_object_tile(t_tetr *tetr, t_tile *this_tile)
{
	t_obj	*object;

	object = tetr->obj;
	this_tile->color = object->color;
	paint_tile(this_tile, &tetr->background_img);
}

void	erase_object_tile(t_tetr *tetr, t_tile *this_tile)
{
	my_mlx_put_img_to_img((t_img_to_img){
		.dst = &tetr->background_img,
		.src = tetr->main_img,
		.aux = NULL,
		.dst_point = (t_point){this_tile->crd.x + 1, this_tile->crd.y + 1},
		.src_point = (t_point){this_tile->crd.x + 1, this_tile->crd.y + 1},
		.size = (t_point){.x = TILE - 2, .y = TILE - 2},
		.filter = 0,
		.skip = 0,
		.color_aux = 0
	});
}

void	render_object(t_tetr *vars, void (*tile_action)(t_tetr *, t_tile *))
{
	t_obj		*object;
	t_point		iter;
	int			limit;

	if (!vars || !tile_action)
		return ;
	object = vars->obj;
	limit = get_greatest(object->matrix_len);
	iter.y = object->iterator.y - 1;
	while (++iter.y < limit)
	{
		iter.x = object->iterator.x - 1;
		while (++iter.x < limit)
		{
			if (object->design[iter.y][iter.x] == '1')
			{
				tile_action(vars, &vars->tiles[object->start_index.y + iter.y - object->iterator.y][object->start_index.x + iter.x - object->iterator.x]);
			}
		}
	}
}

void	start_object(t_tetr *vars, t_obj *datas)
{
	if (!vars || !datas)
		return ;
	vars->obj = datas;
	vars->obj->start_index.y = 0;
	vars->obj->start_index.x = ((TOTAL_TILE_X - datas->matrix_len.x) / 2);
	render_object(vars, paint_object_tile);
}

int	main(void)
{
	t_tetr	tetr;

	init_tetr(&tetr);
	// prompt_user(&tetr);
	setup_game(&tetr);
	start_object(&tetr, get_object_data(STICK));
	my_mlx_hooks(&tetr);
	mlx_loop(tetr.mlx);
	return (0);
}


//inc, rest, rest, rest
