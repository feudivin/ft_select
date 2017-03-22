/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfourne <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/01 13:57:26 by jfourne           #+#    #+#             */
/*   Updated: 2017/02/13 14:58:32 by jfourne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <sys/types.h>
# include <sys/uio.h>
# include <unistd.h>
# include <stdlib.h>
# include "libft.h"
# define BUFF_SIZE 100

int				get_next_line(const int fd, char **line);
char			*ft_strchr(const char *s, int c);
char			*ft_strjoin_and_clean(char *s1, char *s2, int clean);
char			*ft_strdup(const char *s);

#endif
