#include "../includes/fdf.h"

/*
 ** Display hook, triggered by screen refreshing.
 **
 ** Buffer an image as an array and display it in the window.
 */

int	ft_display(t_data *data)
{
	if (data->win_ptr)
	{
		data->mlx_img = mlx_new_image(data->mlx_ptr, WIDTH, HEIGHT);
		data->address = mlx_get_data_addr(
				data->mlx_img,
				&data->bpp,
				&data->linelen,
				&data->endian
				);
		ft_render(data);
		if (data->level_motion)
			ft_motion(data, &data->level);
		if (data->rotate_motion)
			data->gamma += 0.005 * data->rotate_speed;
		mlx_put_image_to_window
			(data->mlx_ptr, data->win_ptr, data->mlx_img, 0, 0);
		ft_hud_help(data);
		ft_hud_info(data);
		return (0);
	}
	return (1);
}

/*
 ** Keyboard hook, triggered by keypress.
 **
 **						key     		key-code
 ** General:
 ** - Quit				q/Esc
 ** - Reset all 	    r
 ** - Undo mode			u
 ** - Cycle views		v
 ** - Toggle motion		m
 ** - Step level		1 to 4
 **
 ** Modes:
 ** - Offset			a	(hjkl)
 ** - Scale	 			s	(jk)
 ** - Rotate 			d	(pnjkhl)
 ** - Level				f	(jk)
 */

int	ft_keyboard(int key, t_data *data)
{
	if (key == 53 || key == 12)
		ft_quit(data);
	else if (key == 15)
		ft_reset_all(data);
	else if (key == 9)
		ft_cycle_views(data);
	else if (key == 44)
		data->hud = 1 * data->hud == 0;
	else if ((key >= 18 && key <= 21) || key == 24 || key == 27)
		ft_step(key, data);
	else if (key == 0 || key == 1 || key == 2 || key == 3)
		data->mode = key;
	if (data->mode == 0)
		ft_offset(key, data);
	else if (data->mode == 1)
		ft_scale(key, data);
	else if (data->mode == 2)
		ft_rotate(key, data);
	else if (data->mode == 3)
		ft_level(key, data);
	return (0);
}
