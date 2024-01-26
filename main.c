/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlefebvr <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 09:54:22 by tlefebvr          #+#    #+#             */
/*   Updated: 2022/02/23 11:29:26 by tlefebvr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "./so_long.h"

int	main(int argc, char **argv)
{
	t_so_long	*game;

	game = malloc(sizeof (t_so_long));
	game->mult = 50;
	if (!game)
		return (0);
	if (argc != 2)
		return (printf ("Error\n"));
	if (ft_check_file(argv[1]) && ft_init_map(&game, argv[1]))
	{
		game->player_move = 0;
		game->anim_count = 0;
		game->enemies_count = 0;
		mlx_key_hook(game->mlx_win, ft_win_event, &game);
		mlx_hook(game->mlx_win, 17, 1L << 17, ft_exit_hook, &game);
		mlx_loop_hook(game->mlx, ft_sprite, &game);
		mlx_loop(&game->mlx);
		ft_close(&game, 0);
		printf("\033[2K\r\033[0;34mYou made : %i.\e[0m", game->player_move);
	}
	else
		printf ("Error\n");
	free (game);
	return (1);
}
