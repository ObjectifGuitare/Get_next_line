#include "libft.h"

int main(int ac, char **av)
{
    char *lines
    int fd;
    int gnl;

    lines = NULL;
    fd = open(av[1], O_RDONLY);
    if (fd > 0)
    {
        printf("fichier existe pas frr\n");
        return 0;
    }
    while ((gnl = get_next_line(fd, &lines)) > 0) 
    {
        printf(lines);
    }
    close(a);
}