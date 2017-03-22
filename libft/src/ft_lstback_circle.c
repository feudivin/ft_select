/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstback_circle.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfourne <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/02 16:41:05 by jfourne           #+#    #+#             */
/*   Updated: 2017/03/02 17:17:12 by jfourne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_lstback_circle(t_list **alst, t_list *elem, int nb_elem)
{
	int		i;
	t_list	*tmp;

	i = 0;
	if (!alst || !elem)
		return ;
	tmp = *alst;
	while (i < nb_elem)
		tmp = tmp->next;
	tmp->next = elem;
	elem->prev = tmp;
	elem->next = *alst;
}
