/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   testmain.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: mjiam <mjiam@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/28 16:45:21 by mjiam          #+#    #+#                */
/*   Updated: 2020/01/08 21:10:53 by tmullan       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>

int	main(int argc, char **argv)
{
	char	*readline;
	int		fd;
	int		fnreturn = 0;
	int		linecount = 0;

	if (argc)
	{
		if (argc == 1)
			fd = 0;
		else
			fd = open(argv[1], O_RDONLY);
		while ((fnreturn = get_next_line(fd, &readline)))
		{
			linecount++;
			printf("Read line: %s\n", readline);
			printf("Fn return: %d\n", fnreturn);
			free(readline);
		}
		if (fnreturn == 0)
		{
			linecount++;
			printf("Read line: %s\n", readline);
			printf("Fn return: %d\n", fnreturn);
			free(readline);
		}
		printf("Line count: %d\n", linecount);
	}
    /* for checking leaks */
	while (1)
	{}
	return (0);
}
