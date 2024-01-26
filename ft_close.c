/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_close.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlefebvr <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 11:29:10 by tlefebvr          #+#    #+#             */
/*   Updated: 2022/02/22 15:29:05 by tlefebvr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./so_long.h"

int	ft_exit_hook(t_so_long **game)
{
	(void) *game;
	exit(10);
}

int	ft_close(t_so_long **game, int x)
{
	mlx_destroy_image((*game)->mlx, (*game)->border);
	mlx_destroy_image((*game)->mlx, (*game)->background);
	mlx_destroy_image((*game)->mlx, (*game)->exit);
	while (x < 11)
		mlx_destroy_image((*game)->mlx, (*game)->enemies[x++]);
	x = 0;
	while (x < 6)
		mlx_destroy_image((*game)->mlx, (*game)->player[x++]);
	mlx_destroy_window((*game)->mlx, (*game)->mlx_win);
	x = 0;
	while (x < (*game)->max_y)
		free((*game)->str[x++]);
	free((*game)->str);
	free((*game)->mlx);
	ft_exit_hook((*game)->mlx);
	return (0);
}
