#include "../get_next_line_bonus.c" 
#include "../get_next_line_utils_bonus.c"

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <limits.h>
#include <string.h>

int print_fd_filename(int fd)
{
	char path[64];
	char filename[1024];
	ssize_t len;

	snprintf(path, sizeof(path), "/proc/self/fd/%d", fd);
	len = readlink(path, filename, sizeof(filename) - 1);
	//if (len == -1)
	//	printf("Invalid FD %d\n", fd);
		//perror("readlink");

	filename[len] = '\0';
	printf("FD %d: %s\n", fd, strrchr(filename, '/')+1);
	return (0);
}

int not_in(int *narray, int fn)
{
	int i = 0;
	while(narray[i])
	{
		if (narray[i] == fn)
			return (0);
		i++;
	}
	return(1);
}

int main()
{
		char	*line = "";
		//char cont = 'y';
		int fd1 = open("t_10_nl", O_RDONLY);
		int fd2 = open("t_no_nl", O_RDONLY);
		int fd3 = open("t_1huge_line", O_RDONLY);
		int fd4 = open("t_empty", O_RDONLY);
		int fd5 = open("t_exact_10_with_nl", O_RDONLY);
		int narray[6] = {fd1, fd2, fd3, fd4, fd5, 0};
		int fn = 42;
		int i = -1;
		printf("\n**OPTIONS**\n");
		while (narray[++i])
			print_fd_filename(narray[i]);
		while(fn)
		{
			printf("\nSelect FD [0 to exit]: ");
			scanf(" %d", &fn);
			if (fn == 0)
				break ;
			printf("You selected FD %d\nGetting line...\n", fn);
			sleep(1);

			if (not_in(narray, fn) && fn != 0)
			{
				printf("FD %d is not a valid file\n", fn);
				printf("\nSelect FD [0 to exit]: \n");
				scanf(" %d", &fn);
				if (fn == 0)
					break ;
			}
			if (fn == 0)
				break ;
			line = get_next_line(fn);
			if (line)
				printf("%s", line);
			else
				printf("No more lines to print in fd %d", fn);
				free (line);
			//printf("\nGet next line [y/n]: ");
			//scanf(" %c", &cont);
		}
	close (fd1);
	close (fd2);
	close (fd3);

	return (0);
}
