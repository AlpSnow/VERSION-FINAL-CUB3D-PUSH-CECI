/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_input_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnamoune <cnamoune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/14 01:15:12 by cnamoune          #+#    #+#             */
/*   Updated: 2025/08/14 01:15:12 by cnamoune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d_bonus.h"

static int	is_cub_file(char *str)
{
	char	*ext;

	ext = ft_strrchr(str, '.');
	if (ext == NULL || ext == str)
		return (1);
	if (ft_strcmp(ext, ".cub") == 0)
		return (0);
	return (1);
}

void	validate_input(int argc, char *argv[])
{
	if (argc != 2)
	{
		ft_putstr_const_fd(ERROR_ARGC, 2);
		exit(1);
	}
	if (is_cub_file(argv[1]) == 1)
	{
		ft_putstr_const_fd(ERROR_CUB, 2);
		exit(1);
	}
}
