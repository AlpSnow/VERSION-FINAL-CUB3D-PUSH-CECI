/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_handler_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwallis <mwallis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/14 02:22:32 by mwallis           #+#    #+#             */
/*   Updated: 2025/08/14 02:45:00 by mwallis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d_bonus.h"

static void	recenter_mouse_if_needed(t_resources *resources,
					int mouse_x, int mouse_y, int32_t *prev_x)
{
	int	screen_width;
	int	screen_height;

	screen_width = resources->dimensions_config.screen_width;
	screen_height = resources->dimensions_config.screen_height;
	if (mouse_x < MOUSE_MARGIN || mouse_x > (screen_width - MOUSE_MARGIN)
		|| mouse_y < MOUSE_MARGIN || mouse_y > (screen_height - MOUSE_MARGIN))
	{
		mlx_set_mouse_pos(resources->mlx, screen_width / 2, screen_height / 2);
		*prev_x = screen_width / 2;
	}
}

void	handle_mouse_input(t_resources *resources)
{
	static int32_t	prev_x = -1;
	int32_t			mouse_x;
	int32_t			mouse_y;
	int32_t			delta_x;

	mlx_get_mouse_pos(resources->mlx, &mouse_x, &mouse_y);
	if (prev_x == -1)
		prev_x = mouse_x;
	delta_x = mouse_x - prev_x;
	prev_x = mouse_x;
	if (delta_x > MOUSE_MAX_DELTA)
		delta_x = MOUSE_MAX_DELTA;
	if (delta_x < -MOUSE_MAX_DELTA)
		delta_x = -MOUSE_MAX_DELTA;
	if (delta_x != 0)
		move_player_rotation(&resources->player_data,
			delta_x * MOUSE_SENSIBILITY * resources->mlx->delta_time * 60.0);
	recenter_mouse_if_needed(resources, mouse_x, mouse_y, &prev_x);
}
