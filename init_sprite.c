/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_sprite.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlefebvr <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 14:14:05 by tlefebvr          #+#    #+#             */
/*   Updated: 2022/02/22 15:25:43 by tlefebvr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./so_long.h"

void	*ft_open_xpm(t_so_long **game, char *str)
{
	return (mlx_xpm_file_to_image(
			(*game)->mlx, str, &(*game)->picture_size,
			&(*game)->picture_size));
}

int	ft_check_in(char str, char *charset)
{
	int	j;
	int	check;

	j = 0;
	check = 0;
	while (charset[j])
	{
		if (str == charset[j])
			check = 1;
		else if (str != charset[j] && check != 1)
			check = 0;
		j++;
	}
	if (check == 0)
		return (0);
	j = 0;
	return (check);
}

int	ft_init_while(t_so_long **game, t_map_check **check)
{
	while (++(*check)->y < (*check)->max_y)
	{
		(*check)->x = -1;
		(*check)->count_x = 0;
		while (++(*check)->x < (*check)->max_x
			&& ft_check_in((*game)->str[(*check)->y][(*check)->x], "10EPCN"))
		{
			if ((*game)->str[(*check)->y][0] != '1' ||
				(*game)->str[(*check)->y][(*check)->max_x - 1] != '1')
				return (0);
			if (((*check)->y == 0 || (*check)->y == (*check)->max_y - 1)
				&& (*game)->str[(*check)->y][(*check)->x] == '1')
				(*check)->count_x++;
		}
		if (((*check)->y == 0 || (*check)->y == (*check)->max_y - 1)
			&& ((*check)->x != (*check)->count_x
				|| (*check)->max_x != (*check)->x))
			return (0);
		if ((*check)->x != (*check)->max_x)
			return (0);
	}
	return (1);
}

int	ft_string_put(t_so_long **game)
{
	mlx_put_image_to_window((*game)->mlx, (*game)->mlx_win,
		(*game)->border, 0 * (*game)->mult, 0 * (*game)->mult);
	mlx_put_image_to_window((*game)->mlx, (*game)->mlx_win,
		(*game)->border, 1 * (*game)->mult, 0 * (*game)->mult);
	mlx_put_image_to_window((*game)->mlx, (*game)->mlx_win,
		(*game)->border, 2 * (*game)->mult, 0 * (*game)->mult);
	mlx_string_put((*game)->mlx,
		(*game)->mlx_win, 0, 25, 0XFFFFFF, "Mouvement:");
	mlx_string_put((*game)->mlx,
		(*game)->mlx_win, 75, 25, 0X0000FF00, ft_itoa((*game)->player_move));
	return (0);
}
