#include "get_next_line.h"



size_t	ft_strlen(const char *s)
{
	size_t	n;

	n = 0;
	while (s && s[n])
		n++;
	return (n);
}

char	*ft_strjoin(char const *s1, char const *s2, int b)
{
	char	*s3;
	int		i;
	int		j;

	i = -1;
	j = 0;
	if (!s2)
		return (NULL);
	s3 = malloc((ft_strlen(s1) + ft_strlen(s2)) + 1);
	if (!s3)
		return (NULL);
    if (s1)
    {
        while (s1[++i] != '\0')
            s3[j++] = s1[i];
        i = -1;
    }
    while (s2[++i] != '\0')
		s3[j++] = s2[i];
    if (b)
        s3[j++] = '\n';
	s3[j] = '\0';
    free(s1);
    free(s2);
	return (s3);
}


ssize_t clone_buf_in_line(char *buffer, char *line, int i)
{
    if(i == -2)
        return(1);
    if (i == -1)
    {
        line = ft_strjoin(line, buffer, i);
        return (1);
    }
    line = ft_strjoin(line, buffer, i);
    return (0);
}

char *split_me_daddy(char *line)
{
    char *new;
    int i;
    int j;

    i = 0;
    j = 0;
    new = malloc(ft_strlen(line) + 3);
    if(!new)
        return (NULL);
    while (line[j])
    {
        new[i++] = line[j];
        if (line[j++] == '\n')
            new[i++] = '\0';
    }
    new[i++] = '\0';
    new[i] = '\0';
    free(line);
    return (new);
}

char *clean_next_line(char *line)
{
    char *new;
    int i;

    i = 0;
    while(*line != '\n')
        line++;
    line += 2;
    if (*line == '\0')
        return (NULL);
    new = malloc(ft_strlen(line) + 2);
    if(!new)
        return (NULL);
    while(*line)
        new[i++] = *line++;
    new[i] = '\0';
    return (new);
}