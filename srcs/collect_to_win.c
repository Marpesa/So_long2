/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collect_to_win.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmery <lmery@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/11 16:24:18 by lmery             #+#    #+#             */
/*   Updated: 2022/08/14 17:12:42 by lmery            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	ft_win(t_game *game)
{
	if (game->last_item == 'E' && game->finish == 1)
	{
		write (1, "YOU WON !\n", 10);
		sleep(1 / 2);
		ft_close(game);
	}
	if (game->last_item == 'X' && game->finish == 0)
	{
		write (1, "YOU LOST !\n", 11);
		ft_close(game);
	}
	return ;
}

void	ft_collect(t_game *game)
{
	if (game->last_item == 'C')
		game->collected++;
	if (game->collected == game->to_collect)
		game->finish = 1;
	return ;
}
