/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tab_to_list_circle.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfourne <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/02 16:48:41 by jfourne           #+#    #+#             */
/*   Updated: 2017/03/02 17:04:08 by jfourne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_tab_to_list_circle(char **tab)
{
	int		i;
	t_list	*first;
	t_list	*lst;

	i = 1;
	if ((first = ft_lstnew(tab[0], ft_strlen(tab[0]))) == NULL)
		return (NULL);
	while (tab[i])
	{
		if ((lst = ft_lstnew(tab[i], ft_strlen(tab[i]))) == NULL)
			return (NULL);
		ft_lstback_circle(&first, lst, i);
		i++;
	}
	return (first);
}
