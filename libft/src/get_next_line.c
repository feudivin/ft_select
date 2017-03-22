/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfourne <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/01 13:50:16 by jfourne           #+#    #+#             */
/*   Updated: 2017/02/13 14:57:37 by jfourne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int					previous_line(char **str, char **line)
{
	int				stop;

	if (ft_strcmp(*str, "") != 0)
	{
		if (ft_strchr(*str, '\n') != NULL)
		{
			stop = ft_strchr(*str, '\n') - *str;
			*line = ft_strndup(*str, stop);
			*str = *str + stop + 1;
			*line[stop] = '\0';
			return (1);
		}
		else
		{
			*line = ft_strdup(*str);
			free(*str);
		}
	}
	return (0);
}

int					read_it(int *ret, char **line, const int fd)
{
	int				stop;
	char			buff[BUFF_SIZE + 1];

	stop = 0;
	while (stop == 0 && (*ret = read(fd, buff, BUFF_SIZE)) > 0)
	{
		buff[*ret] = '\0';
		if (ft_strchr(buff, '\n') != NULL)
			stop = 1;
		if ((*line = ft_strjoin_and_clean(*line, buff, 1)) == NULL)
			return (-1);
	}
	return (0);
}

int					create_str(char **str)
{
	if (*str == NULL)
	{
		if ((*str = ft_strdup("")) == NULL)
			return (-1);
	}
	return (0);
}

int					get_next_line(const int fd, char **line)
{
	int				stop;
	int				ret;
	static char		*str = NULL;

	if (fd < 0 || !line || BUFF_SIZE < 1)
		return (-1);
	if (create_str(&str) == -1)
		return (-1);
	*line = ft_strdup("");
	if (previous_line(&str, line) == 1)
		return (1);
	if (read_it(&ret, line, fd) == -1)
		return (-1);
	if (ft_strchr(*line, '\n') != NULL)
	{
		stop = ft_strchr(*line, '\n') - *line;
		free(str);
		if ((str = ft_strdup(*line + stop + 1)) == NULL)
			return (-1);
		(*line)[stop] = '\0';
	}
	if (ret < 1 && (*line)[0] == '\0')
		return (ret);
	return (1);
}
