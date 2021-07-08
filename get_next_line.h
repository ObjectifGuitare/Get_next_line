/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seb <seb@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/10 00:53:18 by spatez            #+#    #+#             */
/*   Updated: 2021/06/26 19:13:09 by seb              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <stdlib.h>
# include <unistd.h>
# include <stdbool.h>

size_t	ft_strlen(const char *s);
char	*ft_strjoin(char const *s1, char const *s2);
size_t	ft_line_return_check(char *buffer);
char *ft_read(int fd, char *buffer, int i);
int	get_next_line(int fd, char **line);

#endif