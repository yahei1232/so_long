/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yal-kham <yal-kham@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 13:51:56 by yal-kham          #+#    #+#             */
/*   Updated: 2025/01/14 13:52:07 by yal-kham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	free_exit_error(t_mlx *mlx, const char *line)
{
	free_map(mlx->info->map);
	free(mlx->info);
	free(mlx);
	perror(line);
	exit(01);
}

int	is_ber(char *file)
{
	char	*check;
	size_t	i;

	if (ft_strlen(file) < 4)
		return (0);
	i = ft_strlen(file) - 4;
	check = ft_substr(file, i, 4);
	if (ft_strncmp(check, ".ber", 4) != 0)
	{
		free(check);
		return (0);
	}
	free(check);
	return (1);
}
