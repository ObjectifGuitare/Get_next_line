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
	// printf("%s\n", s2);
	// printf("LA FIN DE JOIN EST |%p|\n", &s2);
    free(s2);
	return (s3);
}


// char *bricolage(char *warehouse, char *buffer)
// {
// 	int line_len;

// 				warehouse = ft_strjoin(warehouse, buffer);
// 				printf("LE BUFF APRES JOIN |%s|\n", buffer);
// 				line_len = buffer_scan_bsn(warehouse);
// 				if (line_len)
// 				{
// 					// printf("LE BUFF AVANT NEXT LINE |%s|\n", buffer);
// 					buffer = next_line(warehouse, line_len);
// 					// printf("LE BUFF APRES NEXT LINE |%s|\n", buffer);
// 					// printf("WAREHOUSE AVANT CLEAN |%s|\n", warehouse);
// 					warehouse = clean_me_daddy(warehouse);
// 					// printf("LE BUFF APRES CLEAN |%s|\n", buffer);
// 					// printf("WAREHOUSE APRES CLEAN |%s|\n", warehouse);
// 					if (!buffer || !warehouse)
// 					{
// 						printf("DANGER ZONE\n");
// 						if(buffer)
// 							free(buffer);
// 						if(warehouse)
// 							free(warehouse);
// 						return (NULL);
// 					}
// 					return (buffer);
// 				}
// 				return (warehouse);
// }
