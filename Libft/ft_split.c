/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmery <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 15:11:12 by lmery             #+#    #+#             */
/*   Updated: 2021/12/06 17:37:09 by lmery            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

int	ft_count(const char *s, char c)
{
	int	i;
	int	n;

	i = 0;
	n = 0;
	while (*s)
	{
		if (*s != c && n == 0)
		{
			n = 1;
			i++;
		}
		else if (*s == c)
			n = 0;
		s++;
	}
	return (i);
}

char	*ft_word(const char *s, int start, int end)
{
	char	*w;
	int		i;

	i = 0;
	w = malloc(sizeof(char) * (end - start + 1));
	while (start < end)
		w[i++] = s[start++];
	w[i] = '\0';
	return (w);
}

char	**ft_split(char const *s, char c)
{
	int		i;
	int		j;
	int		n;
	char	**tab;

	tab = (char **)malloc(sizeof(char *) * (ft_count(s, c) + 1));
	if (!s || !tab)
		return (NULL);
	i = 0;
	j = 0;
	n = -1;
	while (i <= ft_strlen(s))
	{
		if (s[i] != c && n < 0)
			n = i;
		else if ((s[i] == c || i == ft_strlen(s)) && n >= 0)
		{
			tab[j++] = ft_word(s, n, i);
			n = -1;
		}
		i++;
	}
	tab[j] = 0;
	return (tab);
}
