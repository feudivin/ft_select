/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_binding.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfourne <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/15 13:33:16 by jfourne           #+#    #+#             */
/*   Updated: 2017/03/20 16:40:43 by jfourne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

int					key_return(char *buf, t_list **arg)
{
	t_list			*tmp;
	int				first;

	first = 0;
	tmp = *arg;
	if (buf[0] == 10 && buf[1] == 0 && buf[2] == 0)
	{
		while (tmp)
		{
			if (tmp->select == 1)
			{
				if (first == 1)
					ft_putchar(' ');
				if (first == 0)
					first = 1;
				ft_putstr(tmp->content);
			}
			tmp = tmp->next;
		}
		return (2);
	}
	return (0);
}

int					key_ctrl_d(char *buf, t_list **arg)
{
	(void)arg;
	if ((buf[0] == 4 && buf[1] == 0 && buf[2] == 0) ||
			(buf[0] == 27 && buf[1] == 0 && buf[2] == 0))
		return (2);
	return (0);
}

int					key_space(char *buf, t_list **arg)
{
	t_list			*tmp;

	if (buf[0] == 32 && buf[1] == 0 && buf[2] == 0)
	{
		tmp = *arg;
		while (tmp && tmp->cursor != 1)
			tmp = tmp->next;
		if (tmp->select == 0)
			tmp->select = 1;
		else
			tmp->select = 0;
		tmp->cursor = 0;
		if (tmp->next)
			tmp->next->cursor = 1;
		else
			(*arg)->cursor = 1;
		return (1);
	}
	return (0);
}

int					key_arrow_up(char *buf, t_list **arg)
{
	t_list			*tmp;

	if (buf[0] == 27 && buf[1] == 91 && buf[2] == 65)
	{
		tmp = *arg;
		while (tmp != NULL && tmp->cursor != 1)
			tmp = tmp->next;
		tmp->cursor = 0;
		if (tmp->prev != NULL)
			tmp = tmp->prev;
		else
		{
			while (tmp->next)
				tmp = tmp->next;
		}
		tmp->cursor = 1;
		return (1);
	}
	return (0);
}

int					key_arrow_down(char *buf, t_list **arg)
{
	t_list			*tmp;

	if (buf[0] == 27 && buf[1] == 91 && buf[2] == 66)
	{
		tmp = *arg;
		while (tmp != NULL && tmp->cursor != 1)
			tmp = tmp->next;
		tmp->cursor = 0;
		tmp = tmp->next;
		if (tmp == NULL)
			tmp = *arg;
		tmp->cursor = 1;
		return (1);
	}
	return (0);
}
