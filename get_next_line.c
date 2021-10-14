#include "get_next_line.h"

char *clone_buf_in_line(char *buffer, int i, int j)
{
    static char *line;

    if (j)
    {
        if(!i)
            free(buffer);
        if(!line)
            return (NULL);
        line = split_me_daddy(line);
        return (line); 
    }
    if (i == -3)
        return (line);
    if(i == -2)
    {
        line = clean_next_line(line);
        return("ye");
    }
    line = ft_strjoin(line, buffer);
    if (i == -1)
        return ("ye");
    return ("\0");
}

char *get_next_line(int fd)
{
    char *buffer;
    int i;

    i = -2;
    buffer = NULL;
    while(clone_buf_in_line(buffer, i, 0) && i < 1)
    {
        buffer = malloc(BUFFER_SIZE + 1);
        if (!buffer)
            return (NULL);
        i = read(fd, buffer, BUFFER_SIZE);
        if(!i)
            return (clone_buf_in_line(buffer, i, 1));
        buffer[i] = '\0';
        i = buffer_scan_bsn(buffer);
    }
    return (clone_buf_in_line(buffer, i, 1));
}

int buffer_scan_bsn(char *buffer)
{
    int i;

    i = 0;
    while (buffer[i])
        if (buffer[i++] == '\n')
            return (1);
    return (-1);
}


// char *clone_buf_in_line(char *buffer, int i)
// {
//     static char *line;

//     if (i == -3)
//         return (line);
//     if(i == -2)
//     {
//         line = clean_next_line(line);
//         return("ye");
//     }
//     line = ft_strjoin(line, buffer);
//     if (i == -1)
//         return ("ye");
//     return ("\0");
// }

// char *clean_eof(char *buffer, int i)
// {
//     char *line;

//     if(!i)
//         free(buffer);
//     line = clone_buf_in_line(buffer, -3);
//     if(!line)
//         return (NULL);
//     line = split_me_daddy(line);
//     return (line);
// }