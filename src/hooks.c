/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efinda <efinda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/24 17:51:07 by efinda            #+#    #+#             */
/*   Updated: 2025/05/24 17:53:28 by efinda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/tetr.h"

static int	my_mlx_close(t_tetr *tetr)
{
	deallocate_tetr(tetr, "The Game Was Closed Through The Window's Close Button.", 0);
	return (0);
}

static int	my_mlx_key_press(int keycode, t_tetr *tetr)
{
	t_obj		*object;
	static char	checker;

	if (keycode == ESC)
        deallocate_tetr(tetr, "The Game Was Closed Through The ESC Key Press.", 0);
	object = tetr->obj;
	if (keycode == UP)
	{
		write(1, "UP\n", 3);
		render_object(tetr, erase_object_tile);
		rotate_object(object);
		//Se o objecto está na parede esquerda e a sua rotação poderá faze-lo ir alem da parede
		if (!object->start_index.x && object->iterator.x)
			object->iterator.x = 0;
		render_object(tetr, paint_object_tile);
	}
	else if (keycode == LEFT)
	{
		render_object(tetr, erase_object_tile);
		//Se ainda pode ser decrementado
		if (object->start_index.x)
		{
			object->start_index.x--;
		}
		//Se o range do objecto esta na parede esquerda mais a sua forma fisica ainda não tocou
		else if (object->matrix_start.x && (object->matrix_start.x - object->iterator.x))
		{
			object->iterator.x++;
		}
		ft_printf("LEFT: %d\n", object->start_index.x);
		render_object(tetr, paint_object_tile);
	}
	else if (keycode == RIGHT)
	{
		render_object(tetr, erase_object_tile);
		//Verifica se o há colunas vazias dentro da matriz e se o iterador do objecto é diferente de zero
		if (object->matrix_start.x && object->iterator.x) //ERRO ESTÁ AQUI!!!!!!!!!!!!!!!!!!!!!!!!
		{
			object->iterator.x--;
		}
		//Se o índex de inicio dos tales mais o maior comprimento do objecto for menor que o numero de tiles em x, para evitar que ele vá além da tabela
		else if (object->start_index.x + get_greatest(object->matrix_len) < TOTAL_TILE_X)
		{
			object->start_index.x++;
		}
		//Se o range do objecto esta na parede direita mais a sua forma fisica ainda não tocou
		/*else if ((object->matrix_end.x + object->iterator.x) < get_greatest(object->matrix_len))
		{
			object->iterator.x++;
			checker = 1;
		}*/
		ft_printf("RIGHT: %d\n", object->start_index.x);
		render_object(tetr, paint_object_tile);
	}
	mlx_put_image_to_window(tetr->mlx, tetr->win, tetr->background_img.img, 0, 0);
	return (0);
}

static int	my_mlx_loop_hook(t_tetr *tetr)
{
	return (0);
}

void	my_mlx_hooks(t_tetr *tetr)
{
	mlx_hook(tetr->win, 2, 1L << 0, my_mlx_key_press, tetr);
	mlx_hook(tetr->win, 17, 1L << 17, my_mlx_close, tetr);
	mlx_loop_hook(tetr->mlx, my_mlx_loop_hook, tetr);
}