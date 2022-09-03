/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmery <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 13:19:11 by lmery             #+#    #+#             */
/*   Updated: 2021/12/06 18:27:24 by lmery            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strnlen(char *str, size_t s)
{
	size_t	b;

	b = 0;
	while (str[b] && b < s)
		b++;
	return (b);
}

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (!dest || !src)
		return (0);
	j = ft_strnlen(dest, size);
	if (!size || size == 0)
		return (ft_strlen(src));
	if (j == size)
		return (size + ft_strlen(src));
	while (src[i] && (j + i) < (size - 1))
	{
		dest[j + i] = src[i];
		i++;
	}
	dest[j + i] = '\0';
	return (j + ft_strlen(src));
}
