/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwallis <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/14 01:13:56 by mwallis           #+#    #+#             */
/*   Updated: 2025/08/14 01:13:59 by mwallis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

uint32_t	convert_rgba_to_argb(const mlx_image_t *image, int x, int y)
{
	int				pixel_index;
	const uint8_t	*rgba;
	uint32_t		final_color;

	pixel_index = (y * image->width + x);
	rgba = &image->pixels[pixel_index * 4];
	final_color = ((uint32_t)rgba[0] << 24)
		| ((uint32_t)rgba[1] << 16)
		| ((uint32_t)rgba[2] << 8)
		| (uint32_t)rgba[3];
	return (final_color);
}

uint32_t	shade_color(uint32_t color)
{
	uint32_t	alpha;
	uint32_t	rgb;
	uint32_t	final_rgb;

	alpha = color & 0x000000FF;
	rgb = (color >> 8) & 0x00FFFFFF;
	rgb = (rgb >> 1) & 0x007F7F7F;
	final_rgb = ((rgb << 8) | alpha);
	return (final_rgb);
}

void	safe_put_pixel(mlx_image_t *image, int screen_x, int screen_y, \
						uint32_t color_argb)
{
	if (screen_x >= 0 && screen_y >= 0
		&& screen_x < (int)image->width && screen_y < (int)image->height)
	{
		mlx_put_pixel(image, screen_x, screen_y, color_argb);
	}
}
