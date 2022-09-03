/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmery <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 17:07:02 by lmery             #+#    #+#             */
/*   Updated: 2021/12/01 08:24:55 by lmery            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, int n)
{
	int					i;
	unsigned const char	*a;
	unsigned char		*b;

	if (dst == NULL && src == NULL)
		return (0);
	a = (unsigned char *)src;
	b = (unsigned char *)dst;
	i = 0;
	while (i < n)
	{
		((char *)b)[i] = ((char *)a)[i];
		i++;
	}
	return (dst);
}
