#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char *warehouse = NULL;
	char *buffer;
	

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
		if (buffer_scan_bsn)
		{
			free(buffer);
			buffer = next_line(warehouse);
			clean_me_daddy(warehouse);
			return (buffer);
		}
	}

	return ();
}

int buffer_scan_bsn(char *buffer)
{
    while (*buffer)
        if (*buffer++ == '\n')
            return (1);
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

char *next_line(char *warehouse)
{
	char *line;

	line = malloc();
	if (!line)
	{
		// free ce qui doit etre free
		return (NULL);
	}
	while ()
}