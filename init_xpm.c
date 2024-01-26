/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_xpm.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlefebvr <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 14:18:59 by tlefebvr          #+#    #+#             */
/*   Updated: 2022/02/22 14:57:36 by tlefebvr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./so_long.h"

static void	ft_player(t_so_long **game)
{
	(*game)->player[0] = ft_open_xpm(&(*game),
			"./imgXpm/skeleton_2_50X50_hat_sand.xpm");
	(*game)->player[1] = ft_open_xpm(&(*game),
			"./imgXpm/skeleton_1_50X50_hat_sand.xpm");
	(*game)->player[2] = ft_open_xpm(&(*game),
			"./imgXpm/skeleton_3_50X50_hat_sand.xpm");
}

static void	ft_enemies(t_so_long **game)
{
	(*game)->enemies[0] = ft_open_xpm(&(*game),
			"./imgXpm/skeleton_2_50X50_sand.xpm");
	(*game)->enemies[1] = ft_open_xpm(&(*game),
			"./imgXpm/skeleton_1_50X50_sand.xpm");
	(*game)->enemies[2] = ft_open_xpm(&(*game),
			"./imgXpm/skeleton_3_50X50_sand.xpm");
}

void	ft_init_xpm(t_so_long **game)
{
	printf("dans le init_xpm\n");
	(*game)->border = ft_open_xpm(&(*game), "./imgXpm/bg.xpm");
	(*game)->exit = ft_open_xpm(&(*game),
			"./imgXpm/chest_close_50X50_sand.xpm");
	(*game)->background = ft_open_xpm(&(*game), "./imgXpm/sand_50X50.xpm");
	(*game)->coin = ft_open_xpm(&(*game), "./imgXpm/key_sand_50X50.xpm");
	ft_player (&(*game));
	ft_enemies (&(*game));
	printf("init_xpm ok\n");
}
