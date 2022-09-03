/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_file_type.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmery <lmery@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/02 17:23:58 by lmery             #+#    #+#             */
/*   Updated: 2022/08/14 17:22:42 by lmery            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	check_directory(char *file_name)
{
	int	d;
	int	i;

	d = open(file_name, O_RDONLY);
	i = open(file_name, __O_DIRECTORY);
	if (d != -1)
		close(d);
	if (i != -1)
		close(i);
	if (d == -1 || i != -1)
		return (0);
	return (1);
}

int	check_extension(char *file_name)
{
	int	i;

	if (!check_directory(file_name))
		return (-1);
	i = 0;
	while (file_name[i])
		i++;
	i--;
	if (i < 4)
		return (0);
	if (file_name[i] != 'r')
		return (0);
	if (file_name[i - 1] != 'e')
		return (0);
	if (file_name[i - 2] != 'b')
		return (0);
	if (file_name[i - 3] != '.')
		return (0);
	return (1);
}
