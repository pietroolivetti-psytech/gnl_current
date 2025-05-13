/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pileonar <pileonar@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 21:30:46 by pileonar          #+#    #+#             */
/*   Updated: 2025/05/12 21:30:50 by pileonar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*clean_pointers(char *p1, char *p2)
{
	if (p1)
	{
		free(p1);
		p1 = NULL;
	}
	if (p2)
	{
		free(p2);
		p2 = NULL;
	}
	return(NULL);
}
char	*buildup_static(char *static_buffer, char *temp_buffer)
{
	char	*build_backup;

	if (!static_buffer)
	{
		static_buffer = ft_strdup(temp_buffer);
		return (static_buffer);
	}
	build_backup = static_buffer;
	static_buffer = ft_strjoin(build_backup, temp_buffer);
	if (!static_buffer)
		return(clean_pointers(build_backup, NULL));
	free(build_backup);
	build_backup = NULL;
	return (static_buffer);
}

char	*feed_static_buffer(int fd, char *static_buffer)
{
	char	*temp_buffer;
	ssize_t	bytes;

	bytes = 1;
	temp_buffer = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!temp_buffer)
		return (clean_pointers(temp_buffer, static_buffer));
	while (bytes)
	{
		bytes = read(fd, temp_buffer, BUFFER_SIZE);
		if (bytes < 0)
			return (clean_pointers(static_buffer, temp_buffer));
		if(!bytes)
			break;
		temp_buffer[bytes] = '\0';
		static_buffer = buildup_static(static_buffer, temp_buffer);
		if (!static_buffer)
			break ;
		if (ft_chrpos(static_buffer, '\n') > -1)
			break;
	}
	free(temp_buffer);
	temp_buffer = NULL;
	return (static_buffer);
}

char	*get_next_line(int fd)
{
	static char	*static_buffer;
	ssize_t		nl_pos;
	char		*next_line;
	char		*current_line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		//return(clean_pointers(static_buffer, NULL));
		return (NULL);
	static_buffer = feed_static_buffer(fd, static_buffer);
	if (!static_buffer || !static_buffer[0])
		//return (free(static_buffer), static_buffer = NULL, NULL); 
		return (clean_pointers(static_buffer, NULL));
	nl_pos = ft_chrpos(static_buffer, '\n');
	if (nl_pos > -1 && (nl_pos < (ssize_t)ft_strlen(static_buffer) - 1))
	{
		next_line = ft_strdup(&static_buffer[nl_pos + 1]);
		current_line = ft_substr(static_buffer, 0, nl_pos + 1);
		if (!current_line || !next_line)
			return(free(static_buffer), static_buffer = NULL, clean_pointers(next_line, current_line));
		free(static_buffer);
		static_buffer = next_line;
		return (current_line);
	}
	current_line = ft_strdup(static_buffer);
	return (free(static_buffer), static_buffer = NULL, current_line);
}
