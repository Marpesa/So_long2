/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_heroe.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmery <lmery@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/11 14:15:30 by lmery             #+#    #+#             */
/*   Updated: 2022/08/14 17:12:28 by lmery            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	ft_move_up(t_game *game, int x, int y)
{
	game->last_item = game->map[y - 1][x];
	if (game->map[y - 1][x] == '1'
		|| (game->map[y - 1][x] == 'E' && game->finish == 0))
		return ;
	if (game->map[y][x] == 'P')
		game->map[y - 1][x] = 'P';
	if (game->map[y][x] == 'B')
		game->map[y - 1][x] = 'B';
	game->map[y][x] = '2';
	game->heroe.y = y - 1;
	game->moves++;
}

void	ft_move_down(t_game *game, int x, int y)
{
	game->last_item = game->map[y + 1][x];
	if (game->map[y + 1][x] == '1'
		|| (game->map[y + 1][x] == 'E' && game->finish == 0))
		return ;
	if (game->map[y][x] == 'P')
		game->map[y + 1][x] = 'P';
	if (game->map[y][x] == 'B')
		game->map[y + 1][x] = 'B';
	game->map[y][x] = '2';
	game->heroe.y = y + 1;
	game->moves++;
}

void	ft_move_left(t_game *game, int x, int y)
{
	game->last_item = game->map[y][x - 1];
	if (game->map[y][x - 1] == '1'
		|| (game->map[y][x - 1] == 'E' && game->finish == 0))
		return ;
	game->map[y][x] = '2';
	game->map[y][x - 1] = 'B';
	game->heroe.x = x - 1;
	game->moves++;
}

void	ft_move_right(t_game *game, int x, int y)
{
	game->last_item = game->map[y][x + 1];
	if (game->map[y][x + 1] == '1'
		|| (game->map[y][x + 1] == 'E' && game->finish == 0))
		return ;
	game->map[y][x] = '2';
	game->map[y][x + 1] = 'P';
	game->heroe.x = x + 1;
	game->moves++;
}

void	ft_move_heroe(t_game *game, int keycode)
{
	int	x;
	int	y;

	x = game->heroe.x;
	y = game->heroe.y;
	if (keycode == KEY_W && y > 1)
		ft_move_up(game, x, y);
	if (keycode == KEY_S && y < game->nb_lines - 3)
		ft_move_down(game, x, y);
	if (keycode == KEY_A && x > 1)
		ft_move_left(game, x, y);
	if (keycode == KEY_D && x < game->nb_columns - 3)
		ft_move_right(game, x, y);
	ft_collect(game);
	draw_image(game);
	mlx_put_image_to_window(game->mlx, game->window, game->image.bloc, 0, 0);
	ft_dialogues(game);
	ft_print_infos(game);
	ft_win(game);
}
