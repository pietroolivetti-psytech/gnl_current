#include "../get_next_line.c" 
#include "../get_next_line_utils.c"

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <limits.h>
#include <string.h>

int main()
{

		int	fd;
		char cont = 'y';
		char	*line = "";
		fd = open("t_10_nl", O_RDONLY);
		//fd = open("t_no_nl", O_RDONLY);

		while(cont == 'y')
		{
			line = get_next_line(fd);
			if (line)
				printf("%s", line);
			else
			{
				printf("No more lines to print");
				break;
			}
			free (line);
			printf("\nGet next line [y/n]: ");
			scanf(" %c", &cont);
		}
		close (fd);
}
	
