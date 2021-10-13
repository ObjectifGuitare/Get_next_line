#include "get_next_line.h"
#include <stdio.h>


size_t	ft_strlen(const char *s)
{
	size_t	n;

	n = 0;
	while (s && s[n])
		n++;
	return (n);
}

char	*ft_strjoin(char *s1, char *s2, int b)
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
    if (b > 0)
        i++;
    // {
        
    //     printf("|||%s AINSI QUE %i|||\n", s3, b);
    //     s3[j++] = '\n';
    // }
    s3[j] = '\0';
    // printf("VALEUR DE s1 APRES STRJOIN = |%s|\n", s1);
    // printf("VALEUR DE s2 APRES STRJOIN = |%s|\n", s2);
    printf("VALEUR DE s3 APRES STRJOIN = |%s|\n", s3);
    free(s1);
    free(s2);
	return (s3);
}


char *clone_buf_in_line(char *buffer, int i)
{
    static char *line;

    if (i == -3)
    {
        return (line);
    }
    if(i == -2)
    {
        line = clean_next_line(line);
        return("ye");
    }
    // printf("VALEUR DE LINE AVANT JOIN = |%s|\n", line);
    printf("[[[%i]]]\n", i);
    line = ft_strjoin(line, buffer, i);
    // printf("VALEUR DE LINE = |%s|\n", line);
    if (i == -1)
        return ("ye");
    return ("\0");
}

char *split_me_daddy(char *line)
{
    char *new;
    int i;
    int j;

    i = 0;
    j = 0;
    // printf("slt\n");
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

    if (!line)
        return (NULL);
    i = 0;
    while(*line != '\n')
        line++;
    line += 1;
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