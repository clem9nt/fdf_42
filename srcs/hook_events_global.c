#include "../includes/fdf.h"

/*
 ** Quit the program with 'Esc' or 'q'.
 */

void	ft_quit(t_data *data)
{
	ft_backfree(data->values, data->height - 1);
	if (data->win_ptr)
	{
		mlx_destroy_window(data->mlx_ptr, data->win_ptr);
		data->win_ptr = NULL;
	}
	exit (EXIT_SUCCESS);
}

/*
 ** Reset the view like it was at start.
 */

void	ft_reset_all(t_data *data)
{
	data->x_offset = data->default_x_offset;
	data->y_offset = data->default_y_offset;
	data->alpha = data->default_alpha;
	data->beta = data->default_beta;
	data->gamma = data->default_gamma;
	data->scale = data->default_scale;
	data->level = data->default_level;
	data->wave_level = data->level;
	data->rotate_motion = 0;
	data->level_motion = 0;
	data->rotate_speed = 1;
	data->step = data->scale;
	ft_hud_help(data);
	ft_hud_info(data);
}

/*
 ** Cycle the different view mode.
 */

void	ft_cycle_views(t_data *data)
{
	ft_reset_all(data);
	data->view = 1 * (data->view == 0);
}

/*
 ** Help information HUD.
 */

void	ft_hud_help(t_data *data)
{
	if (!data->hud)
		mlx_string_put(data->mlx_ptr, data->win_ptr, 20, HEIGHT - 40,
			0xFFFFFF, "Help   [?]");
	else
	{
		mlx_string_put(data->mlx_ptr, data->win_ptr, 20, HEIGHT - 170,
			0xFFFFFF, "General               Modes");
		mlx_string_put(data->mlx_ptr, data->win_ptr, 20, HEIGHT - 140,
			0xFFFFFF, "  Quit          [q esc] Offset [a]");
		mlx_string_put(data->mlx_ptr, data->win_ptr, 20, HEIGHT - 120,
			0xFFFFFF, "  Reset all     [r]     Scale  [s]");
		mlx_string_put(data->mlx_ptr, data->win_ptr, 20, HEIGHT - 100,
			0xFFFFFF, "  Undo mode     [u]     Rotate [d]");
		mlx_string_put(data->mlx_ptr, data->win_ptr, 20, HEIGHT - 80,
			0xFFFFFF, "  Cycle views   [v]     Level  [f]");
		mlx_string_put(data->mlx_ptr, data->win_ptr, 20, HEIGHT - 60,
			0xFFFFFF, "  Toggle motion [m]");
		mlx_string_put(data->mlx_ptr, data->win_ptr, 20, HEIGHT - 40,
			0xFFFFFF, "  Step level    [1 2 3 4]");
	}
}

/*
 ** Interactions indicator HUD.
 */

void	ft_hud_info(t_data *data)
{
	if (data->mode == 0)
		mlx_string_put(data->mlx_ptr, data->win_ptr, 20, 15,
			0xFFFFFF, "Offset   [hjkl i]");
	if (data->offset_sign > 0 && data->mode == 0)
		mlx_string_put(data->mlx_ptr, data->win_ptr, WIDTH - 195, 15,
			0xFFFFFF, "         inverted");
	if (data->mode == 1)
		mlx_string_put(data->mlx_ptr, data->win_ptr, 20, 15,
			0xFFFFFF, "Scale    [jk]");
	if (data->mode == 2)
	{
		mlx_string_put(data->mlx_ptr, data->win_ptr, 20, 15,
			0xFFFFFF, "Rotate");
		mlx_string_put(data->mlx_ptr, data->win_ptr, 20, 45,
			0xFFFFFF, "  Alpha  [np]");
		mlx_string_put(data->mlx_ptr, data->win_ptr, 20, 65,
			0xFFFFFF, "  Beta   [jk]");
		mlx_string_put(data->mlx_ptr, data->win_ptr, 20, 85,
			0xFFFFFF, "  Gamma  [hl]");
		mlx_string_put(data->mlx_ptr, data->win_ptr, 20, 105,
			0xFFFFFF, "  Motion [m-+]");
	}
	if (data->mode == 3)
		mlx_string_put(data->mlx_ptr, data->win_ptr, 20, 15,
			0xFFFFFF, "Level    [jk m]");
}
