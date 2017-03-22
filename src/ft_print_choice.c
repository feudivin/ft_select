/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_choice.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfourne <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/22 12:36:01 by jfourne           #+#    #+#             */
/*   Updated: 2017/03/22 12:40:12 by jfourne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

void				init_print(struct winsize *coord, struct winsize w,
								char *clearstr, char *search)
{
	coord->ws_row = 1;
	coord->ws_col = 1;
	print_frame(w);
	tputs(tgoto(clearstr, 0, 0), init_tty(), &my_putc);
	ft_putstr_fd(search, init_tty());
	tputs(tgoto(clearstr, coord->ws_col, coord->ws_row), init_tty(), &my_putc);
}

int					check_row(struct winsize *coord, t_list *tmp,
								struct winsize w, char *clearstr)
{
	coord->ws_row = 1;
	if (coord->ws_col + ft_strlen(tmp->content) + 1 >= w.ws_col)
	{
		clear_window();
		tputs(tgoto(clearstr, 1, 1), init_tty(), &my_putc);
		ft_putstr_fd("ft_select can't display all choices\n", 1);
		return (-1);
	}
	tputs(tgoto(clearstr, coord->ws_col, coord->ws_row), init_tty(), &my_putc);
	return (0);
}

int					check_col(struct winsize w, t_list *tmp, int *max_x,
								char *clearstr)
{
	if (ft_strlen(tmp->content) > (size_t)(*max_x))
		*max_x = (int)ft_strlen(tmp->content);
	if (ft_strlen(tmp->content) > (size_t)w.ws_col)
	{
		clear_window();
		tputs(tgoto(clearstr, 1, 1), 1, &my_putc);
		ft_putstr_fd("ft_select can't display all choices\n", 1);
		return (-1);
	}
	return (0);
}

void				print_selected(t_list *tmp, struct winsize *coord,
									char *clearstr)
{
	if (tmp->select == 1)
		reverse_video();
	if (tmp->cursor == 1)
		underline();
	print_with_color(tmp->content);
	coord->ws_row += 1;
	tputs(tgoto(clearstr, coord->ws_col, coord->ws_row), init_tty(), &my_putc);
	if (tmp->cursor == 1)
		reverse_underline();
	if (tmp->select == 1)
		normal_video();
}

void				print_choice(t_list **arg, struct winsize w, char *search)
{
	t_list			*tmp;
	int				max_x;
	struct winsize	coord;
	char			*clearstr;

	if ((clearstr = tgetstr("cm", NULL)) == NULL)
		return ;
	max_x = 0;
	init_print(&coord, w, clearstr, search);
	tmp = *arg;
	while (tmp != NULL)
	{
		if (coord.ws_row + 1 >= w.ws_row)
		{
			coord.ws_col += max_x + 2;
			if (check_row(&coord, tmp, w, clearstr) == -1)
				return ;
		}
		if (check_col(w, tmp, &max_x, clearstr) == -1)
			return ;
		print_selected(tmp, &coord, clearstr);
		tmp = tmp->next;
	}
}
