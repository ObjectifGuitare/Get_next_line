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
		buffer[line_len] = '\0';
		if (line_len == 0)
		{
			buffer = next_line(warehouse, line_len);
			warehouse = clean_me_daddy(warehouse);
			if (*buffer == '\0')
				return (NULL);
			return (buffer);
			// return (NULL); //probleme ici quand la warehouse a deja tout en elle
		}
		if (line_len < 0)
		{
			free(buffer);
			if (warehouse)
				free(warehouse);
			return (NULL);
		}
		// return (bricolage(warehouse, buffer));
		warehouse = ft_strjoin(warehouse, buffer);
		printf("LE BUFF APRES JOIN |%s|\n", buffer);
		line_len = buffer_scan_bsn(warehouse);
		if (line_len)
		{
			// printf("LE BUFF AVANT NEXT LINE |%s|\n", buffer);
			buffer = next_line(warehouse, line_len);
			// printf("LE BUFF APRES NEXT LINE |%s|\n", buffer);
			// printf("WAREHOUSE AVANT CLEAN |%s|\n", warehouse);
			warehouse = clean_me_daddy(warehouse);
			// printf("LE BUFF APRES CLEAN |%s|\n", buffer);
			// printf("WAREHOUSE APRES CLEAN |%s|\n", warehouse);
			if (!buffer || !warehouse)
			{
				printf("DANGER ZONE\n");
				if(buffer)
					free(buffer);
				if(warehouse)
					free(warehouse);
				return (NULL);
			}
			return (buffer);
		}
	}
	return (warehouse);
}

char	*clean_me_daddy(char *warehouse)
{
	char	*new;
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (warehouse[j] && warehouse[j] != '\n')
		j++;
	new = malloc(ft_strlen(warehouse + j + 1) + 1);
	if (!new)
		return (NULL);
	while (warehouse[++j] != '\0')
		new[i++] = warehouse[j];
	new[i] = '\0';
	free(warehouse);
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
	return (line);
}
