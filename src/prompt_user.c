/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt_user.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efinda <efinda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/24 14:54:44 by efinda            #+#    #+#             */
/*   Updated: 2025/05/24 17:31:38 by efinda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/tetr.h"

void    prompt_user(t_tetr *tetr)
{
    ft_printf("\033[2J\033[H");
    ft_printf(BOLD_ANSI CYAN_ANSI "\n\n");
    ft_printf("\t████████╗███████╗████████╗██████╗ \n");
	ft_printf("\t╚══██╔══╝██╔════╝╚══██╔══╝██╔══██╗\n");
	ft_printf("\t   ██║   █████╗     ██║   ██████╔╝\n");
	ft_printf("\t   ██║   ██╔══╝     ██║   ██╔═══╝ \n");
	ft_printf("\t   ██║   ███████╗   ██║   ██║  ██╗\n");
	ft_printf("\t   ╚═╝   ╚══════╝   ╚═╝   ╚═╝  ╚═╝\n\n" RESET_ANSI);
	ft_printf(BOLD_ANSI GREEN_ANSI "\t        Welcome to 42 Tetr!\n\n" RESET_ANSI);
	ft_printf(YELLOW_ANSI "\t Controls:\n");
	ft_printf("\t  →  Move Right\n");
	ft_printf("\t  ←  Move Left\n");
	ft_printf("\t  ↑  Rotate Piece\n");
	ft_printf("\t  ↓  Soft Drop\n");
	ft_printf("\t  Spacebar  Hard Drop\n");
	ft_printf("\t  P         Pause\n" RESET_ANSI);
	ft_printf(BLUE_ANSI "\n\t Clear lines, score high, and don't stack too high!\n" RESET_ANSI);
    usleep(5 * 1000000);
    ft_printf("\033[2J\033[H");
    ft_printf(GREEN_ANSI BOLD_ANSI "Before we start, enter you username: " RESET_ANSI);
    tetr->player.name = get_next_line(0);
    if (!tetr->player.name)
        deallocate_tetr(tetr, "Exiting because Ctrl-D was pressed.", 0);
    ft_printf("\033[2J\033[H");
}
