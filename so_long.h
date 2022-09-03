/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmery <lmery@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/02 12:22:12 by lmery             #+#    #+#             */
/*   Updated: 2022/08/14 16:56:38 by lmery            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "./Libft/libft.h"
# include "./mlx/mlx.h"
# include <stdlib.h>
# include <stdio.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <sys/types.h>
# include <dirent.h>

# define KEY_W 119
# define KEY_A 97
# define KEY_S 115
# define KEY_D 100
# define KEY_ESC 65307

# define WALL_PATH "sprites/Wall.xpm"
# define EMPTY_PATH "sprites/Empty.xpm"
# define PASSED_PATH "sprites/Passed.xpm"
# define HEROE_PATH "sprites/Heroe.xpm"
# define HEROEB_PATH "sprites/Heroeb.xpm"
# define ENEMY_PATH "sprites/Farmer.xpm"
# define DOOR_PATH "sprites/Door.xpm"
# define DOORB_PATH "sprites/Doorb.xpm"
# define COLLECT_PATH "sprites/Collect.xpm"

# define WP "Well done, go to exit"
# define CL "Collected : "

typedef struct s_img
{	
	void	*bloc;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_img;

typedef struct s_pos
{
	int		x;
	int		y;
}	t_pos;

typedef struct s_sprite
{
	t_img	img;
	t_pos	pos;
	char	*path;
	int		width;
	int		height;
}	t_sprite;

typedef struct s_game
{
	void		*mlx;
	void		*window;
	t_img		image;
	t_sprite	sprite_heroe;
	t_sprite	sprite_heroeb;
	t_sprite	sprite_enemy;
	t_sprite	sprite_door;
	t_sprite	sprite_doorb;
	t_sprite	sprite_collect;
	t_sprite	sprite_wall;
	t_sprite	sprite_empty;
	t_sprite	sprite_passed;
	int			moves;
	int			nb_doors;
	int			to_collect;
	int			collected;
	int			nb_lines;
	int			nb_columns;
	int			finish;
	char		last_item;
	t_pos		heroe;
	t_pos		*door;
	t_pos		*collect;
	char		**map;
}	t_game;

void			ft_error(char *msg, char **map);
int				check_arg(int ac, char **av);
int				check_walls(char **map);
int				check_map(t_game *game);
void			check_mandatory_chars(t_game *game);
int				check_extension(char *file_name);
void			ft_final_free(char **map);
void			free_first(t_game *game);
void			destroy_img(t_game *game);

void			init_values(t_game *game);
void			init_map(t_game *game);
void			write_map_collect(t_game *game, int x, int y, char c);
int				ft_close(t_game *game);
int				key_hook(int keycode, t_game *game);
int				mouse_hook(int keycode, t_game *game);
int				ft_get_positions(t_game *game);
void			draw_bloc(t_game *game, int pos_x, int pos_y, char c);
void			draw_image(t_game *game);

int				get_color_addr(char *color_addr);
char			*ft_get_color(t_img *image, int x, int y);
t_sprite		*ft_choose_sprite(t_game *game, char c);
void			my_mlx_pixel_put(t_img *data, int x, int y, int color);

void			ft_move_heroe(t_game *game, int keycode);
void			ft_print_infos(t_game *game);
void			ft_collect(t_game *game);
void			ft_dialogues(t_game *game);
void			ft_win(t_game *game);

#endif