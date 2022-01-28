/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   projection.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clem9nt <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/28 18:33:42 by clem9nt           #+#    #+#             */
/*   Updated: 2022/01/28 18:33:43 by clem9nt          888   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

/*
 ** Alpha rotation.
 */

static void	ft_rotate_alpha(int *y, long *z, double alpha)
{
	int	y_cpy;

	y_cpy = *y;
	*y = (int)(y_cpy * cos(alpha) + *z * sin(alpha));
	*z = (long)(-y_cpy * sin(alpha) + *z * cos(alpha));
}

/*
 ** Beta rotation.
 */

static void	ft_rotate_beta(int *x, long *z, double beta)
{
	int	x_cpy;

	x_cpy = *x;
	*x = (int)(x_cpy * cos(beta) + *z * sin(beta));
	*z = (long)(-x_cpy * sin(beta) + *z * cos(beta));
}

/*
 ** Gamma rotation.
 */

static void	ft_rotate_gamma(int *x, int *y, double gamma)
{
	int	x_cpy;
	int	y_cpy;

	x_cpy = *x;
	y_cpy = *y;
	*x = (int)(x_cpy * cos(gamma) - *y * sin(gamma));
	*y = (int)(x_cpy * sin(gamma) + *y * cos(gamma));
}

/*
 ** Isometric projection.
 */

static void	ft_isometric(int *x, int *y, long z)
{
	int	x_cpy;
	int	y_cpy;

	x_cpy = *x;
	y_cpy = *y;
	*x = (int)((x_cpy - y_cpy) * cos(ANG_30));
	*y = (int)((x_cpy + y_cpy) * sin(ANG_30) - z);
}

/*
 ** Projection translation.
 */

void	ft_translate(t_data *data, t_pixel *p)
{
	p->x *= data->scale;
	p->y *= data->scale;
	p->z = p->z * data->scale * data->level / 2000;
	p->x -= (data->width * data->scale) / 2;
	p->y -= (data->height * data->scale) / 2;
	ft_rotate_alpha(&p->y, &p->z, data->alpha);
	ft_rotate_beta(&p->x, &p->z, data->beta);
	ft_rotate_gamma(&p->x, &p->y, data->gamma);
	if (data->view == 1)
		ft_isometric(&p->x, &p->y, p->z);
	p->x = p->x + data->x_offset;
	p->y = p->y + data->y_offset;
}
