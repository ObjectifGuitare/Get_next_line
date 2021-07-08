/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seb <seb@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/10 00:53:22 by spatez            #+#    #+#             */
/*   Updated: 2021/07/05 10:55:43 by seb              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

#include <stdio.h>

size_t	ft_line_return_check(char *buffer)
{
	// returns the index + 1 for the first occurence of \n
	// 0 if \n not found or if buffer == null
	int i;

    printf("entering line return check\n");
	if (!buffer)
		return (0);
    printf("buffer was not NULL\n");
	i = -1;
	while (buffer[++i])
    {
        // printf("entering loop in line return check\n");
		if (buffer[i] == '\n')
		{
            printf("line return was found in buffer\n");
            buffer[i] = '\0';
            return (i + 1);
        }
    }
    printf("no backslash n was found\n");
	return (0);
}

char *ft_read(int fd, char *buffer, int i)
{
    char *dst;
    
    printf("entering ft_read\n");
	dst = NULL;
    printf("value of i is : %i\n", i);
    if (i)
    {
        printf("entering i condition to read further\n");
        if (read(fd, buffer, i) == 0)
        {
            printf("returning eof\n");
            return ("\n");
        }
    }
    else
        printf("read's stream has not been increased\n");
	while (ft_line_return_check(dst) == 0)
	{
        printf("entering ft_read loop\n");
		buffer = malloc(BUFFER_SIZE + 1);
		if (!buffer)
			return (NULL);
        read(fd, buffer, BUFFER_SIZE);
        buffer[BUFFER_SIZE] = '\0';
        printf("mon buffer après read est : |%s|\n", buffer);
		dst = ft_strjoin(dst, buffer);
        printf("the value of my static variable is : %i\n", i);
        printf("my line until now is : |%s|\n", dst);
	}
    printf("the line to be returned in ft_read is : |%s|\n", dst);
    printf("the final value of my static variable is : %i\n", i);
    return (dst);
}

int get_next_line(int fd, char **line)
{
	char *buffer;
    static int i;
	// check errors
	buffer = NULL;
    
    i = 0;
    // printf("starting get next line for the %i time\n", ++i);
    *line = ft_read(fd, buffer, i);
    printf("ft read passed succesfully\n");
    i += ft_strlen(*line);
    if (!*line)
        return (-1);
    if (**line == '\n')
        return (0);
    return(1);
}
