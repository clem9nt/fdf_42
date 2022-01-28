/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clem9nt <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/28 18:33:46 by clem9nt           #+#    #+#             */
/*   Updated: 2022/01/28 18:33:46 by clem9nt          888   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

/*
 ** Open 3 file descriptors for 3 map reading.
 */

void	ft_open(t_data *data)
{
	int	i;

	i = 0;
	while (i < 3)
	{
		data->fd[i] = open(data->file, O_RDONLY);
		if (data->fd[i] < 0)
		{
			ft_close_fd(data);
			ft_exit(NO_FILE);
		}
		i++;
	}
}

/*
 ** Get the width of the map.
 */

void	ft_width(t_data *data)
{
	char	*line;
	char	**cells;

	line = get_next_line(data->fd[0]);
	if (!line)
	{
		ft_close_fd(data);
		ft_exit(READ_ERR);
	}
	cells = ft_split(line, ' ');
	ft_free(line);
	while (cells[data->width] && *cells[data->width] != '\n')
	{
		ft_free(cells[data->width]);
		data->width++;
	}
	ft_free(cells[data->width]);
	ft_free(cells);
	if (close(data->fd[0]) < 0)
	{
		ft_close_fd(data);
		ft_exit(CLOSE_ERR);
	}
}

/*
 ** Get the height of the map.
 */

void	ft_height(t_data *data)
{
	char	*line;

	line = get_next_line(data->fd[1]);
	if (!line)
	{
		ft_close_fd(data);
		ft_exit(READ_ERR);
	}
	while (line)
	{
		ft_free(line);
		line = get_next_line(data->fd[1]);
		data->height++;
	}
	ft_free(line);
	if (close(data->fd[1]) < 0)
	{
		ft_close_fd(data);
		ft_exit(CLOSE_ERR);
	}
}

/*
 ** Write the informations in the program memory.
 */

static void	ft_fill(t_data *data, int i, char *line)
{
	char	**tab;
	int		j;

	if (!line)
	{
		ft_close_fd(data);
		ft_backfree(data->values, i);
		ft_exit(READ_ERR);
	}
	tab = ft_split(line, ' ');
	j = 0;
	while (tab[j] && *tab[j] != '\n')
	{
		data->values[i][j] = ft_atoi(tab[j]);
		ft_free(tab[j]);
		j++;
	}
	ft_free(tab[j]);
	ft_free(tab);
}

/*
 ** Get each map coordinate value.
 */

void	ft_values(t_data *data)
{
	int		i;
	char	*line;

	i = 0;
	while (i < data->height)
	{
		data->values[i] = malloc (sizeof(int) * (size_t)data->width);
		if (!data->values[i])
		{
			ft_close_fd(data);
			ft_backfree(data->values, i);
			ft_exit(MALLOC_ERR);
		}
		line = get_next_line(data->fd[2]);
		ft_fill(data, i, line);
		ft_free(line);
		i++;
	}
	if (close(data->fd[2]) < 0)
	{
		ft_close_fd(data);
		ft_exit(CLOSE_ERR);
	}
}
