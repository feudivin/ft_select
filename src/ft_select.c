/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_select.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfourne <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/15 13:51:20 by jfourne           #+#    #+#             */
/*   Updated: 2017/03/24 16:42:11 by jfourne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

int			(*g_func_tab[])(char *, t_list **) = {
	&key_ctrl_d,
	&key_arrow_up,
	&key_arrow_down,
	&key_space,
	&key_return,
	&key_delete,
	&key_clear_refresh,
	NULL};

static void			init_select(t_list **arg, bool *stop)
{
	t_list			*tmp;

	*stop = FALSE;
	tmp = *arg;
	while (tmp != NULL)
	{
		tmp->cursor = 0;
		tmp->select = 0;
		tmp = tmp->next;
	}
	(*arg)->cursor = 1;
	init_window();
}

void				other_key(char *buf, t_list **arg, struct winsize w,
								char **search)
{
	if (buf[0] == 126 && buf[1] == 0 && buf[2] == 0)
		return ;
	key_letter(buf, arg, search, NULL);
	key_arrow_right(buf, arg, w);
	key_arrow_left(buf, arg, w);
}

void				ft_select(t_list **arg, int i, int *ret)
{
	bool			stop;
	struct winsize	w;
	char			buf[MAX_KEY];
	char			*search;

	init_select(arg, &stop);
	search = NULL;
	while (stop == FALSE)
	{
		i = 0;
		ft_memset(&buf, 0, MAX_KEY);
		get_size(&w);
		print_choice(arg, w, search);
		if ((*ret = read(0, buf, MAX_KEY - 1)) == -1)
			return ;
		buf[*ret] = '\0';
		while (g_func_tab[i] != NULL && (*ret = g_func_tab[i](buf, arg)) == 0)
			i++;
		if (*ret == 0)
			other_key(buf, arg, w, &search);
		if (*ret == 2 || *ret == 3)
			stop = TRUE;
	}
	if (search)
		free(search);
}
