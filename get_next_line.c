#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char *warehouse = NULL;
	char *buffer;
	int line_len;

	buffer = NULL;
	if (fd < 0 || read(fd, buffer, 0) == -1) // ainsi que OPEN MAX	
		return(NULL);
	line_len = 0;
	while(!line_len)
	{
		buffer = malloc(BUFFER_SIZE + 1);
        if (!buffer)
            return (NULL);
		line_len = read(fd, buffer, BUFFER_SIZE);
		if (line_len == 0)
			return (warehouse);
		if (line_len < 0)
		{
			free(buffer);
			if (warehouse)
				free(warehouse);
			return (NULL);
		}
		warehouse = ft_strjoin(warehouse, buffer);
		line_len = buffer_scan_bsn(warehouse);
		// printf("coucou\n");
		// free(buffer);
		if (line_len)
		{
			buffer = next_line(warehouse, line_len);
			warehouse = clean_me_daddy(warehouse); //probleme dans cette fonction car elle efface le buffer
				printf("maiis %s\n", buffer);
			if (!buffer || !warehouse)
			{
				printf("hiiiiiiiiii\n");
				if(buffer)
					free(buffer);
				if(warehouse)
					free(warehouse);
				return (NULL);
			}
			printf("le buffer renvoye est %s\n", buffer);
			return (buffer);
		}
	}
	return (warehouse);
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

char	*clean_me_daddy(char *warehouse)
{
	// cleaned_sweetie = malloc((ft_strlen(warehouse) - i) + 1);
	// if (!cleaned_sweetie)
	// 	return (NULL);
	// while (*warehouse != '\n')
	// 	warehouse++;
	// warehouse++;
	// return (ft_strjoin(NULL, warehouse));
	char	*new;
	int		i;
	int		j;

	i = 0;
	j = 0;

	while (warehouse[j] != '\n')
		j++;
	j++;
	new = malloc(ft_strlen(warehouse + j + 1) + 1);
	if (!new)
		return (NULL);
	while (*warehouse)
		new[i++] = warehouse[j++];
	new[i] = '\0';
	free(warehouse);
	printf("new est %s\n", new);
	return (new);
}

char *next_line(char *warehouse, int len)
{
	char *line;
	int i;

	i = 0;
	line = malloc(len + 1);
	if (!line)
		return (NULL);
	while (*warehouse != '\n')
		line[i++] = *warehouse++;
	line[i++] = '\n';
	line[i] = '\0';
	printf("LA LINE EST: |%s|\n", line);
	return (line);
}
