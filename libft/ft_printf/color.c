/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgalvani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/31 17:01:24 by jgalvani          #+#    #+#             */
/*   Updated: 2017/08/29 21:11:49 by jgalvani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	color(int color)
{
	if (color == BLACK)
		write(1, "\033[0;40;30m", 11);
	else if (color == RED)
		write(1, "\033[0;40;31m", 11);
	else if (color == GREEN)
		write(1, "\033[0;40;32m", 11);
	else if (color == YELLOW)
		write(1, "\033[0;40;33m", 11);
	else if (color == BLUE)
		write(1, "\033[0;40;34m", 11);
	else if (color == PURPLE)
		write(1, "\033[0;40;35m", 11);
	else if (color == CYAN)
		write(1, "\033[0;40;36m", 11);
	else if (color == WHITE)
		write(1, "\033[0;40;37m", 11);
	else if (color == STOP)
		write(1, "\033[0m", 5);
}

void	string_protection(char *str, t_data *data)
{
	if (!str)
	{
		write(1, "(null)", 6);
		data->ret += 6;
	}
}
