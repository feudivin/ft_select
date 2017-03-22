/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup_clean.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfourne <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/01 15:18:13 by jfourne           #+#    #+#             */
/*   Updated: 2017/02/01 15:20:51 by jfourne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_my_strlen(const char *str)
{
	int		i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char		*ft_strdup_clean(char *s)
{
	int		i;
	char	*dup;

	i = 0;
	if ((dup = malloc((ft_my_strlen(s) + 1) * sizeof(char))) == 0)
		return (NULL);
	while (s[i])
	{
		dup[i] = s[i];
		i++;
	}
	free(s);
	dup[i] = '\0';
	return (dup);
}
