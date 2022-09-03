/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmery <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 09:53:36 by lmery             #+#    #+#             */
/*   Updated: 2021/12/03 17:44:39 by lmery            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_substr(char const *s, unsigned int i, size_t len)
{
	size_t	j;
	char	*d;

	j = 0;
	if (!s)
		return (0);
	if ((unsigned int)ft_strlen((char *)s) < i)
		return (ft_strdup(""));
	if (len > ft_strlen(s) - i)
		len = ft_strlen(s) - i;
	if (len <= (size_t)ft_strlen(s))
	{
		d = (char *)malloc(sizeof(char) * (len + 1));
		if (d == 0)
			return (0);
	}
	while (s[i] && j < len)
	{
		d[j] = s[i];
		i++;
		j++;
	}
	d[j] = '\0';
	return (d);
}
