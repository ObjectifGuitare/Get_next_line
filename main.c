#include "get_next_line.h"
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int main()
{
    int fd;
    char *line;
    int i; 
    int b = 1;

    i = 1;
    fd = open("ouvrebatar", O_RDONLY);
    while(i)
    {
        printf("\n\n%i EME ITERATION DE GNL\n\n", b);
        line =  get_next_line(fd);
        printf("%s", line);
        if (!line)
            i = 0;
    }
    close(fd);
}



