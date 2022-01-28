#include "../includes/fdf.h"

/*
 ** Locate the pixel and set its value.
 **
 ** 1. Translate 2D array point coordinates into 1D array pixel index.
 ** 2. Locate the pixel by incrementing the pixel array address by the index.
 ** 3. Set the pixel (color) value.
 */

static void	ft_put_pixel(t_data *data, int x, int y, int color)
{
	char	*pixel;

	pixel = data->address + (y * data->linelen + x * (data->bpp / 8));
	if (x >= 0 && x < WIDTH && y >= 0 && y < HEIGHT)
		*(int *) pixel = color;
}

/*
 ** Compute a line using Bresenham algorithm.
 */

static void	ft_init_bresenham(t_bresenham *b, t_pixel *beg, t_pixel *end)
{
	b->xdelta = ft_abs(end->x - beg->x);
	b->ydelta = ft_abs(end->y - beg->y) * -1;
	b->xsign = (beg->x < end->x) * 1 + (beg->x > end->x) * -1;
	b->ysign = (beg->y < end->y) * 1 + (beg->y > end->y) * -1;
	b->err = b->xdelta + b->ydelta;
}

static void	ft_set_line(t_data *data, t_pixel *beg, t_pixel *end)
{
	t_bresenham	b;

	ft_init_bresenham(&b, beg, end);
	while (1)
	{
		ft_put_pixel(data, beg->x, beg->y, beg->color);
		if (beg->x == end->x && beg->y == end->y)
			break ;
		b.errcpy = 2 * b.err;
		if (b.errcpy > b.ydelta)
		{
			b.err += b.ydelta;
			beg->x += b.xsign;
		}
		if (b.errcpy < b.xdelta)
		{
			b.err += b.xdelta;
			beg->y += b.ysign;
		}
	}
}

/*
 ** Set the pixel location and color.
 */

static t_pixel	ft_set_pixel(t_data *data, int x, int y)
{
	t_pixel	p;

	p.x = x;
	p.y = y;
	p.z = data->values[y][x];
	ft_translate(data, &p);
	ft_color(data, &p);
	return (p);
}

/*
 ** Browse and render each map points.
 */

void	ft_render(t_data *data)
{
	int		x;
	int		y;
	t_pixel	beg;
	t_pixel	end;

	y = -1;
	while (++y < data->height)
	{
		x = -1;
		while (++x < data->width)
		{
			if (x < data->width - 1)
			{
				beg = ft_set_pixel(data, x, y);
				end = ft_set_pixel(data, x + 1, y);
				ft_set_line(data, &beg, &end);
			}
			if (y < data->height - 1)
			{
				beg = ft_set_pixel(data, x, y);
				end = ft_set_pixel(data, x, y + 1);
				ft_set_line(data, &beg, &end);
			}
		}
	}
}
