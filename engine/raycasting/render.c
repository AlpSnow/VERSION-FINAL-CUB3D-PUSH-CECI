/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwallis <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/14 01:13:32 by mwallis           #+#    #+#             */
/*   Updated: 2025/08/14 01:13:39 by mwallis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

void	render_frame(void *setting)
{
	t_resources					*resources;
	t_raycast_data				raycast_data;
	t_ray_column_norm_helper	helper;
	int							screen_x;

	resources = (t_resources *)setting;
	if (resources->screen == NULL)
		write_and_exit_with_graphics_error(ERROR_SCREEN_NOT_INITIALIZED, \
										resources);
	screen_x = 0;
	while (screen_x < resources->dimensions_config.screen_width)
	{
		init_raycast(resources, screen_x, &raycast_data);
		raycast_digital_differential_analyzer(resources, &raycast_data);
		helper.texture = determine_texture_and_hit_column(resources, \
										&raycast_data, &helper.wall_hit_x);
		draw_entire_pixel_column(resources, screen_x, &raycast_data, &helper);
		screen_x = screen_x + 1;
	}
}
