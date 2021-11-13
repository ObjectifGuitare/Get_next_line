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
		printf("LE BUFFER AU DEBUT DE LA BOUCLE|%s|\n", buffer);
		buffer = malloc(BUFFER_SIZE + 1);
        if (!buffer)
            return (NULL);
		line_len = read(fd, buffer, BUFFER_SIZE);
		buffer[BUFFER_SIZE] = '\0';
		if (line_len == 0)
			return (NULL);
		if (line_len <= 0)
		{
			free(buffer);
			if (warehouse)
				free(warehouse);
			return (NULL);
		}
		printf("LE BUFF AVANT JOIN |%s|\n", buffer);
		warehouse = ft_strjoin(warehouse, buffer);
		printf("LE BUFF APRES JOIN |%s|\n", buffer);
		line_len = buffer_scan_bsn(warehouse);
		// printf("coucou\n");
		// free(buffer);
		if (line_len)
		{
			// printf("LE BUFF AVANT NEXT LINE |%s|\n", buffer);
			buffer = next_line(warehouse, line_len);
			// printf("LE BUFF APRES NEXT LINE |%s|\n", buffer);
			// printf("WAREHOUSE AVANT CLEAN |%s|\n", warehouse);
			warehouse = clean_me_daddy(warehouse); //probleme a partir de cette fonction car elle efface le buffer
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
			// printf("le buffer renvoye est |%s|\n", buffer);
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
	while (warehouse[j] != '\n')
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
