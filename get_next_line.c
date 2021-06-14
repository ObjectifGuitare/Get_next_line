/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spatez <spatez@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/10 00:53:22 by spatez            #+#    #+#             */
/*   Updated: 2021/06/14 07:48:52 by spatez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

ssize_t	ft_line_return_check(char *buffer)
{
	// returns the index for the first occurence of \n
	// -1 if no \n was found and EOF was reached
	// buffer_size + 1 if \n not found
	int i;

	i = -1;
	while (buffer[++i])
		if (buffer[i] == '\n')
			return (i);
	return (-1);
}



ssize_t ft_read(int fd, char *buffer)
{
    static int malloced;
    int i;

    if (malloced)
        free(buffer);
    buffer = malloc(BUFFER_SIZE);
    if (!buffer)
        return (-1);
    malloced = 1;
    read(fd, buffer, BUFFER_SIZE);
    i = ft_line_return_check(buffer);

}

int get_next_line(int fd, char **line)
{
    char *buffer;

    check errors

    ft_read(fd, buffer)
}


// int get_next_line(int fd, char **line)
// {
// 	char *buf;
// 	static int i;
	
// 	if (fd < 0 || fd == 2)
// 		return (-1);
// 	if (BUFFER_SIZE == 0 || read(fd, *line, BUFFER_SIZE) == 0));
// 		return (0);
// 	i = 0;
// 	return (1);
	
// }


