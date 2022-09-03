/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmery <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 10:23:06 by lmery             #+#    #+#             */
/*   Updated: 2021/12/03 17:40:47 by lmery            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *s, const char *w, size_t n)
{
	size_t	i;
	size_t	j;
	size_t	len;
	char	*a;

	i = 0;
	a = (char *)s;
	len = ft_strlen(w);
	if (len == 0 || s == w)
		return (a);
	while (a[i] && i < n)
	{
		j = 0;
		while (a[i + j] && w[j] && a[i + j] == w[j] && i + j < n)
			j++;
		if (j == len)
			return ((char *)&a[i]);
		i++;
	}
	return (0);
}
