/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efinda <efinda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/23 13:07:33 by efinda            #+#    #+#             */
/*   Updated: 2025/05/25 18:02:57 by efinda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/tetr.h"

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
/*

void	render_obj(t_tetr *vars)
{
	t_tile	*runner;
	t_tile	*aux;
	t_point	pos;

	pos = vars->obj.center;
	runner = &vars->tiles[pos.x][pos.y];
	runner->color = 0x00FF00;
	// if (vars->obj.type == RIGHT_L)
	// {
	// 	pos.y = -1;
	// 	while (runner && ++pos.y < 3)
	// 	{
	// 		runner->color = vars->obj.color;
	// 		paint_tile(runner, &vars->main_img);
	// 		runner = runner->up;
	// 	}
	// 	if (!runner || !runner->right)
	// 		return ;
	// 	printf("%p\n", runner->right);
	// 	//runner->right->color = vars->obj.color;
	// 	write(2, "here\n", 5);
	// }
	aux = &vars->tiles[0][0];;
	for (int i = 0; i < 4; i++)
	{
		paint_tile(aux, &vars->main_img);
		if (i + 1 == 4)
			aux = aux->right;
		else
			aux = aux->down;
		ft_printf("i=%d\n", i);
		if (!aux)
			return ;
	}
	ft_printf("AAAAAAAAAAAAAA\n");
}

const char	*get_instructions(t_obj_type type)
{
	if (type == RIGHT_L)
		return ("U");
	else if (type == LEFT_L)
		return ("");
	return ("");
}

void	get_obj_body(t_tile *this_tile, t_tile *obj_body[3], const char *components)
{
	t_tile	*next_tile;
	int		i;

	if (!components || !*components)
	{
		obj_body[0] = NULL;
		return ;
	}
	i = 0;
	while (components[i])
	{
		if (components[i] == 'D')
			next_tile = this_tile->down;
		else if (components[i] == 'L')
			next_tile = this_tile->left;
		else if (components[i] == 'R')
			next_tile = this_tile->right;
		if (!next_tile)
		{
			obj_body[0] = NULL;
			return ;
		}
		obj_body[i++] = next_tile;
		this_tile = next_tile;
	}
}
*/

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
			{.type = BLOCK, .color = 0xFFD700, .matrix_len = 2},
			{.type = T_OBJ, .color = 0xBA55D3, .matrix_len = 3},
			{.type = J_OBJ, .color = 0x7B68EE, .matrix_len = 3},
			{.type = L_OBJ, .color = 0xFF8C00, .matrix_len = 3},
			{.type = S_OBJ, .color = 0x9ACD32, .matrix_len = 3},
			{.type = Z_OBJ, .color = 0xFF4500, .matrix_len = 3},
			{.type = STICK, .color = 0xADD8E6, .matrix_len = 4},
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
			copy_matrix(forms[objs_data[i].type], objs_data[i].matrix_len, objs_data[i].design);
			return (&objs_data[i]);
		}
	}
	return (NULL);
}

void	rotate_object(t_obj *obj)
{
	char	old_form[4][4];
	t_point		iter;

	if (obj->type == BLOCK)
		return ;
	copy_matrix(obj->design, obj->matrix_len, old_form);
	iter.y = -1;
	while (++iter.y < obj->matrix_len)
	{
		iter.x = -1;
		while (++iter.x < obj->matrix_len)
			obj->design[iter.x][iter.y] = old_form[iter.y][iter.x];
	}
}

void	design_object(t_tetr *vars)
{
	t_tile		*this_tile;
	t_obj		*object;
	t_point		iter;

	object = vars->obj;
	iter.y = -1;
	while (++iter.y < object->matrix_len)
	{
		iter.x = -1;
		while (++iter.x < object->matrix_len)
		{
			if (object->design[iter.y][iter.x] == '1')
			{
				this_tile = &vars->tiles[object->start_index.y + iter.y][object->start_index.x + iter.x];
				this_tile->color = object->color;
				paint_tile(this_tile, &vars->background_img);
			}
		}
	}
}

void	render_map(t_tetr *vars, t_obj *datas)
{
	int	start_index;

	if (!datas)
		return ;
	vars->obj = datas;
	vars->obj->start_index.y = 0;
	vars->obj->start_index.x = ((TOTAL_TILE_X - datas->matrix_len) / 2);
	rotate_object(vars->obj);
	design_object(vars);
}

int	main(void)
{
	t_tetr	tetr;

	init_tetr(&tetr);
	// prompt_user(&tetr);
	setup_game(&tetr);
	render_map(&tetr, get_object_data(BLOCK));
	my_mlx_hooks(&tetr);
	mlx_loop(tetr.mlx);
	return (0);
}
