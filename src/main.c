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

t_obj	*get_object_data(t_obj_type type)
{
	static const char	*t_form[3] = {
						"010",
						"111",
						"000"
	};
	static const char	*j_form[3] = {
						"001",
						"111",
						"000"
	};
	static const char	*l_form[3] = {
						"100",
						"111",
						"000"
	};
	static const char	*s_form[3] = {
						"0110",
						"1100",
						"0000"
	};
	static const char	*z_form[3] = {
						"1100",
						"0110",
						"0000"
	};
	static const char	*stick[4] = {
						"0000",
						"1111",
						"0000",
						"0000"
	};
	static const char	*block[2] = {
						"11",
						"11"
	};
	static t_obj		objs_data[7] = {
			{.type = BLOCK, .color = 0xFFD700, .design = block, .matrix_len = 2},
			{.type = T_OBJ, .color = 0xBA55D3, .design = t_form, .matrix_len = 3},
			{.type = J_OBJ, .color = 0xFF8C00, .design = j_form, .matrix_len = 3},
			{.type = L_OBJ, .color = 0x7B68EE, .design = l_form, .matrix_len = 3},
			{.type = S_OBJ, .color = 0x9ACD32, .design = s_form, .matrix_len = 3},
			{.type = Z_OBJ, .color = 0xFF4500, .design = z_form, .matrix_len = 3},
			{.type = STICK, .color = 0xADD8E6, .design = stick, .matrix_len = 4},
	};

	int			i;

	i = -1;
	while (++i < 7)
	{
		if (type == objs_data[i].type)
			return (&objs_data[i]);
	}
	return (NULL);
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
		while (object->design[iter.y][++iter.x])
		{
			if (object->design[iter.y][iter.x] == '1')
			{
				this_tile = &vars->tiles[iter.y][object->start_index + iter.x];
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
	vars->obj->start_index = ((TOTAL_TILE_X - datas->matrix_len) / 2);
	design_object(vars);
}

int	main(void)
{
	t_tetr	tetr;

	init_tetr(&tetr);
	// prompt_user(&tetr);
	setup_game(&tetr);
	render_map(&tetr, get_object_data(STICK));
	my_mlx_hooks(&tetr);
	mlx_loop(tetr.mlx);
	return (0);
}
