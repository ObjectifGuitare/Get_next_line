#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <stdlib.h>
# include <unistd.h>
# include <stdbool.h>


#include <stdio.h>



char *get_next_line(int fd);
int buffer_scan_bsn(char *buffer);
size_t	ft_strlen(const char *s);
char	*ft_strjoin(char *s1, char *s2);
char	*clean_me_daddy(char *warehouse);
char *next_line(char *warehouse, int i);

#endif