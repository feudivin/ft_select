/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfourne <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/02 17:52:27 by jfourne           #+#    #+#             */
/*   Updated: 2017/02/01 15:50:35 by jfourne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char		*ft_strndup(const char *s, int a)
{
	int		i;
	char	*dup;

	i = 0;
	if ((dup = malloc((a + 1) * sizeof(char))) == 0)
		return (NULL);
	while (s[i] && i < a)
	{
		dup[i] = s[i];
		i++;
	}
	dup[i] = '\0';
	return (dup);
}
