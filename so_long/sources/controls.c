/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controls.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yal-kham <yal-kham@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 13:50:49 by yal-kham          #+#    #+#             */
/*   Updated: 2025/01/18 15:34:44 by yal-kham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	key_press(int keycode, t_mlx *mlx)
{
	if (keycode == XK_Escape || keycode == XK_q)
		close_window(mlx);
	if (keycode == XK_w || keycode == XK_Up)
		move_up(mlx);
	if (keycode == XK_s || keycode == XK_Down)
		move_down(mlx);
	if (keycode == XK_a || keycode == XK_Left)
		move_left(mlx);
	if (keycode == XK_d || keycode == XK_Right)
		move_right(mlx);
	return (0);
}

void	hook_controls(t_mlx *mlx)
{
	mlx_hook(mlx->win, 2, 1L << 0, key_press, mlx);
	mlx_hook(mlx->win, 17, 0, close_window, mlx);
}
