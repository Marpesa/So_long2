/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmery <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 11:32:08 by lmery             #+#    #+#             */
/*   Updated: 2021/12/01 15:46:44 by lmery            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>
#include <stdio.h>

char	*ft_strtrim(char const *s, char const *set)
{
	int		len;
	char	*d;

	if (!s || !set)
		return (NULL);
	while (*s && ft_strchr(set, *s))
		s++;
	len = ft_strlen((char *)s);
	while (len && ft_strchr(set, s[len]))
		len--;
	d = ft_substr((char *)s, 0, len + 1);
	return (d);
}
