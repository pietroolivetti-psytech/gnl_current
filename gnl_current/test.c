#include "get_next_line.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

int main()
{
	int	fd;
	char	*line = "";
	fd = open("t_10_nl", O_RDONLY);
	//fd = open("t_no_nl", O_RDONLY);

	while(line)
	{
		line = get_next_line(fd);
		if (line)
			printf("%s", line);
		free (line);
	}
	close (fd);
}



/*size_t	ft_strlen(char *s)
{
	size_t	len;

	len = 0;
	while(s[len])
		len++;
	return (len);
}

char	*ft_strdup(char *s)
{
	char	*new;
	size_t	len;
	ssize_t	i;

	if (!s)
		return (NULL);
	len = ft_strlen(s);
	new = malloc((len + 1) * sizeof(char));
	if (!new)
		return (NULL);
	i = -1;
	while(s[++i])
		new[i] = s[i];
	new[i] = '\0';
	return (new);
}
char	*ft_strjoin(char *s1, char *s2)
{
	char	*s3;
	ssize_t	i;
	ssize_t	j;
	size_t	len;

	len = ft_strlen(s1) + ft_strlen(s2) + 1;
	s3 = malloc(len * sizeof(char));
	if (!s3)
		return (NULL);
	i = -1;
	while (s1[++i])
		s3[i] = s1[i];
	j = -1;
	while (s2[++j])
		s3[i + j] = s2[j];
	s3[i + j] = '\0';
	return(s3);
}

char	*ft_substr(char *s, unsigned int start, size_t len_sub)
{
	char	*new;
	size_t	s_len;
	size_t	i;

	if (!s)
		return (NULL);
	s_len = ft_strlen(s);
	if (start > s_len)
		return (ft_strdup(""));
	if ((s_len - start) < len_sub)
		len_sub = s_len - start;
	new = malloc((s_len + 1) * sizeof(char));
	if (!new)
		return (NULL);
	i = 0;
	while(i < len_sub)
	{
		if (!s[start])
			return (new);
		new[i++] = s[start++]; 
	}
	new[i] = '\0';
	return (new);
}

int main()
{
	char *ex = "copy this\0";
	char *x = ft_strdup(ex);
	char *j = " shit!";
	printf("copied: %s\n", x);
	printf("joining: %s\n", ft_strjoin(ex, j));
	printf("substring from t: %s\n", ft_substr(ex, 5, 15));

}	*/