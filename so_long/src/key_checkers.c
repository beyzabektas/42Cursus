/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_checkers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bebektas <bebektas@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 14:48:55 by bebektas          #+#    #+#             */
/*   Updated: 2024/01/07 15:48:22 by bebektas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "../minilibx/mlx.h"

int	ft_key_hook(int key_code, t_game *game)
{
	if (key_code == ESC)
		success_exit_game(game, "Game Over!\n");
	else if (key_code == A || key_code == S)
		move_and_put_image(key_code, game, -1);
	else if (key_code == W || key_code == D)
		move_and_put_image(key_code, game, 1);
	return (0);
}

int	ft_mouse_hook(t_game *game)
{
	success_exit_game(game, "Game Over!\n");
	return (0);
}

void	ft_key_comb(t_game *game)
{
	mlx_hook(game->mlx.window, ON_KEYDOWN, 0, ft_key_hook, game);
	mlx_hook(game->mlx.window, ON_DESTROY, 0, ft_mouse_hook, game);
}
