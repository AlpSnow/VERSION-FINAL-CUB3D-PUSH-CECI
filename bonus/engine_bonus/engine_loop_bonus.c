/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   engine_loop_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwallis <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/14 01:22:22 by mwallis           #+#    #+#             */
/*   Updated: 2025/08/14 01:22:26 by mwallis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d_bonus.h"

void	engine_loop(void *setting)
{
	t_resources	*resources;

	resources = setting;
	handle_keypress_input(resources);
	handle_mouse_input(resources);
	render_frame(resources);
}
