#include "../includes/fdf.h"

/*
 ** Set the cos wave attributes.
 */

int	ft_coswave(int clock, int speed, int level)
{
	return ((int)(cos((double)clock / FRAMERATE * speed) * level));
}

/*
 ** Animate the projection using a cosine wave.
 */

void	ft_motion(t_data *data, int *target)
{
	data->coswave = ft_coswave(data->clock, data->wave_speed, data->wave_level);
	*target = data->coswave;
	if (data->coswave < 1)
		data->clocksign = -data->clocksign;
	data->clock += -1 * (data->clocksign > 0) + 1 * (data->clocksign < 0);
}
