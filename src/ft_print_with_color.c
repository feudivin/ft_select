/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_with_color.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfourne <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/22 12:37:36 by jfourne           #+#    #+#             */
/*   Updated: 2017/03/22 12:38:15 by jfourne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

void				check_extension(char *str)
{
	size_t			i;

	i = ft_strlen(str) - 1;
	while (i > 0 && str[i] != '.')
		i--;
	if (strcmp(str + i, ".c") == 0)
		ft_putstr_fd(GREEN, init_tty());
	if (strcmp(str + i, ".h") == 0)
		ft_putstr_fd(YELLOW, init_tty());
}

void				print_with_color(char *str)
{
	int				fd;

	if ((fd = open(str, O_DIRECTORY)) > -1)
	{
		close(fd);
		ft_putstr_fd(L_CYAN, init_tty());
	}
	check_extension(str);
	ft_putstr_fd(str, init_tty());
	ft_putstr_fd(RESET, init_tty());
}
