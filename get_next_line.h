/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spatez <spatez@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 19:52:34 by spatez            #+#    #+#             */
/*   Updated: 2021/11/16 20:07:57 by spatez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <stdlib.h>
# include <unistd.h>
# include <stdbool.h>

char	*get_next_line(int fd);
int		buffer_scan_bsn(char *buffer);
size_t	ft_strlen(const char *s);
char	*ft_strjoin(char *s1, char *s2);
char	*clean_me_daddy(char *warehouse);
char	*next_line(char *warehouse, int i);
char	*ft_strdup(const char *s);
char	*error(char *buffer, char *warehouse);
char	*send_next_line(int line_len, char *buffer, int red);

#endif