#include "get_next_line.h"
#include <stdio.h>

char *get_next_line(int fd)
{
    char *buffer;
    int i;

    // if (line)
    //     line = clean_next_line(line);
    i = -2;
    buffer = NULL;
    while(clone_buf_in_line(buffer, i))
    {
        buffer = malloc(BUFFER_SIZE + 1);
        if (!buffer)
            return (NULL);
        if(!read(fd, buffer, BUFFER_SIZE))
        {
            free(buffer);
            return (NULL);
        }
        buffer[BUFFER_SIZE] = '\0';
        i = buffer_scan_bsn(buffer);
        // printf(" VALEUR DE i DANS BUFFER SCAN = | %i |\n", i);
    }
    i = -3;
    buffer = clone_buf_in_line(buffer, i);
    buffer = split_me_daddy(buffer);
    if (!buffer)
        return (NULL);
    return (buffer);
}

int buffer_scan_bsn(char *buffer)
{
    int i;

    i = 0;
    if (buffer[i] == '\n')
        return (0);
    while (buffer[i] && buffer[i++] != '\n')
    {
        if (buffer[i] == '\n')
            return (i);
    }
    return (-1);
}