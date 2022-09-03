/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmery <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 09:45:29 by lmery             #+#    #+#             */
/*   Updated: 2021/12/03 10:50:16 by lmery            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *a, const char *b, int n)
{
	int				i;
	unsigned char	*s1;
	unsigned char	*s2;

	s1 = (unsigned char *)a;
	s2 = (unsigned char *)b;
	i = 0;
	if (n == 0)
		return (0);
	if (n < 0)
		return (-1);
	while (s1[i] == s2[i] && i < n - 1)
		i++;
	if (s1[i] != s2[i] || s1[i] == 0 || s2[i] == 0)
		return (s1[i] - s2[i]);
	return (0);
}
