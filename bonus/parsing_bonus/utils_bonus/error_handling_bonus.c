/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handling_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnamoune <cnamoune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/14 01:15:59 by cnamoune          #+#    #+#             */
/*   Updated: 2025/08/14 01:15:59 by cnamoune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d_bonus.h"

void	clear_remaining_lines_gnl(int fd)
{
	char	*line;

	line = get_next_line(fd, 0);
	while (line != NULL)
	{
		free(line);
		line = get_next_line(fd, 0);
	}
}

void	free_residual_line_and_gnl(int fd, char **line)
{
	if (line && *line)
	{
		free(*line);
		*line = NULL;
	}
	clear_remaining_lines_gnl(fd);
}

void	free_map_copy(char **map_copy)
{
	int	i;

	i = 0;
	while (map_copy[i] != NULL)
		free(map_copy[i++]);
	free(map_copy);
}

void	write_close_and_exit(int fd, const char *str, t_map_data *map_data)
{
	close(fd);
	ft_putstr_const_fd(str, 2);
	free_map_data(map_data);
	exit(1);
}
