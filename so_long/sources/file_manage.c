/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_manage.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yal-kham <yal-kham@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 13:51:19 by yal-kham          #+#    #+#             */
/*   Updated: 2025/01/14 13:51:29 by yal-kham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	image_init(t_mlx *mlx)
{
	int	a;

	mlx->imgs = malloc(sizeof(t_img));
	if (!mlx->imgs)
		exit_error("Malloc Faliure\n");
	mlx->imgs->wall = mlx_xpm_file_to_image(mlx->mlx,
			"textures/wall.xpm", &a, &a);
	mlx->imgs->floor = mlx_xpm_file_to_image(mlx->mlx,
			"textures/floor.xpm", &a, &a);
	mlx->imgs->player_down = mlx_xpm_file_to_image(mlx->mlx,
			"textures/player_down.xpm", &a, &a);
	mlx->imgs->player_up = mlx_xpm_file_to_image(mlx->mlx,
			"textures/player_up.xpm", &a, &a);
	mlx->imgs->player_left = mlx_xpm_file_to_image(mlx->mlx,
			"textures/player_left.xpm", &a, &a);
	mlx->imgs->player_right = mlx_xpm_file_to_image(mlx->mlx,
			"textures/player_right.xpm", &a, &a);
	mlx->imgs->collectible = mlx_xpm_file_to_image(mlx->mlx,
			"textures/collectable.xpm", &a, &a);
	mlx->imgs->exit = mlx_xpm_file_to_image(mlx->mlx,
			"textures/exit.xpm", &a, &a);
}
