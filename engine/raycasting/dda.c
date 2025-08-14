/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dda.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwallis <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/14 01:12:54 by mwallis           #+#    #+#             */
/*   Updated: 2025/08/14 01:12:57 by mwallis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

void	raycast_digital_differential_analyzer(const t_resources *resources, \
													t_raycast_data *ray)
{
	while (1)
	{
		if (ray->dist_to_next_x < ray->dist_to_next_y)
		{
			ray->dist_to_next_x += ray->dist_per_tile_x;
			ray->ray_current_tile_x += ray->advance_direction_x;
			ray->hit_side = 0;
		}
		else
		{
			ray->dist_to_next_y += ray->dist_per_tile_y;
			ray->ray_current_tile_y += ray->advance_direction_y;
			ray->hit_side = 1;
		}
		if (resources->map_data.map[ray->ray_current_tile_y]
			[ray->ray_current_tile_x] == '1')
			break ;
	}
	if (ray->hit_side == 0)
		ray->perp_distance = ray->dist_to_next_x - ray->dist_per_tile_x;
	else
		ray->perp_distance = ray->dist_to_next_y - ray->dist_per_tile_y;
}
