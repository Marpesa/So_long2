/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmery <lmery@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/08 11:59:23 by lmery             #+#    #+#             */
/*   Updated: 2022/08/14 17:47:06 by lmery            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	key_hook(int keycode, t_game *game)
{
	if (keycode == KEY_ESC)
		ft_close(game);
	if (keycode == KEY_W || keycode == KEY_S
		|| keycode == KEY_A || keycode == KEY_D)
		ft_move_heroe(game, keycode);
	return (0);
}

void	destroy_img(t_game *game)
{
	if (game->sprite_heroe.img.bloc)
		mlx_destroy_image(game->mlx, game->sprite_heroe.img.bloc);
	if (game->sprite_heroeb.img.bloc)
		mlx_destroy_image(game->mlx, game->sprite_heroeb.img.bloc);
	if (game->sprite_door.img.bloc)
		mlx_destroy_image(game->mlx, game->sprite_door.img.bloc);
	if (game->sprite_doorb.img.bloc)
		mlx_destroy_image(game->mlx, game->sprite_doorb.img.bloc);
	if (game->sprite_empty.img.bloc)
		mlx_destroy_image(game->mlx, game->sprite_empty.img.bloc);
	if (game->sprite_wall.img.bloc)
		mlx_destroy_image(game->mlx, game->sprite_wall.img.bloc);
	if (game->sprite_collect.img.bloc)
		mlx_destroy_image(game->mlx, game->sprite_collect.img.bloc);
	if (game->sprite_enemy.img.bloc)
		mlx_destroy_image(game->mlx, game->sprite_enemy.img.bloc);
	if (game->sprite_passed.img.bloc)
		mlx_destroy_image(game->mlx, game->sprite_passed.img.bloc);
}

void	free_first(t_game *game)
{
	if (game->map)
		ft_final_free(game->map);
	if (game->collect)
		free(game->collect);
	if (game->door)
		free(game->door);
}

int	ft_close(t_game *game)
{
	destroy_img(game);
	if (game->image.bloc)
		mlx_destroy_image(game->mlx, game->image.bloc);
	if (game->window)
		mlx_destroy_window(game->mlx, game->window);
	free_first(game);
	if (game->mlx)
	{
		mlx_destroy_display(game->mlx);
		mlx_loop_end(game->mlx);
		free(game->mlx);
	}
	exit (1);
	return (0);
}
