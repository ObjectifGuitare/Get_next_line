#include "get_next_line.h"

char *format_next_line(char *buffer, int i, int j)
{
    static char *line;
    static int end;

    if (end)
        return (NULL);
    if (j)
    {
        if(!i && clean_next_line(line, i) == NULL)
        {
            // printf("%s\n", line);
            end = 1;
            return (line);
        }
        if(!i)
            free(buffer);
        if(!line || *line == '\0')
            return (NULL);
        // printf("LA LIGNE ENVOYEE DANS SPLIT EST: |%s|\n", line);
        line = split_me_daddy(line);
        // printf("LA LIGNE RETOURNEE PAR SPLIT EST: |%s|\n", line);
        return (line); 
    }
    if (i == -3)
        return (line);
    if(i == -2)
    {

        // printf("LA LIGNE ENVOYEE DANS CLEAN EST : |%s|\n", line);
        line = clean_next_line(line, 1); // probleme se trouve dans le fait que parfois la valeur doit etre zero ici
        // printf("LA LIGNE RENVOYEE PAR CLEAN EST : |%s|\n\n", line);
        return("ye");
    }
    // printf("la ligne avant strjoin : |%s|\n", line);
        line = ft_strjoin(line, buffer);
    // printf("la ligne apres strjoin : |%s|\n", line);
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
        buffer = malloc(BUFFER_SIZE + 1);
        if (!buffer)
            return (NULL);
        i = read(fd, buffer, BUFFER_SIZE);
        // printf("LA VALEUR DE READ EST : |%i|\n", i);
        if(!i)
            return (format_next_line(buffer, i, 1));
        buffer[i] = '\0';
        i = buffer_scan_bsn(buffer);
    }
    return (format_next_line(buffer, i, 1));
}

int buffer_scan_bsn(char *buffer)
{
    while (*buffer)
        if (*buffer++ == '\n')
            return (1);
    return (-1);
}
