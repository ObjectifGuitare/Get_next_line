#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	n;

	n = 0;
	while (s && s[n])
		n++;
	return (n);
}

ssize_t strlen_bsn(char *s)
{
    size_t n;

    if (!s)
        return (-1);
    n = 0;
    while (*s)
    {
        while (*s)
        {
            if(*s == '\n')
                n++;
            s++;
        }
        s++;
    }
    return (n);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*s3;
	int		i;
	int		j;

	i = -1;
	j = 0;
	if (!s2)
    {
        printf("coucou\n");
		return (NULL);
    }
	s3 = malloc((ft_strlen(s1) + ft_strlen(s2)) + 1);
	if (!s3)
		return (NULL);
    if (s1)
        while (s1[++i] != '\0')
            s3[j++] = s1[i];
    i = -1;
    while (s2[++i] != '\0')
		s3[j++] = s2[i];
    s3[j] = '\0'; // only one null byte at the end
    if (s1)
        free(s1);
    free(s2);
	return (s3);
}

char *split_me_daddy(char *line)
{
    char *new;
    int i;
    int j;

    i = 0;
    j = 0;

    new = malloc(ft_strlen(line) + strlen_bsn(line) + 2);
    if(!new)
        return (NULL);
    while (line[j] )
    {
        new[i++] = line[j];
        if (line[j++] == '\n') // peut etre devrais ne split qu une seule ligne a la fois
            new[i++] = '\0';
    }
    new[i++] = '\0';
    new[i] = '\0';
    free(line);
    // printf("|||%c|||\n", new[6]);
    return (new);
}

char *clean_next_line(char *line, int read)
{
    char *new;
    int j;
    int i;

    if (!line)
        return (NULL);
    i = 0;
    j = 0;

    while(line[j])
        j++;
    j++;
    if(line[j] == '\0' && line[j - 2] == '\n')
        return (NULL);
    if(line[j] == '\0' && read == 0)
        return (NULL);
    printf("%i |||%c|||\n", j, line[j]);
    new = malloc(ft_strlen(line) + 2);
    if(!new)
        return (NULL);
    while(line[j])
    {
        while(line[j])
            new[i++] = line[j++];
        j++;
    }
    new[i++] = '\0';
    new[i] = '\0';
    // printf(new);
    //  printf("%i |||%c|||\n", j, line[j]);
    free(line);
    // printf("|||%s|||\n", new);
    return (new);
}
