/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfourne <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/28 16:06:53 by jfourne           #+#    #+#             */
/*   Updated: 2017/03/24 16:43:22 by jfourne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

void				clear_window(void)
{
	char			*clearstr;

	if ((clearstr = tgetstr("cl", NULL)) == NULL)
		return ;
	tputs(clearstr, 1, &my_putc);
}

void				print_end(t_list *arg)
{
	int				first;
	t_list			*tmp;

	first = 0;
	tmp = arg;
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
}

int					main(int ac, char **av)
{
	int				ret;
	t_list			*arg;

	if (ac < 2)
	{
		ft_putendl_fd("error", 2);
		return (-1);
	}
	init_signal();
	if ((arg = ft_tab_to_list(av + 1)) == NULL)
		return (-1);
	if (init_term() == FALSE)
	{
		reset_term();
		return (-1);
	}
	ret = 0;
	ft_select(&arg, 0, &ret);
	reset_term();
	if (ret == 3)
		print_end(arg);
	ft_lstfree(&arg);
	return (0);
}
