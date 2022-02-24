>       ft

#       FDF

ft_keyboard display keys
	ft_putnbr_fd(key, 2);
	ft_putchar_fd('\n', 2);

Compilation MACOS:
    cc main.c -L minilibx_macos libgnl libft -lmlx -framework OpenGL -framework AppKit

Print file.fdf:
	int x;
	int y;

	y = 0;
	while (y < data.height)
	{
		x = 0;
		while (x < data.width)
		{
			printf("%i ", data.values[y][x]);
			x++;
		}
		printf("\n");
		y++;
	}

Draw background:
    static void	background(t_data *data, int color)
    {
        int	x;
        int	y;

        x = 0;
        while (x < HEIGHT)
        {
            y = 0;
            while (y < WIDTH)
                img_pixel_put(data, y++, x, color);
            ++x;
        }
    }

Set the map depth min/max:
    void	ft_set_map_values(t_data *data)
    {
        int	i;
        int	j;

        j = 0;
        while (j < data->height)
        {
            while (i < data->width)
            {
                if (data->bot > data->values[j][i])
                    data->bot = data->values[j][i];
                if (data->top < data->values[j][i])
                    data->top = data->values[j][i];
                i++;
            }
            i = 0;
            j++;
        }
    }

'ft_level_motion' 360 instead 180:
	int	prev;
	data->sinwave = ft_sinwave(data->clock, data->speed, data->amp);
	prev = ft_sinwave(data->clock - 1, data->speed, data->amp);
	if (data->sinwave < prev)
		data->clocksign = -data->clocksign;
	else
		data->clocksign = +data->clocksign;
	data->clock += data->clocksign;
