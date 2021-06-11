/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spatez <spatez@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/10 00:53:22 by spatez            #+#    #+#             */
/*   Updated: 2021/06/11 05:15:36 by spatez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int get_next_line(int fd, char **line)
{
	static int i;
	
	if (fd < 0 || fd == 2)
		return (-1);
	i = 0;
	if (read(fd, line, BUFFER_SIZE) == 0);
		return (0);
	return (1);
	
}


