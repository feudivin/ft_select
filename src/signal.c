/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfourne <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/15 16:16:52 by jfourne           #+#    #+#             */
/*   Updated: 2017/03/22 12:41:15 by jfourne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

void				sig_stop(int sig)
{
	char			key[4];
	struct termios	suspend;

	(void)sig;
	if (tcgetattr(0, &suspend) == -1)
	{
		ft_putendl_fd("ft_select: could not get termios", 2);
		return ;
	}
	key[0] = suspend.c_cc[VSUSP];
	key[1] = 0;
	key[2] = 0;
	key[3] = 0;
	reset_term();
	signal(SIGTSTP, SIG_DFL);
	signal(SIGINT, SIG_DFL);
	signal(SIGWINCH, SIG_DFL);
	ioctl(0, TIOCSTI, key);
}

void				sig_cont(int sig)
{
	init_term();
	init_signal();
	init_window();
	sig_resize(sig);
}

void				sig_resize(int sig)
{
	char			key[4];

	(void)sig;
	key[0] = -62;
	key[1] = 0;
	key[2] = 0;
	key[3] = '\0';
	ioctl(0, TIOCSTI, key);
}

void				sig_int(int sig)
{
	char			key[4];

	(void)sig;
	key[0] = 4;
	key[1] = 0;
	key[2] = 0;
	key[3] = 0;
	ioctl(0, TIOCSTI, key);
}

void				init_signal(void)
{
	if (signal(SIGTSTP, sig_stop) == SIG_ERR)
		ft_putendl_fd("error signal suspend", 2);
	if (signal(SIGCONT, sig_cont) == SIG_ERR)
		ft_putendl_fd("error signal continue", 2);
	if (signal(SIGWINCH, sig_resize) == SIG_ERR)
		ft_putendl_fd("error signal resize", 2);
	if (signal(SIGINT, sig_int) == SIG_ERR)
		ft_putendl_fd("error signal int", 2);
}
