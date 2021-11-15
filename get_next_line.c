#include "get_next_line.h"

char	*get_next_line(int fd)
{
	char *buffer;
	int red;
	int line_len;

	buffer = NULL;
	if (fd < 0 || read(fd, buffer, 0) == -1) // ainsi que OPEN MAX	
		return(NULL);
	red = 0;
	line_len = 0;
	while(!line_len)
	{
		buffer = malloc(BUFFER_SIZE + 1);
        if (!buffer)
            return (NULL);
		red = read(fd, buffer, BUFFER_SIZE);
		buffer = send_next_line(-1, buffer, red);
		if (!buffer)
			return (NULL);
		line_len = buffer_scan_bsn(buffer);
		if ((red == 0 && line_len == 0) || line_len)
			return (send_next_line(line_len, buffer, red));
		else
			buffer = NULL;
	}
	return (NULL);
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
	free(warehouse); // probleme de free une fois sur deux avec lui...
	return (new);
}

char *next_line(char *warehouse, int len)
{
	char *line;
	int i;

	i = 0;
	if (len == 0)
		return (warehouse);
	line = malloc(len + 1);
	if (!line)
		return (NULL);
	while (*warehouse != '\n')
		line[i++] = *warehouse++;
	line[i++] = '\n';
	line[i] = '\0';
	return (line);
}
