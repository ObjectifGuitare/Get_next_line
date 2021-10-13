#include "get_next_line.h"
#include <stdio.h>

char *get_next_line(int fd)
{
    char *buffer;
    int i;

    i = -2;
    buffer = NULL;
    while(clone_buf_in_line(buffer, i) && i < 1)
    {
        buffer = malloc(BUFFER_SIZE + 1);
        if (!buffer)
            return (NULL);
        if(!read(fd, buffer, BUFFER_SIZE))
        {
            free(buffer);
            // printf("bonjour\n");
            buffer = clean_eof(buffer);
            return (buffer);
        }
        buffer[BUFFER_SIZE] = '\0';
        // printf("VALEUR DE BUFFER DANS LA WHILE PRINCIPALE : |%s|\n", buffer);
        i = buffer_scan_bsn(buffer);
        // printf(" VALEUR DE i DANS BUFFER SCAN = | %i |\n", i);
    }
    buffer = clone_buf_in_line(buffer, -3);
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
        return (1);
    while (buffer[i] && buffer[i++] != '\n')
    {
        if (buffer[i] == '\n')
            return (i);
    }
    return (-1);
}