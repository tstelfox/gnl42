/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line_bonus.h                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: tmullan <tmullan@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/02 15:50:51 by tmullan        #+#    #+#                */
/*   Updated: 2020/01/10 21:30:28 by tmullan       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef _GET_NEXT_LINE_H
# define _GET_NEXT_LINE_H
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif
# ifndef FD_MAX
#  define FD_MAX 1024
# endif
# include <stdlib.h>
# include <unistd.h>
# include <strings.h>

char	*ft_strjoin(char *s1, char *s2);
size_t	ft_strlen(char *s);
void	*ft_memmove(void *dst, void *src, size_t len);
char	*ft_strdup(char *s1);
int		get_next_line(int fd, char **line);
#endif
