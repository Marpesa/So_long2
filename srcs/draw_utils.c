/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmery <lmery@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/12 22:16:10 by lmery             #+#    #+#             */
/*   Updated: 2022/08/13 04:34:16 by lmery            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	my_mlx_pixel_put(t_img *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

t_sprite	*ft_choose_sprite(t_game *game, char c)
{
	if (c == 'P')
		return (&game->sprite_heroe);
	if (c == 'B')
		return (&game->sprite_heroeb);
	if (c == 'C')
		return (&game->sprite_collect);
	if (c == 'X')
		return (&game->sprite_enemy);
	if (c == '0')
		return (&game->sprite_empty);
	if (c == '1')
		return (&game->sprite_wall);
	if (c == 'E' && game->finish == 0)
		return (&game->sprite_door);
	if (c == 'E' && game->finish == 1)
		return (&game->sprite_doorb);
	if (c == '2')
		return (&game->sprite_passed);
	return (0);
}

char	*ft_get_color(t_img *image, int x, int y)
{
	char	*color;

	color = image->addr + (y * image->line_length
			+ x * (image->bits_per_pixel / 8));
	return (color);
}

int	get_color_addr(char *color_addr)
{
	int	*color;

	color = (int *)color_addr;
	return (*color);
}

void	draw_bloc(t_game *game, int pos_x, int pos_y, char c)
{
	int		x;
	int		y;
	char	*color;

	x = pos_x * 64;
	y = pos_y * 64;
	while (y < ((64 * pos_y) + 64))
	{
		color = NULL;
		x = pos_x * 64;
		while (x < ((64 * pos_x) + 64))
		{
			color = ft_get_color(&ft_choose_sprite(game, c)->img,
					x - (64 * pos_x), y - (64 * pos_y));
			my_mlx_pixel_put(&game->image, x, y, get_color_addr(color));
			x++;
		}
		y++;
	}
}
