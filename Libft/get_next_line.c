/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmery <lmery@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 14:20:08 by lmery             #+#    #+#             */
/*   Updated: 2022/07/18 19:35:58 by lmery            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

static char	*gft_strchr(char *str, int c)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
	{
		if (str[i] == (char)c)
			return ((char *)&str[i]);
		i++;
	}
	return (0);
}

static char	*gft_strjoin(char *s1, char *s2)
{
	int		i;
	int		j;
	char	*d;

	if (!s1)
	{
		s1 = malloc (sizeof(char));
		s1[0] = '\0';
	}
	if (!s1 || !s2)
		return (0);
	d = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!d)
		return (0);
	i = -1;
	while (s1[++i])
		d[i] = s1[i];
	j = 0;
	while (s2[j])
		d[i++] = s2[j++];
	d[i] = '\0';
	free(s1);
	return (d);
}

char	*ft_next_line(char *str)
{
	int		i;
	int		j;
	int		l;
	char	*s;

	l = ft_strlen(str);
	i = 0;
	while (str[i] && str[i] != '\n')
		i++;
	if (!str[i])
	{
		free(str);
		return (0);
	}
	s = malloc(sizeof (char) * (l - i + 1));
	if (!s)
		return (0);
	j = 0;
	i++;
	while (str[i])
		s[j++] = str[i++];
	s[j] = '\0';
	free(str);
	return (s);
}

char	*ft_read_file(int fd, char *str)
{
	int		n;
	char	*temp;

	temp = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!temp)
		return (0);
	n = 1;
	while (!gft_strchr(str, 10) && n != 0)
	{
		n = read(fd, temp, BUFFER_SIZE);
		if (n == -1)
		{
			free(temp);
			return (0);
		}
		temp[n] = '\0';
		str = gft_strjoin(str, temp);
	}
	free(temp);
	return (str);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*static_str;

	if (BUFFER_SIZE <= 0 || fd < 0)
		return (0);
	static_str = ft_read_file(fd, static_str);
	if (!static_str)
		return (0);
	line = ft_read_line(static_str);
	static_str = ft_next_line(static_str);
	return (line);
}
