#include "../includes/fdf.h"

/*
 ** Triggers the loop.
 */

static void	ft_start_loop(t_data *data)
{
	mlx_loop_hook(data->mlx_ptr, ft_display, data);
	mlx_hook(data->win_ptr, 2, 0, ft_keyboard, data);
	mlx_loop(data->mlx_ptr);
}

/*
 ** Startup
 */

int	main(int argc, char **argv)
{
	t_data	data;

	if (argc == 2)
	{
		ft_check_input(argv[1]);
		data.file = argv[1];
		ft_init_map(&data);
		ft_init_mlx(&data);
		ft_init_view(&data);
		ft_init_motion(&data);
		ft_init_hooks(&data);
		ft_start_loop(&data);
	}
	else
		ft_exit(WRONG_ARG);
	return (0);
}
