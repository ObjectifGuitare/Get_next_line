/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spatez <spatez@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/10 00:53:22 by spatez            #+#    #+#             */
/*   Updated: 2021/06/14 12:05:38 by spatez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"



#include <stdio.h>



size_t	ft_strlen(const char *s)
{
	size_t	n;

	n = 0;
	while (s[n])
		n++;
	return (n);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*s3;
	int		i;
	int		j;

	i = -1;
	j = 0;
	if (!s1 || !s2)
		return (NULL);
	s3 = malloc((ft_strlen(s1) + ft_strlen(s2)) + 1);
	if (!s3)
		return (NULL);
	while (s1[++i] != '\0')
	{
		s3[j] = s1[i];
		j++;
	}
	i = -1;
	while (s2[++i] != '\0')
	{
		s3[j] = s2[i];
		j++;
	}
	s3[j] = '\0';
	return (s3);
}

char	*ft_strdup(const char *s)
{
	char	*new;
	int		i;

	i = 0;
	new = malloc(sizeof(*new) * (ft_strlen(s) + 1));
	if (!new)
		return (0);
	while (s[i])
	{
		new[i] = s[i];
		i++;
	}
	new[i] = '\0';
	return (new);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;

	if (!dst || !src)
		return (0);
	if (size == 0)
		return (ft_strlen(src));
	i = -1;
	while (src[++i] && i < size - 1)
		dst[i] = src[i];
	dst[i] = '\0';
	return (ft_strlen(src));
}

ssize_t	ft_line_return_check(char *buffer)
{
	// returns the index for the first occurence of \n
	// -1 if \n not found
	int i;

	i = -1;
	buffer[BUFFER_SIZE] = '\0';
	while (buffer[++i])
    {
		if (buffer[i] == '\n')
		{
            if (i < BUFFER_SIZE - 1)
                buffer[i] = '\0';
            return (i);
        }
    }
	// printf("%s\n", buffer);
	return (-1);
}



char *ft_read(int fd, char *buffer)
{
    static int malloced;
    int i;
    int eof;
    char *dst;

    if (malloced)
        free(buffer);
    buffer = malloc((BUFFER_SIZE) + 1);
    if (!buffer)
        return (NULL);
    malloced = 1;
    if (read(fd, buffer, BUFFER_SIZE) == 0)
        eof = 1;
    i = ft_line_return_check(buffer);
    if (i == -1)
        return (ft_read(fd, buffer));
    
    dst = ft_strdup(buffer);
    return (dst);
}

int get_next_line(int fd, char **line)
{
    char *buffer;
	char *test;
    // check errors
    buffer = NULL;
    printf("%s",ft_strdup(ft_read(fd, buffer)));
    test = ft_strdup(ft_read(fd, buffer));
	printf("%s\n", test);
    *line = malloc(ft_strlen(test) + 1);
    if (!*line)
        return (-1);
    ft_strlcpy(*line, test, 10000);
    return(1);
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

