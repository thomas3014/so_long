/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_event.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlefebvr <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 16:58:49 by tlefebvr          #+#    #+#             */
/*   Updated: 2022/02/23 10:14:51 by tlefebvr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./so_long.h"

int	ft_int_len(int x)
{
	int	y;

	y = 0;
	if (x > 0)
	{
		if (x > 9)
			y += ft_int_len(x / 10);
		y++;
	}
	return (y);
}

static void	ft_moov(t_so_long **game, int y, int x)
{
	mlx_put_image_to_window((*game)->mlx, (*game)->mlx_win,
		(*game)->background, ((*game)->player_x) * (*game)->mult,
		((*game)->player_y) * (*game)->mult);
	mlx_put_image_to_window((*game)->mlx, (*game)->mlx_win,
		(*game)->player[(*game)->anim_player], ((*game)->player_x + x)
		* (*game)->mult, ((*game)->player_y + y) * (*game)->mult);
	(*game)->str[(*game)->player_y + y][(*game)->player_x + x] = 'P';
	(*game)->str[(*game)->player_y][(*game)->player_x] = '0';
	(*game)->player_y += y;
	(*game)->player_x += x;
	(*game)->player_move++;
	ft_printf("\033[2K\r\033[0;32m%i\e[0m", (*game)->player_move);
	ft_string_put(&(*game));
}

static void	ft_go(t_so_long **game, int y, int x)
{
	if ((*game)->str[(*game)->player_y + y][(*game)->player_x + x] == '0')
		ft_moov(&(*game), y, x);
	else if ((*game)->str[(*game)->player_y + y][(*game)->player_x + x] == 'C')
	{
		ft_moov(&(*game), y, x);
		(*game)->coin_count--;
	}
	else if ((*game)->str[(*game)->player_y + y][(*game)->player_x + x] == 'E')
	{
		if ((*game)->coin_count == 0)
		{
			printf("WIN!!");
			ft_exit_hook((*game)->mlx);
		}
		else
			ft_printf("il te manque %i clef(s)\n", (*game)->coin_count);
	}
	else if ((*game)->str[(*game)->player_y + y][(*game)->player_x + x] == 'N')
	{
		printf("GAME OVER!");
		ft_exit_hook((*game)->mlx);
	}
}

int	ft_win_event(int keycode, t_so_long **game)
{
	if (keycode == EVENT_W)
	{
		ft_go(&(*game), -1, 0);
	}
	else if (keycode == EVENT_A)
	{
		ft_go(&(*game), 0, -1);
	}
	else if (keycode == EVENT_D)
	{
		ft_go(&(*game), 0, 1);
	}
	else if (keycode == EVENT_S)
	{
		ft_go(&(*game), 1, 0);
	}
	else if (keycode == EVENT_ESC)
	{
		ft_exit_hook((*game)->mlx);
		return (0);
	}
	return (0);
}
