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

int	main(int ac, char **av)
{
    t_tetr  tetr;

    init_tetr(&tetr);
    // prompt_user(&tetr);
    setup_game(&tetr);
    my_mlx_hooks(&tetr);
    mlx_loop(tetr.mlx);
    return (0);
}
