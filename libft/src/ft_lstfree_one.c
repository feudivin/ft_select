/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstfree_one.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfourne <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/15 15:45:25 by jfourne           #+#    #+#             */
/*   Updated: 2017/02/16 15:33:42 by jfourne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			ft_lstfree_one(t_list **alst, t_list **tmp)
{
	free((*tmp)->content);
	if ((*tmp)->prev)
		(*tmp)->prev->next = (*tmp)->next;
	else
		*alst = (*tmp)->next;
	if ((*tmp)->next)
		(*tmp)->next->prev = (*tmp)->prev;
	free(*tmp);
	return (0);
}
