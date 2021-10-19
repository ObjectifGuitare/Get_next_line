#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char *warehouse = NULL;
	char *buffer;
	int line_len;
	

	buffer = NULL;
	if (fd < 0 || read(fd, buffer, 0) == -1) // ainsi que OPEN MAX	
		return(NULL);
	while()
	{
		if (!read(fd, buffer, BUFFER_SIZE));
		{
			// free le buffer et la warehouse si necessaire
			return ();
		}
		ft_strjoin(warehouse, buffer);
		line_len = buffer_scan_bsn(warehouse);
		if (line_len)
		{
			free(buffer);
			buffer = next_line(warehouse, line_len);
			clean_me_daddy(warehouse);
			return (buffer);
		}
	}

	return ();
}

int buffer_scan_bsn(char *buffer)
{
	int i;

	i = 0;
    while (buffer[i])
        if (buffer[i++] == '\n')
            return (i);
    return (-1);
}

void	clean_me_daddy(char *warehouse)
{
	char *cleaned_sweetie;

	cleaned_sweetie = malloc();
	if (!cleaned_sweetie)
	{
		//free ce qui doit etre free
		return (NULL);
	}
	while (*warehouse != '\n')
		warehouse++;
	return (ft_strjoin(cleaned_sweetie, warehouse));
}

char *next_line(char *warehouse, int i)
{
	char *line;
	int i;

	i = 0;
	line = malloc(i + 1);
	if (!line)
	{
		// free ce qui doit etre free
		return (NULL);
	}
	while (*warehouse != '\n')
		line[i++] = *warehouse++;
	line[i++] = '\n';
	line[i] = '\0';
	return (line);
}