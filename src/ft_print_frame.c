/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_frame.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfourne <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/22 12:17:13 by jfourne           #+#    #+#             */
/*   Updated: 2017/03/22 12:18:38 by jfourne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

void				color_line(struct winsize w, struct winsize coord,
								char *clearstr)
{
	while (coord.ws_col + 1 <= w.ws_col)
	{
		ft_putchar_fd(' ', init_tty());
		coord.ws_col++;
		tputs(tgoto(clearstr, coord.ws_col, coord.ws_row), init_tty(),
				&my_putc);
	}
}

void				color_col(struct winsize w, struct winsize coord,
								char *clearstr)
{
	while (coord.ws_row + 1 <= w.ws_row)
	{
		ft_putchar_fd(' ', init_tty());
		coord.ws_row++;
		tputs(tgoto(clearstr, coord.ws_col, coord.ws_row), init_tty(),
				&my_putc);
	}
}

void				print_frame(struct winsize w)
{
	char			*clearstr;
	struct winsize	coord;

	if ((clearstr = tgetstr("cm", NULL)) == NULL)
		return ;
	coord.ws_row = 0;
	coord.ws_col = 0;
	ft_putstr_fd(BG_GREEN, init_tty());
	tputs(tgoto(clearstr, coord.ws_col, coord.ws_row), init_tty(), &my_putc);
	color_line(w, coord, clearstr);
	tputs(tgoto(clearstr, coord.ws_col, coord.ws_row), init_tty(), &my_putc);
	color_col(w, coord, clearstr);
	coord.ws_row = w.ws_row - 1;
	tputs(tgoto(clearstr, coord.ws_col, coord.ws_row), init_tty(), &my_putc);
	color_line(w, coord, clearstr);
	coord.ws_col = w.ws_col - 1;
	coord.ws_row = 0;
	tputs(tgoto(clearstr, coord.ws_col, coord.ws_row), init_tty(), &my_putc);
	color_col(w, coord, clearstr);
	ft_putstr_fd(BG_BLACK, init_tty());
}
