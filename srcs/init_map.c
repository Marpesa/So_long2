/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmery <lmery@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/07 16:38:07 by lmery             #+#    #+#             */
/*   Updated: 2022/08/14 17:44:38 by lmery            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	sprite_init_one(t_game *game, t_sprite *sprite)
{
	sprite->img.bloc = mlx_xpm_file_to_image(game->mlx, sprite->path,
			&sprite->width, &sprite->height);
	if (!sprite->img.bloc)
	{
		destroy_img(game);
		free_first(game);
		mlx_destroy_display(game->mlx);
		free(game->mlx);
		ft_error("Missing sprite file", NULL);
	}
	sprite->img.addr = mlx_get_data_addr(sprite->img.bloc,
			&sprite->img.bits_per_pixel, &sprite->img.line_length,
			&sprite->img.endian);
}

void	sprite_init_all(t_game *game)
{
	game->sprite_collect.path = COLLECT_PATH;
	game->sprite_wall.path = WALL_PATH;
	game->sprite_empty.path = EMPTY_PATH;
	game->sprite_door.path = DOOR_PATH;
	game->sprite_doorb.path = DOORB_PATH;
	game->sprite_heroe.path = HEROE_PATH;
	game->sprite_heroeb.path = HEROEB_PATH;
	game->sprite_enemy.path = ENEMY_PATH;
	game->sprite_passed.path = PASSED_PATH;
	sprite_init_one(game, &game->sprite_collect);
	sprite_init_one(game, &game->sprite_wall);
	sprite_init_one(game, &game->sprite_empty);
	sprite_init_one(game, &game->sprite_door);
	sprite_init_one(game, &game->sprite_doorb);
	sprite_init_one(game, &game->sprite_heroe);
	sprite_init_one(game, &game->sprite_heroeb);
	sprite_init_one(game, &game->sprite_enemy);
	sprite_init_one(game, &game->sprite_passed);
}

void	draw_image(t_game *game)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (y < game->nb_lines - 1)
	{
		x = 0;
		while (x < game->nb_columns - 1)
		{
			draw_bloc(game, x, y, game->map[y][x]);
			x++;
		}
		y++;
	}
}

void	init_map(t_game *game)
{
	ft_get_positions(game);
	game->mlx = mlx_init();
	if (!game->mlx)
	{
		free_first(game);
		ft_error("Compromised environment", NULL);
	}
	sprite_init_all(game);
	game->window = mlx_new_window(game->mlx, (game->nb_columns - 1) * 64,
			(game->nb_lines - 1) * 64, "So long !");
	game->image.bloc = mlx_new_image(game->mlx, (game->nb_columns - 1) * 64,
			(game->nb_lines - 1) * 64);
	game->image.addr = mlx_get_data_addr(game->image.bloc,
			&game->image.bits_per_pixel, &game->image.line_length,
			&game->image.endian);
	draw_image(game);
	mlx_put_image_to_window(game->mlx, game->window, game->image.bloc, 0, 0);
	mlx_key_hook(game->window, key_hook, game);
	mlx_hook(game->window, 17, 0, ft_close, game);
	mlx_loop(game->mlx);
}
