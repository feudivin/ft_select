/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_binding_second.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfourne <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/15 13:37:46 by jfourne           #+#    #+#             */
/*   Updated: 2017/03/22 12:45:09 by jfourne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

int				key_delete(char *buf, t_list **arg)
{
	int			stop;
	t_list		*tmp;

	stop = 0;
	if ((buf[0] == 127 && buf[1] == 0 && buf[2] == 0) ||
			(buf[0] == 27 && buf[1] == 91 && buf[2] == 51))
	{
		tmp = *arg;
		while (tmp && tmp->cursor != 1)
			tmp = tmp->next;
		if (tmp->next)
			tmp->next->cursor = 1;
		else
			(*arg)->cursor = 1;
		if (tmp == *arg && tmp->next == NULL)
			stop = 1;
		ft_lstfree_one(arg, &tmp);
		clear_window();
		if (stop == 1)
			return (2);
		return (1);
	}
	return (0);
}

int				key_clear_refresh(char *buf, t_list **arg)
{
	struct winsize w;

	if (buf[0] == -62 && buf[1] == 0 && buf[2] == 0)
	{
		clear_window();
		get_size(&w);
		print_choice(arg, w, NULL);
		return (1);
	}
	return (0);
}

int				key_arrow_left(char *buf, t_list **arg, struct winsize w)
{
	int			i;
	t_list		*tmp;

	i = 0;
	if (buf[0] == 27 && buf[1] == 91 && buf[2] == 68)
	{
		tmp = *arg;
		while (tmp && tmp->cursor == 0)
			tmp = tmp->next;
		tmp->cursor = 0;
		while (tmp && i < w.ws_row - 2)
		{
			i++;
			tmp = tmp->prev;
		}
		if (tmp == NULL)
			tmp = *arg;
		tmp->cursor = 1;
		return (1);
	}
	return (0);
}

int				key_arrow_right(char *buf, t_list **arg, struct winsize w)
{
	int			i;
	t_list		*tmp;

	i = 0;
	if (buf[0] == 27 && buf[1] == 91 && buf[2] == 67)
	{
		tmp = *arg;
		while (tmp && tmp->cursor == 0)
			tmp = tmp->next;
		tmp->cursor = 0;
		while (tmp && i < w.ws_row - 2)
		{
			i++;
			tmp = tmp->next;
		}
		if (tmp == NULL)
			tmp = *arg;
		tmp->cursor = 1;
		return (1);
	}
	return (0);
}
