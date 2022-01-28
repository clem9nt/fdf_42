#include "../includes/fdf.h"

/*
 ** Move the map.
 */

void	ft_offset(int key, t_data *data)
{
	if (key == 4)
		data->x_offset += data->step * data->offset_sign;
	else if (key == 38)
		data->y_offset -= data->step * data->offset_sign;
	else if (key == 40)
		data->y_offset += data->step * data->offset_sign;
	else if (key == 37)
		data->x_offset -= data->step * data->offset_sign;
	else if (key == 32)
	{
		data->x_offset = data->default_x_offset;
		data->y_offset = data->default_y_offset;
	}
	else if (key == 34)
		data->offset_sign *= -1;
}

/*
 ** Zoom on the map.
 */

void	ft_scale(int key, t_data *data)
{
	if (key == 40 && data->scale < data->default_scale
		* (data->width + data->height) / 2)
		data->scale += data->step;
	else if (key == 38)
	{
		data->scale -= data->step;
		if (data->scale < data->default_scale / 2)
			data->scale = data->default_scale / 2;
		if (data->scale < 1)
			data->scale = 1;
	}
	else if (key == 32)
		data->scale = data->default_scale;
}

/*
 ** Rotate the map.
 */

void	ft_rotate(int key, t_data *data)
{
	if (key == 46)
		data->rotate_motion = 1 * (data->rotate_motion == 0);
	else if (key == 45)
		data->alpha += data->step * 0.01;
	else if (key == 35)
		data->alpha -= data->step * 0.01;
	else if (key == 38)
		data->beta += data->step * 0.01;
	else if (key == 40)
		data->beta -= data->step * 0.01;
	else if (key == 4)
		data->gamma += data->step * 0.01;
	else if (key == 37)
		data->gamma -= data->step * 0.01;
	else if (key == 32)
	{
		data->alpha = data->default_alpha;
		data->beta = data->default_beta;
		data->gamma = data->default_gamma;
	}
}

/*
 ** Increase maps reliefs.
 */

void	ft_level(int key, t_data *data)
{
	if (key == 46)
		data->level_motion = 1 * data->level_motion == 0;
	else if (key == 40)
	{
		data->level += 5 * data->step * (!data->level_motion);
		data->wave_level += 5 * data->step;
	}
	else if (key == 38)
	{
		data->level -= 5 * data->step * (!data->level_motion);
		data->wave_level -= 5 * data->step;
		data->wave_level = data->wave_level * (data->wave_level > 0);
	}
	else if (key == 32)
	{
		data->level = data->default_level;
		data->wave_level = data->level;
	}
}

/*
 ** User interaction intensity.
 */

void	ft_step(int key, t_data *data)
{
	int	step;

	if (key >= 18 && key <= 21)
	{
		if (data->mode == 1)
			step = data->default_scale;
		else
			step = data->scale;
		data->step = 1 * (key == 18)
			+ step * (key == 19)
			+ step * 2 * (key == 20)
			+ step * 10 * (key == 21);
	}
	if (key == 24 || key == 27)
	{
		data->rotate_speed = ft_abs(data->rotate_speed
				+ 2 * (key == 24) - 2 * (key == 27));
		data->rotate_speed = data->rotate_speed * (data->rotate_speed < 1000)
			+ (data->rotate_speed - 2) * (data->rotate_speed >= 1000);
	}
}
