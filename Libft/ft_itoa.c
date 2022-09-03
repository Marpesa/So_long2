/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmery <lmery@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 17:43:42 by lmery             #+#    #+#             */
/*   Updated: 2022/08/11 20:48:30 by lmery            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_count(long int i)
{
	int	a;

	a = 0;
	if (i < 0)
		a++;
	if (i == 0)
		a = 1;
	while (i != 0)
	{
		i = i / 10;
		a++;
	}
	return (a);
}

char	*ft_write_num(char *r, long int n, long int i)
{

	if (n == 0)
		r[0] = 48;
	while (n > 0)
	{
		r[i] = (n % 10) + 48;
		n = n / 10;
		i--;
	}
	return (r);
}

char	*ft_itoa(int n)
{
	int			i;
	char		*r;
	long int	num;

	num = (long int)n;
	r = (char *)malloc(sizeof(char) * (ft_count(num) + 1));
	if (!r)
		return (0);
	if (num == 0)
		r[0] = '\0';
	i = ft_count(num) - 1;
	r[ft_count(num)] = '\0';
	if (num < 0)
	{	
		r[0] = '-';
		num = -num;
	}
	r = ft_write_num(r, num, i);
	return (r);
}