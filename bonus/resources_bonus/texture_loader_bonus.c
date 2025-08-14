/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_loader_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwallis <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/14 01:27:11 by mwallis           #+#    #+#             */
/*   Updated: 2025/08/14 01:27:23 by mwallis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d_bonus.h"

mlx_image_t	*load_image_texture(t_resources	*resources, const char *path)
{
	mlx_texture_t	*texture;
	mlx_image_t		*image;

	texture = mlx_load_png(path);
	if (texture == NULL)
	{
		write_and_exit_with_graphics_error(ERROR_LOAD_TEXTURE, resources);
	}
	image = mlx_texture_to_image(resources->mlx, texture);
	mlx_delete_texture(texture);
	if (image == NULL)
	{
		write_and_exit_with_graphics_error(ERROR_LOAD_IMAGE, resources);
	}
	return (image);
}
