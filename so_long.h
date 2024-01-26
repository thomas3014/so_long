/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlefebvr <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 10:35:38 by tlefebvr          #+#    #+#             */
/*   Updated: 2022/02/23 10:13:01 by tlefebvr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef SO_LONG_H
# define SO_LONG_H

# include "./mlx/mlx.h"
# include "./libft/libft.h"
# include "./ft_printf/ft_printf.h"
# include <stdio.h>
# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>

# define EVENT_W 13
# define EVENT_A 0
# define EVENT_S 1
# define EVENT_D 2
# define EVENT_ESC 53

typedef struct so_long
{
	char	**str;
	int		mult;
	int		max_x;
	int		max_y;
	int		picture_size;
	int		coin_count;
	int		anim_count;
	int		anim_player;
	int		enemies_count;
	int		anim_enemies;
	int		player_y;
	int		player_x;
	int		player_move;
	void	*coin;
	void	*enemies[3];
	void	*wall;
	void	*background;
	void	*player[3];
	void	*mlx;
	void	*mlx_win;
	void	*exit;
	void	*border;	
}	t_so_long;

typedef struct map_check
{
	int		max_x;
	int		max_y;
	int		count_x;
	int		x;
	int		y;
}				t_map_check;

int		ft_check_file(char *path);
int		ft_init_map(t_so_long **game, char *path);
int		ft_init_while(t_so_long **game, t_map_check **check);
int		ft_close(t_so_long **game, int x);
int		ft_strcmpn(char *s1, char *s2);
int		ft_sprite(t_so_long **game);
int		ft_exit_hook(t_so_long **game);
int		ft_int_len(int x);
int		ft_win_event(int keycode, t_so_long **game);
char	*ft_get_file(int fd, int size, int len);
char	**ft_split_ln(char *str, char *charset, int *ln);
char	*ft_strncpy(char *dest, char*src, unsigned int n);
int		ft_string_put(t_so_long **game);
void	ft_init_xpm(t_so_long **game);
void	ft_reload(t_so_long **game);
void	*ft_open_xpm(t_so_long **game, char *str);

#endif
