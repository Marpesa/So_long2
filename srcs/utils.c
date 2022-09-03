/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmery <lmery@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/11 16:32:52 by lmery             #+#    #+#             */
/*   Updated: 2022/08/14 17:51:34 by lmery            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	init_values(t_game *game)
{
	game->moves = 0;
	game->collected = 0;
	game->finish = 0;
	game->sprite_enemy.img.bloc = NULL;
	game->sprite_passed.img.bloc = NULL;
	game->sprite_collect.img.bloc = NULL;
	game->sprite_door.img.bloc = NULL;
	game->sprite_doorb.img.bloc = NULL;
	game->sprite_heroe.img.bloc = NULL;
	game->sprite_heroeb.img.bloc = NULL;
	game->sprite_wall.img.bloc = NULL;
	game->sprite_empty.img.bloc = NULL;
}

void	ft_dialogues(t_game *game)
{
	if (game->last_item == 'X' && game->finish == 1)
		mlx_string_put(game->mlx, game->window, game->heroe.x * 64 + 20,
			(game->heroe.y * 64 + 5), 16777215, "Hu Hu");
	if (game->last_item == 'C')
		mlx_string_put(game->mlx, game->window, game->heroe.x * 64 + 20,
			(game->heroe.y * 64 + 5), 16777215, "Nom nom nom");
}

void	ft_print_infos(t_game *game)
{
	char	*a;
	char	*b;
	char	*c;

		a = ft_itoa(game->moves);
	b = ft_itoa(game->collected);
	c = ft_itoa(game->to_collect);
	mlx_string_put(game->mlx, game->window, 100, 30, 16777215, "Moves : ");
	mlx_string_put(game->mlx, game->window, 150, 30, 16777215, a);
	ft_putstr_fd("Moves : ", 1);
	ft_putstr_fd(a, 1);
	ft_putstr_fd("\n", 1);
	if (game->collected < game->to_collect)
	{
		mlx_string_put(game->mlx, game->window, 100, 47, 16777215, CL);
		mlx_string_put(game->mlx, game->window, 175, 47, 16777215, b);
		mlx_string_put(game->mlx, game->window, 185, 47, 16777215, " / ");
		mlx_string_put(game->mlx, game->window, 205, 47, 16777215, c);
	}
	else
		mlx_string_put(game->mlx, game->window, 100, 47, 15921152, WP);
	free(a);
	free(b);
	free(c);
}

void	write_map_collect(t_game *game, int x, int y, char c)
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
				game->collect[i].x = x;
				game->collect[i].y = y;
				i++;
			}
			x++;
		}
		y++;
	}
}
