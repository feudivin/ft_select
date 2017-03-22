/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfourne <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/28 16:06:53 by jfourne           #+#    #+#             */
/*   Updated: 2017/03/22 13:05:48 by jfourne          ###   ########.fr       */
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

int					main(int ac, char **av)
{
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
	ft_select(&arg, 0, 0);
	ft_lstfree(&arg);
	reset_term();
	return (0);
}
