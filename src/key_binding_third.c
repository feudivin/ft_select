/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_binding_third.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfourne <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/22 12:44:16 by jfourne           #+#    #+#             */
/*   Updated: 2017/03/22 14:52:07 by jfourne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

void			check_del_letter(char *buf, char **search)
{
	if (buf[0] == 27 && buf[1] == 91 && buf[2] == 70)
	{
		if (*search != NULL)
		{
			free(*search);
			*search = NULL;
		}
	}
}

int				key_letter(char *buf, t_list **arg, char **search, t_list *tmp)
{
	char		*clearstr;
	t_list		*current;

	clearstr = tgetstr("cm", NULL);
	check_del_letter(buf, search);
	if (ft_isprint(buf[0]) && buf[1] == 0 && buf[2] == 0)
	{
		current = *arg;
		tmp = *arg;
		if (*search == NULL)
			*search = ft_strdup(buf);
		else
			*search = ft_strjoin_and_clean(*search, buf, 1);
		while (tmp && ft_strstr(tmp->content, *search) == NULL)
			tmp = tmp->next;
		if (tmp != NULL)
		{
			while (current && current->cursor == 0)
				current = current->next;
			current->cursor = 0;
			tmp->cursor = 1;
		}
		return (1);
	}
	return (0);
}
