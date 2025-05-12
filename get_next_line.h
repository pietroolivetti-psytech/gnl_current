#ifndef GET_NEXT_LINE_H
#define GET_NEXT_LINE_H

#include <stdlib.h>
#include <unistd.h>

#ifndef BUFFER_SIZE
#define BUFFER_SIZE 42
#endif

char	*get_next_line(int fd);
char	*feed_static_buffer(int fd, char *static_buffer);
char	*clean_pointers(char *p1, char *p2);
char	*buildup_static(char *static_buffer, char *temp_buffer);
size_t	ft_strlen(char *s);
char	*ft_strdup(char *s);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_substr(char *s, unsigned int start, size_t len_sub);
ssize_t		ft_chrpos(char *s, char c);
#endif
