/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line_bonus.c                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: tmullan <tmullan@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/10 21:29:32 by tmullan        #+#    #+#                */
/*   Updated: 2020/01/10 21:45:14 by tmullan       ########   odam.nl         */
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
	if (*line == NULL)
		return (-1);
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
		return (1);
	}
}

int		remaining(char *buff, char **line)
{
	if (buff[0] == '\n')
	{
		*line = ft_strdup("");
		ft_memmove(buff, buff + 1, ft_strlen(buff));
		return (*line == 0 ? -1 : 1);
	}
	if (newline(buff))
	{
		if (!*line)
		{
			*line = ft_strdup(buff);
			ft_memmove(buff, buff + (newline(buff) + 1),
			ft_strlen(buff));
			return (*line == 0 ? -1 : 1);
		}
		else
		{
			*line = ft_strjoin(*line, buff);
			return (*line == 0 ? -1 : 1);
		}
	}
	else
		return ((*line = ft_strdup(buff)) ? 0 : -1);
}

int		get_next_line(int fd, char **line)
{
	static char	buff[FD_MAX][BUFFER_SIZE + 1];
	int			res;
	int			ret;

	*line = NULL;
	res = 1;
	if (*buff[fd] != '\0')
	{
		ret = remaining(buff[fd], line);
		if (ret != 0)
			return (ret);
	}
	while (res)
	{
		res = read(fd, buff[fd], BUFFER_SIZE);
		if (res == -1 || fd < 0)
			return (-1);
		buff[fd][res] = '\0';
		ret = processbuff(buff[fd], line);
		if (ret != 0)
			return (ret);
	}
	return (0);
}
