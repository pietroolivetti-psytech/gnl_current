#include "get_next_line_bonus.c"
#include "get_next_line_utils_bonus.c"
#ifndef BUFFER_SIZE
#define BUFFER_SIZE 10
#endif
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <limits.h>
#include <string.h>

int main()
{
	
		char	*line = "";
		char cont = 'y';
		int fd1 = open("t_10_nl", O_RDONLY);
		int fd2 = open("t_no_nl", O_RDONLY);
		int fd3 = open("t_single_line", O_RDONLY);
		int fn = 42;
		while(cont == 'y')
		{
			printf("Choose file: \n%d - t_10_nl\n%d - t_no_nl\n%d - t_single_line\nYour choice: ", fd1, fd2, fd3);
			scanf(" %d", &fn);
				line = get_next_line(fn);
				if (line)
					printf("%s", line);
				else
					printf("No more lines to print in fd %d", fn);

				free (line);
			printf("\nGet next line [y/n]: ");
			scanf(" %c", &cont);
		}
	close (fd1);
	close (fd2);
	close (fd3);

	return (0);
}
