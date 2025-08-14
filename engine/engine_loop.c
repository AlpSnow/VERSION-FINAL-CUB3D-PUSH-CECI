/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   engine_loop.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwallis <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/14 01:11:55 by mwallis           #+#    #+#             */
/*   Updated: 2025/08/14 01:12:25 by mwallis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	engine_loop(void *setting)
{
	t_resources	*resources;

	resources = setting;
	handle_keypress_input(resources);
	render_frame(resources);
}
