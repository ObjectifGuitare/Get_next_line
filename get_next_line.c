/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seb <seb@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/10 00:53:22 by spatez            #+#    #+#             */
/*   Updated: 2021/06/23 14:15:49 by seb              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

#include <stdio.h>

ssize_t	ft_line_return_check(char *buffer)
{
	// returns the index for the first occurence of \n
	// -1 if \n not found or if buffer == null
	int i;

	if (!buffer)
		return (-1);
	i = -1;
	while (buffer[++i])
    {
		if (buffer[i] == '\n')
		{
            if (i < BUFFER_SIZE - 1)
                buffer[i] = '\0';
            return (i);
        }
    }
	return (-1);
}

char *ft_read(int fd, char *buffer)
{
    bool eof;
    char *dst;

	dst = NULL;
	while (ft_line_return_check(dst) == -1)
	{
		buffer = malloc(BUFFER_SIZE + 1);
		if (!buffer)
			return (NULL);
		if (!read(fd, buffer, BUFFER_SIZE))
			eof = 1;
		buffer[BUFFER_SIZE] = '\0';
		dst = ft_strjoin(dst, buffer);
		// printf("%s\n", dst);
		// printf("%s\n", buffer);
	}
    return (dst);
}

int get_next_line(int fd, char **line)
{
	char *buffer;
	// check errors
	buffer = NULL;
    *line = ft_read(fd, buffer);
	printf("%s\n", *line);
    return(1);
}
