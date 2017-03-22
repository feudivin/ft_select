/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_putc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfourne <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/15 13:42:59 by jfourne           #+#    #+#             */
/*   Updated: 2017/03/15 13:43:58 by jfourne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

int					my_putc(int c)
{
	int				tty;

	if ((tty = init_tty()) == -1)
		return (-1);
	ft_putchar_fd(c, tty);
	return (0);
}
