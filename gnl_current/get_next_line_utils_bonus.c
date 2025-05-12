/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pileonar <pileonar@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 21:31:07 by pileonar          #+#    #+#             */
/*   Updated: 2025/05/12 21:31:09 by pileonar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

 #include "get_next_line.h"

size_t	ft_strlen(char *s)
{
	size_t	len;

	len = 0;
	while(s[len])
		len++;
	return (len);
}
char	*ft_strdup(char *src)
{
	char	*new;
	int		i;

	i = 0;
	new = (char *)malloc(sizeof(char) * ft_strlen(src) + 1);
	if (!new)
		return (NULL);
	while (*src)
		new[i++] = *src++;
	new[i] = '\0';
	return (new);
}

/*char	*ft_strdup(char *s)
{
	char	*new;
	size_t	len;
	ssize_t	i;

	//if (!s)
	//	return (NULL);
	len = ft_strlen(s);
	new = malloc((len + 1) * sizeof(char));
	if (!new)
		return (NULL);
	i = -1;
	while(s[++i])
		new[i] = s[i];
	new[i] = '\0';
	return (new);
}*/

/*char	*ft_strjoin(char *s1, char *s2)
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
	while (s1[++i] && i < len)
		s3[i] = s1[i];
	j = -1;
	while (s2[++j] && (i + j < len))
		s3[i + j] = s2[j];
	s3[i + j] = '\0';
	return(s3);
}*/
char	*ft_strjoin(char *s1, char *s2)
{
	char	*s3;
	size_t	i;
	size_t	j;
	size_t	len;

	i = 0;
	j = 0;
	len = (ft_strlen(s1) + ft_strlen(s2)) + 1;
	s3 = malloc(sizeof(char) * len);
	if (!s3)
		return (NULL);
	while (i < len && s1[i])
	{
		s3[i] = s1[i];
		i++;
	}
	while (i + j < len && s2[j])
	{
		s3[j + i] = s2[j];
		j++;
	}
	s3[i + j] = '\0';
	return (s3);
}

/*char	*ft_substr(char *s, unsigned int start, size_t len_sub)
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
}*/
char	*ft_substr(char *s, unsigned int start, size_t len)
{
	size_t	i;
	size_t	len_str;
	char	*s2;

	if (s == NULL)
		return (NULL);
	i = 0;
	len_str = ft_strlen(s);
	if (start >= len_str)
		return (ft_strdup(""));
	if ((len_str - start) < len)
		len = len_str - start;
	s2 = malloc(len + 1 * sizeof(char));
	if (!s2)
		return (NULL);
	while (i < len)
	{
		if (!s[start])
			return (s2);
		s2[i++] = s[start++];
	}
	s2[i] =  '\0';
	return (s2);
}

ssize_t		ft_chrpos(char *s, char c)
{
	ssize_t	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == c)
			return (i);
		i++;
	}
	return (-1);
}