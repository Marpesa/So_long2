/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmery <lmery@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/02 12:19:09 by lmery             #+#    #+#             */
/*   Updated: 2022/08/14 18:05:19 by lmery            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	ft_error(char *msg, char **map)
{
	ft_putstr_fd("Error", 1);
	if (msg)
	{
		ft_putstr_fd(": ", 1);
		ft_putstr_fd(msg, 1);
	}
	ft_putstr_fd("\n", 1);
	if (map)
		ft_final_free(map);
	exit (0);
}

int	check_arg(int ac, char **av)
{
	char	**map;

	map = NULL;
	if (ac < 2)
		ft_error("Missing map file", map);
	if (ac > 2)
		ft_putstr_fd("Only first map wille be used\n", 1);
	if (check_extension(av[1]) == 0)
		ft_error("Wrong file extension", map);
	if (check_extension(av[1]) == -1)
		ft_error("Map is a directory or you don't have reading rights", map);
	return (1);
}

int	check_map_chars(char **map)
{
	int		i;
	int		j;

	j = 0;
	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] != '1' && map[i][j] != '0' && map[i][j] != 'E'
				&& map[i][j] != 'P' && map[i][j] != 'C'
				&& map[i][j] != '\n' && map[i][j] != 'X')
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	check_lenght(t_game *game)
{
	int		i;
	int		j;
	int		len;
	char	**map;

	map = game->map;
	i = 0;
	j = 0;
	len = 0;
	while (map[i][j])
		j++;
	len = j - 1;
	game->nb_columns = len + 1;
	while (map[i])
	{
		j = 0;
		while (map[i][j] != '\n' && map[i][j] != '\0')
			j++;
		if (j != len)
			return (0);
		i++;
	}
	return (1);
}

int	check_map(t_game *game)
{
	char	**map;

	map = game->map;
	if (!map)
		ft_error("Empty map", map);
	if (!check_lenght(game))
		ft_error("Invalid map shape", map);
	if (game->nb_columns > 41)
		ft_error("Map too large, don't put over 40 columns", map);
	if (game->nb_lines > 23)
		ft_error("Map too large, don't put over 22 lines", map);
	if (!check_walls(map))
		ft_error("Invalid walls", map);
	if (!check_map_chars(map))
		ft_error("Invalid char in map file", map);
	check_mandatory_chars(game);
	return (1);
}
