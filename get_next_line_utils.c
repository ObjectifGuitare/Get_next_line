/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seb <seb@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/10 01:04:02 by spatez            #+#    #+#             */
/*   Updated: 2021/06/26 19:59:15 by seb              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	n;

	if (!s)
		return (0);
	n = 0;
	while (s[n])
		n++;
	return (n);
}
#include <stdio.h>
char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*s3;
	int		i;
	int		j;

	i = -1;
	j = 0;
	printf("entering strjoin\n");
	if (!s2)
		return (NULL);
    if (!s1)
        return ((char *) s2);
	s3 = malloc((ft_strlen(s1) + ft_strlen(s2)) + 1);
	if (!s3)
		return (NULL);
	while (s1[++i] != '\0')
		s3[j++] = s1[i];
	i = -1;
	while (s2[++i] != '\0' && s2[i] != '\n')
		s3[j++] = s2[i];
	s3[j] = '\0';
	printf("la valeur renvoyée par strjoin est : %s", s3);
	free((char *) s2);
	free((char *) s1);
	return (s3);
}
