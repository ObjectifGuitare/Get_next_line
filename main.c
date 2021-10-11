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

    i = 1;
    fd = open("ouvrebatar", O_RDONLY);
    while(i)
    {
        line =  get_next_line(fd);
        printf("%s", line);
        if (!line)
            i = 0;
    }
    close(fd);
}



