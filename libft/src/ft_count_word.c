/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_word.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfourne <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/07 14:03:08 by jfourne           #+#    #+#             */
/*   Updated: 2017/02/23 13:51:04 by jfourne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_count_word(const char *str)
{
	int	i;
	int	word;

	i = 0;
	word = 0;
	if (ft_isalpha(str[0]) == 1)
		word = 1;
	while (str[i])
	{
		if (str[i] == ' ' && (str[i + 1] != '\0' || str[i + 1] != ' '))
			word++;
		i++;
	}
	return (word);
}
