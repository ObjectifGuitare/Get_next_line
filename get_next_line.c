#include "get_next_line.h"

char *format_next_line(char *buffer, int i, int j)
{
    static char *line;

    if (j)
    {
        line = clean_next_line(line, i);
        if(!i)
            free(buffer);
        if(!line || *line == '\0')
            return (NULL);
        printf("LA LIGNE ENVOYEE DANS SPLIT EST: |%s|\n", line);
        line = split_me_daddy(line);
        printf("LA LIGNE RETOURNEE PAR SPLIT EST: |%s|\n", line);
        return (line); 
    }
    if (i == -3)
        return (line);
    // if(i == -2)
    // {

    //     printf("LA LIGNE ENVOYEE DANS CLEAN EST : |%s|\n", line);
    //     line = clean_next_line(line);
    //     printf("LA LIGNE RENVOYEE PAR CLEAN EST : |%s|\n\n", line);
    //     return("ye");
    // }
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
    while(format_next_line(buffer, i, 0) && i < 1)
    {
        buffer = malloc(BUFFER_SIZE + 2);
        if (!buffer)
            return (NULL);
        i = read(fd, buffer, BUFFER_SIZE);
        printf("LA VALEUR DE READ EST : |%i|\n", i);
        if(!i)
            return (format_next_line(buffer, i, 1));
        buffer[i++] = '\0';
        buffer[i] = '\0';
        i = buffer_scan_bsn(buffer);
    }
    return (format_next_line(buffer, i, 1));
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
