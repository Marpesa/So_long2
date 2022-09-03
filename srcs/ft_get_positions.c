/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_positions.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmery <lmery@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/08 14:29:37 by lmery             #+#    #+#             */
/*   Updated: 2022/08/13 03:57:07 by lmery            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static void	ft_get_heroe(t_game *game)
{
	char	**map;
	int		i;
	int		j;

	i = 0;
	j = 0;
	map = game->map;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'P')
			{
				game->heroe.x = j;
				game->heroe.y = i;
			}
			j++;
		}
		i++;
	}
}

void	write_map(t_game *game, int x, int y, char c)
{
	char	**map;
	int		i;

	map = game->map;
	i = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if (map[y][x] == c)
			{
				game->door[i].x = x;
				game->door[i].y = y;
				i++;
			}
			x++;
		}
		y++;
	}
}

static void	ft_get_doors(t_game *game, char c)
{
	int		x;
	int		y;

	x = 0;
	y = 0;
	game->door = malloc(sizeof(t_pos) * game->nb_doors);
	if (!game->door)
	{
		free_first(game);
		exit (0);
	}
	write_map(game, x, y, c);
}

static void	ft_get_collect(t_game *game, char c)
{
	int		i;
	int		x;
	int		y;

	i = 0;
	x = 0;
	y = 0;
	game->collect = malloc(sizeof(t_pos) * game->to_collect);
	if (!game->collect)
	{
		(free_first(game));
		exit (0);
	}
	write_map_collect(game, x, y, c);
}

int	ft_get_positions(t_game *game)
{
	ft_get_heroe(game);
	ft_get_doors(game, 'E');
	ft_get_collect(game, 'C');
	return (0);
}
