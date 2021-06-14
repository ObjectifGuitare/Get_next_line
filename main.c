#include "get_next_line.h"

#include <unistd.h>
#include <stdio.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
// int main(int ac, char **av)
// {
//     char *lines
//     int fd;
//     int gnl;

//     lines = NULL;
//     fd = open(av[1], O_RDONLY);
//     if (fd > 0)
//     {
//         printf("fichier existe pas frr\n");
//         return 0;
//     }
//     while ((gnl = get_next_line(fd, &lines)) > 0) 
//     {
//         printf(lines);
//     }
//     close(a);
// }

int main()
{
    int fd = open("bonjour", O_RDONLY);
    char *line;

    printf("%d\n", get_next_line(fd, &line));
    printf("%s\n", line);
    close(fd);
}