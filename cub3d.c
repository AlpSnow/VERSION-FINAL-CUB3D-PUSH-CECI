/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/06 17:40:55 by mwallis           #+#    #+#             */
/*   Updated: 2025/08/12 06:22:52 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	main(int argc, char *argv[])
{
	t_resources	resources;

	validate_input(argc, argv);
	sanitize_structs(&resources);
	init_simulation_parameters(&resources);
	init_map_data(argv[1], &resources.map_data);
	init_game_data(&resources);
	init_screen(&resources);
	mlx_loop_hook(resources.mlx, &engine_loop, &resources);
	mlx_loop(resources.mlx);
	ft_putstr_const_fd(INFO_WINDOW_CLOSE, 1);
	free_game_resources(&resources);
	free_map_data(&resources.map_data);
	return (0);
}
