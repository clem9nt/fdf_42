/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   security.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clem9nt <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/28 18:33:54 by clem9nt           #+#    #+#             */
/*   Updated: 2022/02/11 19:06:42 by clem             888   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/*
 ** Exit with an stderr message.
 */

void	ft_exit(char *error)
{
	ft_putstr_fd(error, 2);
	ft_putstr_fd("\n", 2);
	exit(EXIT_FAILURE);
}

/*
 ** Freem
 */

void	ft_free(void *ptr)
{
	if (ptr)
	{
		free(ptr);
		ptr = NULL;
	}
}

/*
 ** Reverse free a 2D array.
 */

void	ft_backfree(int **tab, int index)
{
	while (index + 1)
	{
		free(tab[index]);
		tab[index] = NULL;
		index--;
	}
	free (tab);
	tab = NULL;
}

/*
 ** Make sure the 3 file descriptors are closed.
 */

void	ft_close_fd(t_data *data)
{
	close(data->fd[0]);
	close(data->fd[1]);
	close(data->fd[2]);
}

/*
 ** Check if that the input file is correct.
 */

void	ft_check_input(char *file)
{
	const char	*sufix = "x.fdf";

	if (ft_strlen(file) < 5)
		ft_exit(FILENAME_ERR);
	while (*(file + 1))
		file++;
	while (*(sufix + 1))
		sufix++;
	while (*(sufix + 1) != '.')
	{
		if (*file != *sufix)
			ft_exit(FILENAME_ERR);
		file--;
		sufix--;
	}
	if ((*file) == '/')
		ft_exit(FILENAME_ERR);
}
