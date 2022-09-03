/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandatory_chars.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmery <lmery@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/02 16:55:41 by lmery             #+#    #+#             */
/*   Updated: 2022/08/12 22:29:00 by lmery            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	check_c(char **map)
{
	int	i;
	int	j;
	int	ret;

	ret = 0;
	i = 0;
	j = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'C')
				ret++;
			j++;
		}
		i++;
	}
	return (ret);
}

int	check_e(char **map)
{
	int	i;
	int	j;
	int	ret;

	ret = 0;
	i = 0;
	j = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'E')
				ret++;
			j++;
		}
		i++;
	}
	return (ret);
}

int	check_p(char **map)
{
	int	i;
	int	j;
	int	ret;

	ret = 0;
	i = 0;
	j = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'P')
				ret++;
			j++;
		}
		i++;
	}
	return (ret);
}

void	check_mandatory_chars(t_game *game)
{
	char	**map;

	map = game->map;
	if (check_p(map) < 1)
		ft_error("Missing heroe on map", map);
	if (check_p(map) > 1)
		ft_error("Too many heroes on map", map);
	if (check_e(map) < 1)
		ft_error("Missing exit on map", map);
	if (check_c(map) < 1)
		ft_error("No collectible on map", map);
	game->to_collect = check_c(map);
	game->nb_doors = check_e(map);
	return ;
}
