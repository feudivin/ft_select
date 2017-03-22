/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfourne <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/05 16:15:05 by jfourne           #+#    #+#             */
/*   Updated: 2016/11/10 15:03:00 by jfourne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>

void		ft_putendl(const char *s)
{
	char	c;

	c = '\n';
	if (!s)
		return ;
	write(1, s, ft_strlen(s));
	write(1, &c, 1);
}