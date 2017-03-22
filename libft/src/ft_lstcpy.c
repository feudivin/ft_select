/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfourne <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/16 14:39:41 by jfourne           #+#    #+#             */
/*   Updated: 2017/02/23 13:51:34 by jfourne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list			*ft_lstcpy(t_list *alst)
{
	t_list		*cpy;
	t_list		*tmp;

	if ((cpy = ft_lstnew(alst->content, alst->content_size)) == NULL)
		return (NULL);
	alst = alst->next;
	while (alst != NULL)
	{
		if ((tmp = ft_lstnew(alst->content, alst->content_size)) == NULL)
			return (NULL);
		ft_lstback(&cpy, tmp);
		alst = alst->next;
	}
	return (cpy);
}
