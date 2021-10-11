#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <stdlib.h>
# include <unistd.h>
# include <stdbool.h>


char *get_next_line(int fd);
int buffer_scan_bsn(char *buffer);
size_t	ft_strlen(const char *s);
char	*ft_strjoin(char *s1, char *s2, int b);
ssize_t clone_buf_in_line(char *buffer, char *line, int i);
char *split_me_daddy(char *line);
char *clean_next_line(char *line);

#endif