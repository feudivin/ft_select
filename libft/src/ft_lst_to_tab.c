/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_to_tab.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfourne <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/13 14:21:31 by jfourne           #+#    #+#             */
/*   Updated: 2017/02/23 13:51:21 by jfourne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_lst_count(t_list *lst)
{
	int			i;

	i = 0;
	while (lst != NULL)
	{
		lst = lst->next;
		i++;
	}
	return (i);
}

char			**ft_lst_to_tab(t_list *lst)
{
	int			i;
	char		**tab;

	if ((tab = (char **)malloc((ft_lst_count(lst) + 1) *
					sizeof(char *))) == NULL)
		return (NULL);
	i = 0;
	while (lst != NULL)
	{
		if ((tab[i] = ft_strdup(lst->content)) == NULL)
			return (NULL);
		i++;
		lst = lst->next;
	}
	tab[i] = NULL;
	return (tab);
}
