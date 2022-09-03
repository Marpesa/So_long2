/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_walls.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmery <lmery@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/02 13:30:01 by lmery             #+#    #+#             */
/*   Updated: 2022/08/12 22:31:44 by lmery            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	check_up(char **map)
{
	int	i;
	int	j;

	i = 0;
	j = 0 ;
	while (map[i][j] != '\n')
	{
		if (map[i][j] != '1')
			return (0);
		j++;
	}
	return (1);
}

int	check_left(char **map)
{
	int	i;
	int	j;

	j = 0;
	i = 0;
	while (map[i])
	{
		if (map[i][j] != '1')
			return (0);
		i++;
	}
	return (1);
}

int	check_right(char **map)
{
	int	i;
	int	j;

	j = 0;
	i = 0;
	while (map [i][j])
		j++;
	j--;
	while (map[i])
	{
		if (map[i][j - 1] != '1')
			return (0);
		i++;
	}
	return (1);
}

int	check_down(char **map)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (map[i])
		i++;
	i--;
	while (map[i][j] && map[i][j] != '\n')
	{
		if (map[i][j] != '1')
			return (0);
		j++;
	}
	return (1);
}

int	check_walls(char **map)
{
	if (!check_up(map) || !check_left(map)
		|| !check_down(map) || !check_right(map))
		return (0);
	return (1);
}
