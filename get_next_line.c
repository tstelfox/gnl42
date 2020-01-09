/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: tmullan <tmullan@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/07 12:44:10 by tmullan        #+#    #+#                */
/*   Updated: 2020/01/08 21:18:47 by tmullan       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		newline(char *buff)
{
	int i;

	i = 0;
	while (buff[i])
	{
		if (buff[i] == '\n')
			return (i);
		i++;
	}
	return (0);
}

int		processbuff(char *buff, char **line)
{
	int len;

	len = newline(buff);
	if (!*line)
		*line = ft_strdup(buff);
	else
		*line = ft_strjoin(*line, buff);
	if (buff[0] == '\n')
	{
		ft_memmove(buff, buff + 1, ft_strlen(buff));
		return (1);
	}
	if (!newline(buff))
		return (0);
	else
	{
		ft_memmove(buff, buff + (len + 1), ft_strlen(buff));
		while ((ft_strlen(buff) - (len + 1) < ft_strlen(buff)))
		{
			buff[strlen(buff)] = '\0';
			len--;
		}
		return (1);
	}
}

int		get_next_line(int fd, char **line)
{
	static char	buff[BUFFER_SIZE + 1];
	int			res;

	*line = NULL;
	res = 1;
	if (*buff != '\0')
	{
		if (buff[0] == '\n')
		{
			*line = ft_strdup("");
			ft_memmove(buff, buff + 1, ft_strlen(buff));
			return (1);
		}
		if (newline(buff))
		{
			if (!*line)
			{
				*line = ft_strdup(buff);
				ft_memmove(buff, buff + (newline(buff) + 1), ft_strlen(buff));
				return (1);
			}
			else
			{
				*line = ft_strjoin(*line, buff);
				return (1);
			}
		}
		else
			*line = ft_strdup(buff);
	}
	while (res)
	{
		res = read(fd, buff, BUFFER_SIZE);
		if (res == -1)
			return (-1);
		buff[res] = '\0';
		if (processbuff(buff, line))
			return (1);
	}
	return (0);
}
