/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_term_tty.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfourne <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/15 13:45:32 by jfourne           #+#    #+#             */
/*   Updated: 2017/03/24 16:42:52 by jfourne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

int					init_tty(void)
{
	int				tty;

	tty = 2;
	if (isatty(tty))
		return (tty);
	return (-1);
}

bool				init_term(void)
{
	struct termios	my_term;

	if (tcgetattr(0, &my_term) == -1)
	{
		ft_putendl_fd("ft_select: could not get termios", 2);
		return (FALSE);
	}
	my_term.c_lflag &= ~ICANON;
	my_term.c_lflag &= ~ECHO;
	my_term.c_oflag &= ~OPOST;
	my_term.c_cc[VMIN] = 1;
	my_term.c_cc[VTIME] = 0;
	if (tcsetattr(0, TCSADRAIN, &my_term) == -1)
	{
		ft_putendl_fd("ft_select: could not set terminale", 2);
		return (FALSE);
	}
	if (tgetent(NULL, getenv("TERM")) == ERR)
		return (FALSE);
	return (TRUE);
}

void				init_window(void)
{
	char			*clearstr;

	if ((clearstr = tgetstr("vi", NULL)) == NULL)
		return ;
	tputs(clearstr, 1, &my_putc);
	if ((clearstr = tgetstr("ti", NULL)) == NULL)
		return ;
	tputs(clearstr, 1, &my_putc);
}

void				get_size(struct winsize *w)
{
	ioctl(0, TIOCGWINSZ, w);
}

void				reset_term(void)
{
	struct termios	my_term;
	char			*clearstr;

	if (tcgetattr(0, &my_term) == -1)
	{
		ft_putendl_fd("ft_select: could not get termios", 2);
		return ;
	}
	my_term.c_lflag |= ICANON;
	my_term.c_lflag |= ECHO;
	my_term.c_oflag |= OPOST;
	if (tcsetattr(0, TCSADRAIN, &my_term) == -1)
	{
		ft_putendl_fd("ft_select: could not set terminale", 2);
		return ;
	}
	if ((clearstr = tgetstr("ve", NULL)) == NULL)
		return ;
	tputs(clearstr, 1, &my_putc);
	if ((clearstr = tgetstr("te", NULL)) == NULL)
		return ;
	tputs(clearstr, 1, &my_putc);
}
