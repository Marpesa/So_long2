/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmery <lmery@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/02 13:56:52 by lmery             #+#    #+#             */
/*   Updated: 2022/08/14 18:11:21 by lmery            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static int	nb_lines(char *map)
{
	int		i;
	int		lines;
	int		fd;
	char	*tmpline;

	fd = open(map, O_RDONLY);
	if (fd == -1)
		return (-1);
	lines = 1;
	i = 0;
	tmpline = get_next_line(fd);
	if (!tmpline)
		return (0);
	while (tmpline)
	{
		lines++;
		free(tmpline);
		tmpline = get_next_line(fd);
	}
	close(fd);
	return (lines);
}

static char	**lines_alloc(char *file)
{
	char	**map;
	int		lines;

	map = NULL;
	lines = nb_lines(file);
	if (lines <= 0)
		ft_error("Invalid file", map);
	map = malloc(sizeof(char *) * (lines + 1));
	if (!map)
		ft_error("Malloc error during map initialisation", map);
	return (map);
}

char	**convert_map(char *file, t_game *game)
{
	char	**map;
	int		fd;
	int		i;
	int		lines;

	lines = nb_lines(file);
	game->nb_lines = lines;
	map = lines_alloc(file);
	if (!map)
		return (0);
	fd = open(file, O_RDONLY);
	i = 0;
	while (lines--)
	{
		map[i] = get_next_line(fd);
		i++;
	}
	map[i] = NULL;
	close(fd);
	return (map);
}

int	main(int ac, char **av)
{
	t_game	game;

	check_arg(ac, av);
	if (nb_lines(av[1]) == -1)
		exit (0);
	if (nb_lines(av[1]) == 0)
	{
		ft_putstr_fd("Error : Empty map\n", 1);
		exit (0);
	}
	game.map = convert_map(av[1], &game);
	check_map(&game);
	init_values(&game);
	init_map(&game);
	ft_final_free(game.map);
	return (1);
}
