/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clem9nt <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/28 18:33:32 by clem9nt           #+#    #+#             */
/*   Updated: 2022/01/28 18:33:35 by clem9nt          888   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/*
 ** Init the map with the input file.
 */

void	ft_init_map(t_data *data)
{
	ft_open(data);
	data->width = 0;
	ft_width(data);
	data->height = 0;
	ft_height(data);
	data->values = malloc (sizeof(int *) * (size_t)data->height);
	if (!data->values)
	{
		ft_close_fd(data);
		ft_exit(MALLOC_ERR);
	}
	ft_values(data);
}

/*
 ** Init server and create window.
 */

void	ft_init_mlx(t_data *data)
{
	data->mlx_ptr = mlx_init();
	if (!data->mlx_ptr)
	{
		ft_backfree(data->values, data->height - 1);
		ft_exit(MLX_ERR);
	}
	data->win_ptr = mlx_new_window(data->mlx_ptr, WIDTH, HEIGHT, data->file);
	if (!data->win_ptr)
	{
		ft_free(data->win_ptr);
		ft_backfree(data->values, data->height - 1);
		ft_exit(MLX_ERR);
	}
}

/*
 ** Init the default view variables.
 */

void	ft_init_view(t_data *data)
{
	data->default_scale
		= ft_min (WIDTH / data->width / 2, HEIGHT / data->height / 2);
	if (data->default_scale < 15)
		data->default_scale += data->default_scale / 2 ;
	if (data->default_scale < 1)
		data->default_scale = 1;
	data->default_level = 200;
	data->default_x_offset = WIDTH / 2;
	data->default_y_offset = HEIGHT / 2;
	data->default_alpha = 0;
	data->default_beta = 0;
	data->default_gamma = 0;
	data->scale = data->default_scale;
	data->level = data->default_level;
	data->x_offset = data->default_x_offset;
	data->y_offset = data->default_y_offset;
	data->alpha = data->default_alpha;
	data->beta = data->default_beta;
	data->gamma = data->default_gamma;
}

/*
 ** Init the default motion variables.
 */

void	ft_init_motion(t_data *data)
{
	data->clock = 0;
	data->clocksign = 1;
	data->coswave = 0;
	data->wave_level = data->level;
	data->wave_speed = 3;
}

/*
 ** Init the switches.
 */

void	ft_init_hooks(t_data *data)
{
	data->mode = 0;
	data->view = 1;
	data->step = data->scale;
	data->hud = 0;
	data->offset_sign = -1;
	data->rotate_motion = 0;
	data->rotate_speed = 1;
	data->level_motion = 0;
}
