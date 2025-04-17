/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yal-kham <yal-kham@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 11:20:31 by yal-kham          #+#    #+#             */
/*   Updated: 2025/01/14 13:44:32 by yal-kham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static char	*remove_nl(t_mlx *mlx, char *line)
{
	char	*str_rtn;
	char	*newline_pos;

	newline_pos = line;
	while (*newline_pos)
	{
		if (!valid_character(*newline_pos) && *newline_pos != '\n')
		{
			free(line);
			free_exit_error(mlx, "Error\nInvalid character in map");
		}
		newline_pos++;
	}
	str_rtn = ft_strdup(line);
	free(line);
	newline_pos = ft_strchr(str_rtn, '\n');
	if (newline_pos)
		*newline_pos = '\0';
	return (str_rtn);
}

static void	extract_map(t_mlx *mlx, int n_lines)
{
	int		i;
	size_t	len;

	i = 0;
	n_lines -= 1;
	if (!all_one(mlx->info->map[0]) || !all_one(mlx->info->map[n_lines]))
		free_exit_error(mlx, "Error\nFirst Line and Last Line not all 1");
	while (start_end_one(mlx->info->map[n_lines]) && n_lines >= 1)
		n_lines--;
	if (n_lines != 0)
	{
		free_exit(mlx);
		exit_error("Error\n map not surrounded by 1");
	}
	while (mlx->info->map[i] && mlx->info->map[i + 1])
	{
		len = ft_strlen(mlx->info->map[i]);
		if (len != ft_strlen(mlx->info->map[i + 1]))
		{
			free_exit(mlx);
			exit_error("Error\nMap not rectangular");
		}
		i++;
	}
	how_many(mlx);
}

static void	store_map(char *file, t_mlx *mlx)
{
	int		fd;
	int		i;
	char	*line;
	int		n_lines;

	n_lines = 0;
	mlx->info->map = ft_calloc((100), sizeof(char *));
	fd = open(file, O_RDONLY);
	if (fd < 0)
		free_exit_error(mlx, "Error\nFile Doesn't Exist");
	line = get_next_line(fd);
	i = 0;
	if (!line)
		free_exit_error(mlx, "Error\nEmpty File");
	while (line)
	{
		mlx->info->map[i] = remove_nl(mlx, line);
		line = get_next_line(fd);
		i++;
		n_lines++;
	}
	free(line);
	mlx->info->map[i] = NULL;
	close(fd);
	extract_map(mlx, n_lines);
}

void	parser(t_mlx *mlx, char *file)
{
	if (!is_ber(file))
	{
		free(mlx);
		exit_error("Error\nFile not .ber");
	}
	mlx->info = malloc(sizeof(t_info));
	if (!mlx->info)
		exit_error("Malloc Faliure\n");
	store_map(file, mlx);
}
