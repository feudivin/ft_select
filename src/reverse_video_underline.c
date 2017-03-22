/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_video_underline.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfourne <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/15 13:40:40 by jfourne           #+#    #+#             */
/*   Updated: 2017/03/22 12:40:33 by jfourne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

void				underline(void)
{
	char			*clearstr;

	if ((clearstr = tgetstr("us", NULL)) == NULL)
		return ;
	tputs(clearstr, 1, &my_putc);
}

void				reverse_video(void)
{
	char			*clearstr;

	if ((clearstr = tgetstr("mr", NULL)) == NULL)
		return ;
	tputs(clearstr, 1, &my_putc);
}

void				reverse_underline(void)
{
	char			*clearstr;

	if ((clearstr = tgetstr("ue", NULL)) == NULL)
		return ;
	tputs(clearstr, 1, &my_putc);
}

void				normal_video(void)
{
	char			*clearstr;

	if ((clearstr = tgetstr("me", NULL)) == NULL)
		return ;
	tputs(clearstr, 1, &my_putc);
}
