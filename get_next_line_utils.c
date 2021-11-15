#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	n;

	n = 0;
	if (!s)
		return (0);
	while (s[n])
		n++;
	return (n);
}

int buffer_scan_bsn(char *buffer)
{
	int i;

	i = 0;
    while (buffer[i])
        if (buffer[i++] == '\n')
            return (i);
    return (0);
}

char	*ft_strjoin(char *s1, char *s2)
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
		while (s1[++i] != '\0')
			s3[j++] = s1[i];
	i = -1;
	while (s2[++i] != '\0')
		s3[j++] = s2[i];
	s3[j] = '\0';
	if (s1)
        free(s1);
    free(s2);
	return (s3);
}

char *error(char *buffer, char *warehouse)
{
	free(buffer);
	if (warehouse)
		free(warehouse);
	return (NULL);
}

char *send_next_line(int line_len, char *buffer, int red)
{
	static char *warehouse = NULL;

	if (line_len == -1)
	{
		if (red < 0)
			return (error(buffer, warehouse));
		buffer[red] = '\0';
		warehouse = ft_strjoin(warehouse, buffer);
		return(warehouse);
	}
	else
	{
		if (*warehouse == '\0')
			return (NULL);
		buffer = next_line(warehouse, line_len);
		warehouse = clean_me_daddy(warehouse);
		return (buffer);
	}
}

