/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reload.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlefebvr <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 17:13:08 by tlefebvr          #+#    #+#             */
/*   Updated: 2022/02/22 15:37:50 by tlefebvr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./so_long.h"

void	ft_reload(t_so_long **game)
{
	int	x;
	int	y;

	y = 0;
	while (y < (*game)->max_y)
	{
		x = 0;
		while (x < (*game)->max_x)
		{
			if ((*game)->str[y][x] == '1')
				mlx_put_image_to_window((*game)->mlx, (*game)->mlx_win,
					(*game)->border, x * (*game)->mult, y * (*game)->mult);
			else if ((*game)->str[y][x] == '0')
				mlx_put_image_to_window((*game)->mlx, (*game)->mlx_win,
					(*game)->background, x * (*game)->mult, y * (*game)->mult);
			else if ((*game)->str[y][x] == 'E')
				mlx_put_image_to_window((*game)->mlx, (*game)->mlx_win,
					(*game)->exit, x * (*game)->mult, y * (*game)->mult);
			x++;
		}
		y++;
	}
}
