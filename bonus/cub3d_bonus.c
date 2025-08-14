/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwallis <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/14 01:19:38 by mwallis           #+#    #+#             */
/*   Updated: 2025/08/14 01:19:44 by mwallis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

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
