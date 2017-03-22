/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_select.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfourne <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/24 16:45:56 by jfourne           #+#    #+#             */
/*   Updated: 2017/03/22 13:11:26 by jfourne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SELECT_H
# define FT_SELECT_H

# include "../libft/include/libft.h"
# include <termios.h>
# include <unistd.h>
# include <curses.h>
# include <term.h>
# include <fcntl.h>
# include <signal.h>
# include <sys/ioctl.h>

# define MAX_KEY	4
# define CYAN		"\x1b[36m"
# define L_CYAN		"\x1b[96m"
# define L_MAGENTA	"\x1b[95m"
# define GREEN		"\x1b[32m"
# define YELLOW		"\x1b[33m"
# define RESET		"\x1b[0m"
# define BG_GREEN	"\x1b[42m"
# define BG_WHITE	"\x1b[47m"
# define BG_BLACK	"\x1b[40m"

int				key_return(char *buf, t_list **arg);
int				key_ctrl_d(char *buf, t_list **arg);
int				key_space(char *buf, t_list **arg);
int				key_clear_refresh(char *buf, t_list **arg);
int				key_arrow_left(char *buf, t_list **arg, struct winsize w);
int				key_arrow_up(char *buf, t_list **arg);
int				key_arrow_down(char *buf, t_list **arg);
int				key_arrow_right(char *buf, t_list **arg, struct winsize w);
int				key_delete(char *buf, t_list **arg);
int				key_letter(char *buf, t_list **arg, char **search,
							t_list *tmp);
void			underline(void);
void			reverse_video(void);
void			normal_video(void);
void			reverse_underline(void);
int				my_putc(int c);
int				init_tty(void);
bool			init_term(void);
void			init_window(void);
void			get_size(struct winsize *w);
void			reset_term(void);
void			print_choice(t_list **arg, struct winsize w, char *search);
void			ft_select(t_list **arg, int i, int ret);
void			ft_print_key(char *buf, size_t len);
void			init_signal(void);
void			sig_resize(int sig);
void			clear_window(void);
void			print_frame(struct winsize w);
void			print_with_color(char *str);

#endif
